#ifndef USERLISTWINDOW_H
#define USERLISTWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMap>
#include "chatwindow.h"

namespace Ui {
class UserListWindow;
}

class UserListWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit UserListWindow(QWidget *parent = 0);
    ~UserListWindow();
    
    void deal_addnew(QString account);//处理新下线
    void addItem(QString account, QString uname);

    void deal_logout(QString account);//处理新下线

    void update_online_number();
    void setAccount(QString);
    void setName(QString);
    void set_window();
    int get_online_num();
    void recv_msg(QString msgs);

signals:
    void send_to_mainwindow(QString msg);

public slots:
    void read_msg_from_chat(QString msg);
    void new_chat_wind(int, int);
    void close_chat_window(QString);

private:
    Ui::UserListWindow *ui;
    QString account;
    QString uname;
    QMap<QString, ChatWindow*> *chat_wins;
};

#endif // USERLISTWINDOW_H
