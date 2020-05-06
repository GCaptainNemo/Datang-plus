#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_project_new.h"
#include <iostream>

int newProjectWindow::num = 0;

newProjectWindow::newProjectWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("新建项目"));



    newProjectWindow::num += 1;
    this->nameLabel = new QLabel(tr("项目名称"), this);
    this->nameLineedit = new QLineEdit(this);
    this->buttonWidget = new widget_okcancel(this);
    this->layout = new QGridLayout(this);
    this->layout->addWidget(this->nameLabel, 0, 0, 1, 3);
    this->layout->addWidget(this->nameLineedit, 0, 3, 1, 3);
    this->layout->addWidget(this->buttonWidget, 1, 0, 1, 6);

    connect(buttonWidget->okButton, SIGNAL(clicked()), this, SLOT(okSLOT()));
    connect(buttonWidget->cancelButton, SIGNAL(clicked()), this, SLOT(close()));

    this->showNormal();

}

newProjectWindow::~newProjectWindow(){
    newProjectWindow::num -= 1;
}


void newProjectWindow::okSLOT()
{

    QString name = this->nameLineedit->text();
    if (name == "")
        QMessageBox::information(this, tr("新建结果"), tr("请输入项目名称"));
    else{
        int ok = this->testDb();
        if (ok == 1){
            query = new QSqlQuery(this->db); //查询Card表并输出，测试能否正常操作数据库
            QString sqlVerify = "SELECT * FROM projects WHERE prname=" + name;
            query->exec(sqlVerify);
            if (query->next())
                QMessageBox::information(this, tr("新建结果"), tr("项目已经存在，添加失败"));
            else{
                projectPar::pj_name = name;
                emit changeTitleSIGNAL();


                QString ipv4 = utils::getIPV4address();
                QDateTime curDateTime = QDateTime::currentDateTime();
                QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");

                query->exec("SELECT MAX(prid) FROM projects");
                query->next();
                projectPar::prid = QString("%1").arg(query->value(0).toString().toInt() + 1);


                //  插入项目prid

                query->exec(QString("INSERT INTO projects(prid, prname, prstate, preditnum, prdesigh) VALUES(%1, '%2', '设计中', 1, '%3')").
                            arg(projectPar::prid).arg(projectPar::pj_name).arg(userPar::userid));
                query->exec(QString("INSERT INTO GasResult(prid) VALUES(%1)").arg(projectPar::prid));
                query->exec(QString("INSERT INTO GSLResult(prid) VALUES(%1)").arg(projectPar::prid));
                query->exec(QString("INSERT INTO pinf(prid, Eid) VALUES(%1, 1)").arg(projectPar::prid));
                query->exec(QString("INSERT INTO Equip(prid) VALUES(%1)").arg(projectPar::prid));
                query->exec(QString("INSERT INTO Coal(prid) VALUES(%1)").arg(projectPar::prid));
                query->exec("SELECT MAX(recid) FROM records");
                query->next();
                int recid = query->value(0).toInt() + 1;
                QString sqlInsertRecord = QString ("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '新建项目%5')").arg(recid).
                        arg(userPar::userid).arg(ipv4).arg(date).arg(projectPar::prid);
                query->exec(sqlInsertRecord);

                this->setInitValue();

                QMessageBox::information(this, tr("新建结果"), tr("项目新建成功"));
                this->close();
            }
        }
    }
}


int newProjectWindow::testDb()
{
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
        return 1;
    }
    else{
        QMessageBox::information(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
        return 0;
    }
}

void newProjectWindow::setInitValue()
{
    // Coal

    pinfPar::ss = "0010100";

}


