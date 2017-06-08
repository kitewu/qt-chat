#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QtNetwork>
#include <QDialog>
#include <QString>
#include <QtGui>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QDialog
{
    Q_OBJECT
public:
    ChatWindow(QString win_name);
    QString get_win_name();
    void add_msg(QString, QString);
    bool saveFile(const QString &fileName);

private slots:
    void on_send_clicked();

    void on_close_clicked();

signals:
    void send_to_list(QString);
    void close_chat_window(QString);

private:
    Ui::ChatWindow *ui;
    QString win_name;   //窗口名，即用户名
};

#endif // CHATWINDOW_H
