#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QHostAddress>
#include <QByteArray>
#include <QLineEdit>
#include <QMessageBox>
#include <QChar>
#include "userlistwindow.h"
#include "chatwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void deal_msg(QString msg);

private slots:
    void send_login_msg();
    void read_msg();
    void on_login_clicked();
    void on_exit_clicked();

    void read_msg_from_listwindow(QString msg);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QString IP;
    int PORT;
    UserListWindow *listwindow;
};

#endif // MAINWINDOW_H
