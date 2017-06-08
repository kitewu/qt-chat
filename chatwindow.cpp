#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QString win_name) : ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    this->win_name = win_name;
    this->setWindowTitle(QString("chat with : " + win_name));
    ui->textBrowser->setFocusPolicy(Qt::NoFocus);

    ui->textEdit->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocus();
    ui->textEdit->installEventFilter(this);
}

//返回窗口名字
QString ChatWindow::get_win_name()
{
    return this->win_name;
}

//将消息显示到聊天框中
void ChatWindow::add_msg(QString from, QString msg)
{
    ui->textBrowser->setTextColor(Qt::blue);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",12));
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textBrowser->append("[ " +from+" ] "+ time);//与主机名聊天中
    ui->textBrowser->append(msg);
}

//发送消息
void ChatWindow::on_send_clicked()
{
    QString msg = ui->textEdit->toPlainText();
    if(win_name == "000000")
        msg = "2;"+msg;
    else
        msg = "3;" + win_name + ";"+msg;
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    emit send_to_list(msg);
}

//关闭聊天窗口
void ChatWindow::on_close_clicked()
{
    emit close_chat_window(win_name);
}
