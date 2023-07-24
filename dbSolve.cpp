#include "dbSolve.h"
#include <QMessageBox>
#include <QSqlQuery>
#include<qsqlerror.h>
#include<qdebug.h>
#include <QString>
#include <QDebug>
dbSolve::dbSolve()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("123.249.29.21");
    db.setUserName("root");
    db.setPassword("Zzz111...");
    db.setDatabaseName("xiuxian");
    db.open();
    if (!db.isOpen())//�����ݿ�,�������false��ʾ��ʧ��
    {
        //QMessageBox::critical(0, QString("Critical��Ϣ��"), QString("����һ��Critical��Ϣ��"));
        qDebug()<<"database not opened";
        qDebug()<<db.lastError().text();
        return;
    }else
        qDebug()<<"database opened";
    res = QSqlQuery(db);
}

dbSolve::~dbSolve()
{
    db.close();
}

QString dbSolve::getPasswd(QString s)
{
    res.clear();
    res.exec(QString("select * from users where user_id='%1'").arg(s));
    if(res.next()){
        return res.value("user_passwd").toString();
    }
    return "";
}
bool dbSolve::addAccount(QString id,QString passwd)
{
    res.clear();
    bool result = res.exec(QString("insert into users(user_id,user_passwd) values ( '%1','%2')")
        .arg(id).arg(passwd));
    return result ? true : false;
}
bool dbSolve::setPasswd(QString id,QString passwd)
{
    res.clear();
    bool result = res.exec(QString("update users set user_passwd='%1' where user_id='%2'")
        .arg(passwd).arg(id));
    return result ? true : false;
}
