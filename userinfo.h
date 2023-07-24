#ifndef USERINFO_H
#define USERINFO_H

#include <windowsSolve.h>
#include <QTcpSocket>
#include <QTcpServer>
#include <ui_userinfo.h>

class userInfo : public windowsSolve
{
    Q_OBJECT

public:
    explicit userInfo(QWidget *parent = nullptr);
    ~userInfo();

private slots:
    void on_minBtn_clicked();
    void on_closeBtn_clicked();
    void on_backBtn_clicked();

    void on_chatBtn_clicked();

    void on_pushButton_4_clicked();

    void on_sendBtn_clicked();

private:
    QTcpSocket* m_socket;
    QTcpServer* m_server;
    Ui::userInfo *ui;
};

#endif // USERINFO_H
