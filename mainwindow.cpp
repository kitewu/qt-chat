#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,400,280);
    IP = "115.159.30.115";
    PORT = 9999;
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(read_msg()));
    connect(socket, SIGNAL(connected()), this, SLOT(send_login_msg()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_msg()
{
    QString msg = socket->readAll();
    deal_msg(msg);
}

void MainWindow::deal_msg(QString msg)
{
    QByteArray c = msg.toAscii();
    switch(c[0])
    {
    case '0'://login failed
        QMessageBox::information(this,"warnning","login failed");
        break;
    case '1'://login success
        listwindow = new UserListWindow();
        listwindow->show();
        this->listwindow->setAccount(ui->account->toPlainText());
        this->listwindow->setName(ui->uname->toPlainText());
        this->listwindow->set_window();
        this->hide();
        connect(listwindow, SIGNAL(send_to_mainwindow(QString)), this, SLOT(read_msg_from_listwindow(QString)));
        break;
    case '2'://群聊 2;msg
        this->listwindow->recv_msg(msg);
        break;
    case '3'://私聊 3;from;msg
        this->listwindow->recv_msg(msg);
        break;
    case '4'://上线 4;account;uname
        this->listwindow->deal_addnew(msg);
        break;
    case '5'://下线 5;account
        this->listwindow->deal_logout(msg);
        break;
    default:
        break;
    }
}

void MainWindow::send_login_msg()
{
    QString account = ui->account->toPlainText();
    QString password = ui->password->toPlainText();
    QString uname = ui->uname->toPlainText();
    QString logininfo("1;"+account+";"+password+";"+uname);
    socket->write(logininfo.toAscii());
    socket->flush();
}

void MainWindow::on_login_clicked()
{
    socket->connectToHost(QHostAddress(IP), PORT);
}

void MainWindow::on_exit_clicked()
{
    exit(0);
}

void MainWindow::read_msg_from_listwindow(QString msg)
{
    socket->write(msg.toAscii());
    socket->flush();
    qDebug() << msg << endl;
}
