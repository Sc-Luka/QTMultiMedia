#ifndef USERPAGE_H
#define USERPAGE_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QScrollArea>
#include <QTemporaryFile>
#include <QVBoxLayout>

namespace Ui {
class UserPage;
}

class UserPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserPage(int userId, QWidget *parent = nullptr);
    ~UserPage();

private slots:
    void on_AddItem_clicked();
    void on_Show_clicked();
    void on_BacK_clicked();

private:
    Ui::UserPage *ui;

    int currentUserId;


    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *scrollLayout;
    QList<QWidget*> fileWidgets;
    QTemporaryFile *currentTempFile = nullptr;
};

#endif // USERPAGE_H
