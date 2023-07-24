#include "userinfo.h"
#include "ui_userinfo.h"

userInfo::userInfo(QWidget *parent)
    :m_socket(new QTcpSocket(this))
    ,ui(new Ui::userInfo)
{
    this->setParent(parent);
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置frame默认显示聊天界面
    ui->chatFrame->setVisible(true);
    ui->backFrame->setVisible(false);
    ui->userFrame->setVisible(false);

    //连接服务器
    m_socket->connectToHost(QHostAddress("127.0.0.1"), 8911);

    connect(m_socket, &QTcpSocket::connected, this, [=]{
        ui->IsConnected->setText("连接成功");
        //ui->chatList->addItem("与服务器连接成功");
    });
}

userInfo::~userInfo()
{
    delete ui;
}

void userInfo::on_minBtn_clicked()
{
    this->showMinimized();
}


void userInfo::on_closeBtn_clicked()
{
    this->close();
}

void userInfo::on_backBtn_clicked()
{
    ui->backFrame->setVisible(true);
    ui->userFrame->setVisible(false);
    ui->chatFrame->setVisible(false);
}


void userInfo::on_chatBtn_clicked()
{
    ui->chatFrame->setVisible(true);
    ui->userFrame->setVisible(false);
    ui->backFrame->setVisible(false);
}


void userInfo::on_pushButton_4_clicked()
{
    ui->userFrame->setVisible(true);
    ui->chatFrame->setVisible(false);
    ui->backFrame->setVisible(false);
}


void userInfo::on_sendBtn_clicked()
{

}

