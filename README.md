# QtMultimedia

A C++ desktop application built with **Qt Framework** that integrates **MySQL user management** and **Qt Multimedia features** to handle media files.

## 👥 User Roles

### 👑 Admin
- Add users  
- Delete users  
- Reset user passwords  

### 👤 Normal User
- Upload image, video, or audio files  
- Play/view uploaded media  
- Delete their own media files  

## 🎵 Features

- Play videos and audio using **Qt Multimedia**
- View images in the application
- Authenticate users with MySQL backend
- Different permissions for Admin and Normal users
- Simple and intuitive Qt GUI

## 🛠️ Technologies Used

- **C++**
- **Qt Framework (Widgets, Multimedia, SQL)**
- **MySQL Database**

## 🚀 How to Build and Run

1. **Install Qt and Qt Creator**  
   Ensure `Qt Multimedia` and `Qt SQL` modules are included.

2. **Set up MySQL database**  
   - Create a database  
   - Create a `users` table with roles and credentials  
   - Update database connection info in the source

3. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/QtMultimedia.git
