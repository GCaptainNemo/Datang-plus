#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_manage_password.h"

int window_manage_password::num = 0;

window_manage_password::window_manage_password(QWidget *parent) : QDialog(parent)
{

    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint ;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    this->setAttribute(Qt::WA_DeleteOnClose);

    window_manage_password::num += 1;
    this->setWindowTitle(tr("修改密码"));


    gridLayout = new QGridLayout(this);
    usridLabel = new QLabel(tr("用户名:"), this);
    usrnameLabel = new QLabel(tr("备注:"), this);
    usrlimitLabel = new QLabel(tr("用户权限:"), this);
    initPasswordLabel = new QLabel(tr("请输入原密码:"), this);
    newPasswordLabel = new QLabel(tr("请输入新密码:"), this);
    okNewPasswordLabel = new QLabel(tr("请确认新密码:"), this);
    usridLineedit = new QLineEdit(this);
    usridLineedit->setText(otherPar::userid);
    usridLineedit->setReadOnly(true);
    usrnameLineedit = new QLineEdit(this);
    usrnameLineedit->setText(otherPar::username);
    usrnameLineedit->setReadOnly(true);
    usrlimitLineedit = new QLineEdit(this);
    usrlimitLineedit->setText(otherPar::userLimit);
    usrlimitLineedit->setReadOnly(true);

    initPasswordLineedit = new QLineEdit(this);
    this->initPasswordLineedit->setEchoMode(QLineEdit::Password);
    newPasswordLineedit = new QLineEdit(this);
    this->newPasswordLineedit->setEchoMode(QLineEdit::Password);
    okNewPasswordLineedit = new QLineEdit(this);
    this->okNewPasswordLineedit->setEchoMode(QLineEdit::Password);

    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));

    gridLayout->addWidget(usridLabel, 0, 0, 1, 3);
    gridLayout->addWidget(usridLineedit, 0, 3, 1, 3);
    gridLayout->addWidget(usrnameLabel, 1, 0, 1, 3);
    gridLayout->addWidget(usrnameLineedit, 1, 3, 1, 3);
    gridLayout->addWidget(usrlimitLabel, 2, 0, 1, 3);
    gridLayout->addWidget(usrlimitLineedit, 2, 3, 1, 3);

    gridLayout->addWidget(initPasswordLabel, 3, 0, 1, 3);
    gridLayout->addWidget(initPasswordLineedit, 3, 3, 1, 3);
    gridLayout->addWidget(newPasswordLabel, 4, 0, 1, 3);
    gridLayout->addWidget(newPasswordLineedit, 4, 3, 1, 3);
    gridLayout->addWidget(okNewPasswordLabel, 5, 0, 1, 3);
    gridLayout->addWidget(okNewPasswordLineedit, 5, 3, 1, 3);
    gridLayout->addWidget(buttonWidget, 6, 0, 1, 6);
    this->showNormal();
}


window_manage_password::~window_manage_password()
{
//    delete query;
    window_manage_password::num -= 1;
}

void window_manage_password::okSLOT()
{
    QString oldpw = this->initPasswordLineedit->text();
    QString newpw1 = this->newPasswordLineedit->text();
    QString newpw2 = this->okNewPasswordLineedit->text();
    if (newpw1 == newpw2 && newpw1 != ""){
        this->updatePassword(newpw2);
    }
    else{
        QMessageBox::warning(this, tr("输入结果"), tr("两次密码输入错误"));
    }
}

void window_manage_password::updatePassword(const QString &newpassword)
{
    if (utils::ping(otherPar::ip)==0)
    {
        if (QSqlDatabase::contains("SQLserver"))
            this->db = QSqlDatabase::database("SQLserver");
        else{
            this->db = QSqlDatabase::addDatabase("QODBC", "SQLserver");   //数据库驱动类型为SQL Server
            QString dsn = "DRIVER={SQL SERVER};SERVER=" + otherPar::ip + ";DATABASE=p;"
                    "UID=sa;PWD=123456;";
            db.setDatabaseName(dsn);
        }


        if(!db.open())                                      //打开数据库
        {
            QMessageBox::warning(this, tr("连接结果"), tr("数据库连接失败"));
        }
        else
        {
            QString oldpw = this->initPasswordLineedit->text();

            this->query = new QSqlQuery(this->db);
            this->query->exec(QString("SELECT * FROM users WHERE userid='%1' AND usercode='%2'").arg(otherPar::userid).arg(oldpw));
            if (query->next()){
                this->query->exec(QString("UPDATE users SET usercode='%1' WHERE userid = '%2'").arg(newpassword).arg(otherPar::userid));

                QString ipv4 = utils::getIPV4address();
                QDateTime curDateTime = QDateTime::currentDateTime();
                QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
                this->query->exec("SELECT MAX(recid) FROM records");
                this->query->next();
                int recid = this->query->value(0).toInt() + 1;
                QString sqlInsertRecord = QString("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '更改密码')").arg(recid).
                        arg(otherPar::userid).arg(ipv4).arg(date);
                this->query->exec(sqlInsertRecord);
                this->okNewPasswordLineedit->clear();
                this->newPasswordLineedit->clear();
                this->initPasswordLineedit->clear();
                QMessageBox::information(this, tr("更改结果"), tr("密码更改成功"));
            }
            else{
                QMessageBox::warning(this, tr("更改结果"), tr("用户原密码输入错误"));
            }
        }
    }
    else
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));

}


