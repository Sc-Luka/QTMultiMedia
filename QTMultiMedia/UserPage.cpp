#include "UserPage.h"
#include "ui_UserPage.h"
#include "MainWindow.h"

#include <QSqlError>
#include <QFileDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateTime>
#include <QLabel>
#include <QPushButton>
#include <QTemporaryFile>
#include <QScreen>

UserPage::UserPage(int userId, QWidget *parent)
    : QWidget(parent), ui(new Ui::UserPage), currentUserId(userId),
    mediaPlayer(new QMediaPlayer(this)),
    videoWidget(new QVideoWidget(this)),
    scrollArea(new QScrollArea(this)),
    scrollContent(new QWidget()),
    scrollLayout(new QVBoxLayout(scrollContent)),
    currentTempFile(nullptr)
{
    ui->setupUi(this);

    // video zomebi
    videoWidget->setFixedSize(600, 400);
    videoWidget->setAspectRatioMode(Qt::KeepAspectRatio);
    videoWidget->setStyleSheet("background: black;");
    mediaPlayer->setVideoOutput(videoWidget);
    videoWidget->setVisible(false);

    // Scroll
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);

    // Main
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(ui->AddItem);
    mainLayout->addWidget(ui->Show);
    mainLayout->addWidget(videoWidget);
    mainLayout->addWidget(scrollArea);
}

UserPage::~UserPage()
{
    mediaPlayer->stop();
    if (currentTempFile) {
        currentTempFile->deleteLater();
    }
    delete ui;
    qDeleteAll(fileWidgets);
}

void UserPage::on_AddItem_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select File");
    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Cannot open file!");
        return;
    }

    QByteArray fileContent = file.readAll();
    file.close();

    QFileInfo fileInfo(filePath);
    QString filename = fileInfo.fileName();
    QString filetype = fileInfo.suffix().toLower();

    QSqlQuery query;
    query.prepare("INSERT INTO files (user_id, filename, filetype, content, upload_date) "
                  "VALUES (:user_id, :filename, :filetype, :content, :date)");
    query.bindValue(":user_id", currentUserId);
    query.bindValue(":filename", filename);
    query.bindValue(":filetype", filetype);
    query.bindValue(":content", fileContent);
    query.bindValue(":date", QDateTime::currentDateTime());

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void UserPage::on_Show_clicked()
{
    mediaPlayer->stop();
    videoWidget->setVisible(false);

    if (currentTempFile) {
        currentTempFile->deleteLater();
        currentTempFile = nullptr;
    }

    qDeleteAll(fileWidgets);
    fileWidgets.clear();

    QLayoutItem* item;
    while ((item = scrollLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    QSqlQuery query;
    query.prepare("SELECT id, filename, filetype, content, upload_date FROM files WHERE user_id = :user_id");
    query.bindValue(":user_id", currentUserId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to load files: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        int fileId = query.value("id").toInt();
        QString filename = query.value("filename").toString();
        QString filetype = query.value("filetype").toString().toLower();
        QByteArray content = query.value("content").toByteArray();
        QDateTime uploadDate = query.value("upload_date").toDateTime();

        QWidget *fileWidget = new QWidget(scrollContent);
        QVBoxLayout *itemLayout = new QVBoxLayout(fileWidget);

        // File informacia
        QLabel *infoLabel = new QLabel(
            QString("%1\nType: %2\nUploaded: %3")
                .arg(filename)
                .arg(filetype.toUpper())
                .arg(uploadDate.toString("yyyy-MM-dd HH:mm")),
            fileWidget);
        itemLayout->addWidget(infoLabel);

        // Image vamowmeb
        if (filetype == "jpg" || filetype == "jpeg" || filetype == "png") {
            QPixmap pixmap;
            if (pixmap.loadFromData(content)) {
                QLabel *imageLabel = new QLabel(fileWidget);
                imageLabel->setPixmap(pixmap.scaled(300, 300, Qt::KeepAspectRatio));
                itemLayout->addWidget(imageLabel);
            }
        }

        bool isMedia = (filetype == "mp4" || filetype == "avi" || filetype == "mkv" ||
                        filetype == "mp3" || filetype == "wav");

        QPushButton *deleteBtn = new QPushButton("Delete", fileWidget);
        QPushButton *playBtn = nullptr;
        QPushButton *stopBtn = nullptr;

        if (isMedia) {
            playBtn = new QPushButton("Play", fileWidget);
            stopBtn = new QPushButton("Stop", fileWidget);

            connect(playBtn, &QPushButton::clicked, [this, content, filetype]() {
                // wina gavachere
                if (mediaPlayer) {
                    mediaPlayer->stop();
                    delete mediaPlayer;
                }
                mediaPlayer = new QMediaPlayer(this);
                mediaPlayer->setVideoOutput(videoWidget);

                QTemporaryFile *tempFile = new QTemporaryFile(this);
                tempFile->setFileTemplate(QDir::tempPath() + "/XXXXXX." + filetype);

                if (tempFile->open()) {
                    tempFile->write(content);
                    tempFile->flush();
                    tempFile->close();

                    if (filetype == "mp4" || filetype == "avi" || filetype == "mkv") {
                        videoWidget->setVisible(true);
                    } else {
                        videoWidget->setVisible(false);
                    }

                    mediaPlayer->setMedia(QUrl::fromLocalFile(tempFile->fileName()));
                    mediaPlayer->play();
                }
            });


            connect(stopBtn, &QPushButton::clicked, [=]() {
                mediaPlayer->stop();
                videoWidget->setVisible(false);
                if (currentTempFile) {
                    currentTempFile->deleteLater();
                    currentTempFile = nullptr;
                }
            });
        }

        connect(deleteBtn, &QPushButton::clicked, [=]() {
            mediaPlayer->stop();
            QSqlQuery delQuery;
            delQuery.prepare("DELETE FROM files WHERE id = :id");
            delQuery.bindValue(":id", fileId);
            if (!delQuery.exec()) {
                QMessageBox::critical(this, "Error", "Delete failed: " + delQuery.lastError().text());
            }
            on_Show_clicked();
        });

        QHBoxLayout *btnLayout = new QHBoxLayout();
        btnLayout->addWidget(deleteBtn);
        if (isMedia) {
            btnLayout->addWidget(playBtn);
            btnLayout->addWidget(stopBtn);
        }
        itemLayout->addLayout(btnLayout);

        scrollLayout->addWidget(fileWidget);
        fileWidgets.append(fileWidget);
    }

    scrollArea->setVisible(true);
    ui->Show->setText("Refresh Files");
}


void UserPage::on_BacK_clicked()
{
    mediaPlayer->stop();
    if (currentTempFile) {
        currentTempFile->deleteLater();
        currentTempFile = nullptr;
    }

    MainWindow *mainwindow = new MainWindow();
    QScreen *screen = QGuiApplication::primaryScreen();

    mainwindow->move(screen->availableGeometry().center() - mainwindow->rect().center());
    mainwindow->show();
    this->hide();
}

