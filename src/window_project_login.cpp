﻿#include "window_project_login.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

void Login_window::start()
{
    qDebug() << "I'm working in thread:" << QThread::currentThreadId();

    if(!db.open())                                      //打开数据库
    {
        QMessageBox::information(this, tr("连接结果"), tr("数据库连接失败"));
    }
    else
    {
        QSqlQuery query(db); //查询Card表并输出，测试能否正常操作数据库
        QString sqlVerify = QString("SELECT * FROM users WHERE userid='%1' AND usercode = '%2'").arg(userPar::userid, userPar::usercode);

        query.exec(sqlVerify);
        if (query.next()){

            //            验证通过
            userPar::userLimit = query.value(3).toString();
            userPar::username = query.value(2).toString();
            QString ipv4 = utils::getIPV4address();
            QDateTime curDateTime = QDateTime::currentDateTime();
            QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
            QString sqlMax = "SELECT MAX(recid) FROM records";
            query.exec(sqlMax);
            query.next();

            int recid = query.value(0).toInt() + 1;
            QString sqlInsertRecord = QString ("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '登录成功')").arg(recid).
                    arg(userPar::userid).arg(ipv4).arg(date);
            query.exec(sqlInsertRecord);

            QString sqlVersion = "SELECT * FROM version";
            query.exec(sqlVersion);
            if (query.next())
            {
                userPar::version = query.value(0).toString();
            }
            QMessageBox::information(this, tr("连接结果"), tr("数据库连接成功"));
            emit setLimitSIGNAL(userPar::userLimit);
            accept();
            this->close();
        }
        else{
            QMessageBox::information(this, tr("连接结果"), tr("用户名或密码错误"));
        }
    }
    db.close();
}


void Login_window::clearSLOT()
{
    this->usrnameLineedit->clear();
    this->pwordLineedit->clear();
    this->ipLineedit->clear();
}


void Login_window::okSLOT()
{
//    给静态全局变量赋值
    userPar::setGloabalvar(usrnameLineedit->text(), pwordLineedit->text(), ipLineedit->text());

    if (utils::ping(userPar::userip)==0)
    {
        if (QSqlDatabase::contains("SQLserver"))
            this->db = QSqlDatabase::database("SQLserver");
        else{
            this->db = QSqlDatabase::addDatabase("QODBC", "SQLserver");   //数据库驱动类型为SQL Server
            QString dsn = "DRIVER={SQL SERVER};SERVER=" + userPar::userip + ";DATABASE=p;"
                    "UID=sa;PWD=123456;";
            db.setDatabaseName(dsn);
        }
        this->start();
     }
    else
        QMessageBox::information(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
}

void Login_window::exitSLOT()
{
    QDialog::reject();
}


void Login_window::testNetSLOT()
{
    QString ip = this->ipLineedit->text();
    int exitCode = utils::ping(ip);
    if(!exitCode)                                      //打开数据库
        QMessageBox::information(this, tr("测试结果"), tr("网络测试成功"));
    else
        QMessageBox::information(this, tr("测试结果"), tr("网络测试失败"));
}


Login_window::Login_window(QWidget *parent) : QDialog(parent)
{
    qDebug() << "Main thread ID = " << QThread::currentThreadId();
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    this->layout = new QGridLayout(this);

    this->usrnameLabel = new QLabel(tr("用户名"), this);
    this->passwordLabel = new QLabel(tr("密码 "), this);
    this->ipAddressLabel = new QLabel(tr("IP地址"), this);

    this->usrnameLineedit = new QLineEdit(this);
    this->pwordLineedit = new QLineEdit(this);
    this->pwordLineedit->setEchoMode(QLineEdit::Password);
    this->ipLineedit = new QLineEdit(this);

    this->testNetButton = new QPushButton(tr("网络测试"), this);
    this->okButton = new QPushButton(tr("确定"), this);
    this->clearButton = new QPushButton(tr("清除"), this);
    this->exitButton = new QPushButton(tr("退出"), this);
    this->layout->addWidget(this->usrnameLabel, 0, 0, 1, 3);
    this->layout->addWidget(this->usrnameLineedit, 0, 3, 1, 3);
    this->layout->addWidget(this->passwordLabel, 0, 6, 1, 3);
    this->layout->addWidget(this->pwordLineedit, 0, 9, 1, 3);
    this->layout->addWidget(this->ipAddressLabel, 1, 0, 1, 3);
    this->layout->addWidget(this->ipLineedit, 1, 3, 1, 6);
    this->layout->addWidget(this->testNetButton, 1, 9, 1, 3);

    buttonWidget = new QWidget(this);
    layout1 = new QGridLayout(buttonWidget);
    this->layout1->addWidget(this->okButton, 0, 0, 1, 4);
    this->layout1->addWidget(this->clearButton, 0, 4, 1, 4);
    this->layout1->addWidget(this->exitButton, 0, 8, 1, 4);
    this->layout->addWidget(this->buttonWidget, 2, 0, 1, 12);

    this->setWindowTitle("登录窗口");

    connect(clearButton, SIGNAL(clicked()), this, SLOT(clearSLOT()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(exitSLOT()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(okSLOT()));
    connect(testNetButton, SIGNAL(clicked()), this, SLOT(testNetSLOT()));

    this->ipLineedit->setText("10.168.1.147");
    this->usrnameLineedit->setText("admin");
    this->pwordLineedit->setText("admin");
    this->show();
}
