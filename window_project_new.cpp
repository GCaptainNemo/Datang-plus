#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_project_new.h"
#include <iostream>

int newPjWindow::num = 0;

newPjWindow::newPjWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);



    newPjWindow::num += 1;
    this->nameLabel = new QLabel(tr("项目名称"), this);
    this->nameLineedit = new QLineEdit(this);
    this->okButton = new QPushButton("确定", this);
    this->layout = new QHBoxLayout(this);
    this->layout->addWidget(this->nameLabel);
    this->layout->addWidget(this->nameLineedit);
    this->layout->addWidget(this->okButton);

    connect(okButton, SIGNAL(clicked()), this, SLOT(okSLOT()));
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->show();
    this->setWindowTitle(tr("新建项目"));

}

newPjWindow::~newPjWindow(){
    newPjWindow::num -= 1;
}


void newPjWindow::okSLOT()
{

    QString name = this->nameLineedit->text();
    qDebug() << "name == " << name;
    if (name == "")
        QMessageBox::information(this, tr("新建结果"), tr("请输入项目名称"));
    else{
        int ok = this->testDb();
        if (ok == 1){

            QSqlQuery query(this->db); //查询Card表并输出，测试能否正常操作数据库
            QString sqlVerify = "SELECT * FROM projects WHERE prname=" + name;
            query.exec(sqlVerify);
            if (query.next())
                QMessageBox::information(this, tr("新建结果"), tr("项目已经存在，添加失败"));
            else{
                QMessageBox::information(this, tr("新建结果"), tr("项目新建成功"));
//                projects::setPar(query.value(1).toString().toStdString(), query.value(2).toInt());
//                qDebug() << "pj_name = " << QString::fromStdString(projects::pj_name);
//                this->start(prid);
                this->close();
            }
        }
    }
}


int newPjWindow::testDb()
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
        return 1;
    }
    else{
        QMessageBox::information(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
        return 0;
    }
}


