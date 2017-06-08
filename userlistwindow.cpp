#include "userlistwindow.h"
#include "ui_userlistwindow.h"

UserListWindow::UserListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserListWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,305,562);

    //设置点击列表中项时打开聊天窗口
    ui->userlist->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->userlist->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->userlist->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->userlist,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(new_chat_wind(int,int)));

    addItem("000000", "群聊");

    chat_wins = new QMap<QString, ChatWindow*>();
}

UserListWindow::~UserListWindow()
{
    delete ui;
}

void UserListWindow::setAccount(QString account)
{
    this->account = account;
}

void UserListWindow::setName(QString uname)
{
    this->uname = uname;
}

void UserListWindow::set_window()
{
    ui->account->setText(this->account);
    ui->uname->setText(this->uname);
}

//处理新上线
void UserListWindow::deal_addnew(QString msg)
{
    QStringList sections = msg.split(";");
    for(int i=1; i<sections.count(); i+=2)
        addItem(sections.at(i), sections.at(i+1));
}
void UserListWindow::addItem(QString account, QString uname)
{
    QTableWidgetItem *acc = new QTableWidgetItem(account);
    QTableWidgetItem *name = new QTableWidgetItem(uname);
    QTableWidgetItem *msg = new QTableWidgetItem("0");
    ui->userlist->insertRow(0);
    ui->userlist->setItem(0,0,acc);
    ui->userlist->setItem(0,1,name);
    ui->userlist->setItem(0,2,msg);
    update_online_number();
}

/**
 * 处理下线
 *
 * 删除表项
 * 更新人数
 * 从map中关闭并删除窗口
 */
void UserListWindow::deal_logout(QString account)
{
    int rowNum = ui->userlist->findItems(account, Qt::MatchExactly).first()->row();
    ui->userlist->removeRow(rowNum);
    update_online_number();

    QMap<QString,ChatWindow*>::iterator it = chat_wins->find(account);
    if(it != chat_wins->end()){
        ChatWindow* cw = it.value();
        cw->close();
        chat_wins->erase(it);
    }
}

//更新在线人数
void UserListWindow::update_online_number()
{
    ui->onlineuser->setText("在线人数："+ui->userlist->rowCount());
}

//返回在线人数
int UserListWindow::get_online_num()
{
    return ui->userlist->rowCount();
}

//从chat窗口发来的信号，即聊天消息
void UserListWindow::read_msg_from_chat(QString msg)
{
    emit send_to_mainwindow(msg);
}

//新建聊天框
void UserListWindow::new_chat_wind(int row, int col)
{
    QTableWidgetItem* s_row = ui->userlist->item(row, 0);
    QString id = s_row->text();
    if(!chat_wins->contains(id))//没有打开的窗口
    {
        ChatWindow* cw = new ChatWindow(id);
        chat_wins->insert(id, cw);
        connect(cw, SIGNAL(send_to_list(QString)), this ,SLOT(read_msg_from_chat(QString)));
        connect(cw, SIGNAL(close_chat_window(QString)), this ,SLOT(close_chat_window(QString)));
        cw->show();
    }
}

void UserListWindow::close_chat_window(QString win_name)
{
    QMap<QString,ChatWindow*>::iterator it = chat_wins->find(win_name);
    ChatWindow* cw = it.value();
    cw->close();
    chat_wins->erase(it);
}

void UserListWindow::recv_msg(QString msg)
{
    QByteArray c = msg.toAscii();
    QStringList sections = msg.split(";");
    QString win_name = "000000";
    QString from = sections.at(1);
    QString con = sections.at(2);
    if(c[0] == '3'){
        win_name = from;
    }
    QMap<QString,ChatWindow*>::iterator it = chat_wins->find(win_name);
    if(it == chat_wins->end())//未打开窗口
    {

    }
    else
    {
        ChatWindow* cw = it.value();
        cw->add_msg(from, con);
    }
}
