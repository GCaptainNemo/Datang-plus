#include "window_project_login.h"

loginThreadObject::loginThreadObject(QString nm, QString pw, QString ip):
    name(nm), password(pw), ip(ip){}

void loginThreadObject::start()
{
    qDebug() << "I'm working in thread:" << QThread::currentThreadId();

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "SQLserver");   //数据库驱动类型为SQL Server
    QString dsn = "DRIVER={SQL SERVER};SERVER=" + otherPar::ip + ";DATABASE=p;"
            "UID=sa;PWD=123456;";
    db.setDatabaseName(dsn);

    if(!db.open())                                      //打开数据库
    {
        emit msgboxShowSIGNAL(1);
    }
    else
    {
        QSqlQuery query(db); //查询Card表并输出，测试能否正常操作数据库
        QString sqlVerify = QString("SELECT * FROM users WHERE userid='%1' AND usercode = '%2'").arg(otherPar::name, otherPar::password);

        query.exec(sqlVerify);
        if (query.next()){
            QString ipv4 = utils::getIPV4address();
            QDateTime curDateTime = QDateTime::currentDateTime();
            QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
            QString sqlMax = "SELECT MAX(recid) FROM records";
            query.exec(sqlMax);
            query.next();

            int recid = query.value(0).toInt() + 1;
            QString sqlInsertRecord = QString ("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '登录成功')").arg(recid).
                    arg(otherPar::name).arg(ipv4).arg(date);
            query.exec(sqlInsertRecord);

            QString sqlVersion = "SELECT * FROM version";
            query.exec(sqlVersion);
            if (query.next())
            {
                QString version = query.value(0).toString();
                otherPar::setVersion(version);
            }
            emit msgboxShowSIGNAL(0);
        }
        else{
            emit msgboxShowSIGNAL(-1);
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

void Login_window::showMsgboxSLOT(int res)
{
    switch (res){
    case 0:{
        QMessageBox::information(this, tr("连接结果"), tr("数据库连接成功"));
        this->loginThread.quit();
        accept();
        this->close();
        break;
    }
    case 1:
        QMessageBox::information(this, tr("连接结果"), tr("数据库连接失败"));
        break;
    case -1:
        QMessageBox::information(this, tr("连接结果"), tr("用户名或密码错误"));
    default:
        break;
    }
}


void Login_window::okSLOT()
{
//    给静态全局变量赋值
    otherPar::setGloabalvar(usrnameLineedit->text(), pwordLineedit->text(), ipLineedit->text());

    if (utils::ping(otherPar::ip)==0)
    {
        this->loginThread.start();
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

    this->hlayout1 = new QHBoxLayout;
    this->hlayout2 = new QHBoxLayout;
    this->hlayout3 = new QHBoxLayout;
    this->layout = new QVBoxLayout(this);

    this->usrnameLabel = new QLabel(tr("用户名"));
    this->passwordLabel = new QLabel(tr("密码 "));
    this->ipAddressLabel = new QLabel(tr("IP地址"));

    this->usrnameLineedit = new QLineEdit;
    this->pwordLineedit = new QLineEdit;
    this->pwordLineedit->setEchoMode(QLineEdit::Password);
    this->ipLineedit = new QLineEdit;

    this->testNetButton = new QPushButton(tr("网络测试"));
    this->okButton = new QPushButton(tr("确定"));
    this->clearButton = new QPushButton(tr("清除"));
    this->exitButton = new QPushButton(tr("退出"));

    this->hlayout1->addWidget(this->usrnameLabel);
    this->hlayout1->addWidget(this->usrnameLineedit);
    this->hlayout1->addWidget(this->passwordLabel);
    this->hlayout1->addWidget(this->pwordLineedit);
    this->hlayout2->addWidget(this->ipAddressLabel);
    this->hlayout2->addWidget(this->ipLineedit);
    this->hlayout2->addWidget(this->testNetButton);
    this->hlayout3->addWidget(this->okButton);
    this->hlayout3->addWidget(this->clearButton);
    this->hlayout3->addWidget(this->exitButton);
    this->layout->addLayout(this->hlayout1);
    this->layout->addLayout(this->hlayout2);
    this->layout->addLayout(this->hlayout3);

    this->setWindowTitle("登录窗口");

    connect(clearButton, SIGNAL(clicked()), this, SLOT(clearSLOT()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(exitSLOT()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(okSLOT()));
    connect(testNetButton, SIGNAL(clicked()), this, SLOT(testNetSLOT()));

    this->ipLineedit->setText("10.168.1.147");
    this->usrnameLineedit->setText("admin");
    this->pwordLineedit->setText("admin");


    this->threadObject = new
            loginThreadObject(otherPar::name, otherPar::password, otherPar::ip);
    this->threadObject->moveToThread(&loginThread);
    connect(&loginThread, SIGNAL(finished()), threadObject, SLOT(deleteLater()));
    connect(&loginThread, SIGNAL(finished()), &loginThread, SLOT(deleteLater()));
    connect(&loginThread, SIGNAL(started()), threadObject, SLOT(start()));
    connect(threadObject, SIGNAL(msgboxShowSIGNAL(int)), this, SLOT(showMsgboxSLOT(int)));
//    connect(this, SIGNAL(startLoginSIGNAL()), threadObject, SLOT(start()));
//    loginThread.start();
    this->show();

}
