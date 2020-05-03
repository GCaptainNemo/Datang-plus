#include "window_project_check_opinion.h"

int window_project_check_opinion::num = 0;

window_project_check_opinion::window_project_check_opinion(QWidget *parent) : QDialog(parent)
{
    window_project_check_opinion::num += 1;
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);


    this->setWindowTitle(tr("校审意见"));


    this->layout = new QGridLayout(this);
    this->checkStateLabel = new QLabel(tr("校核状态"), this);
    this->checkOpinionLabel = new QLabel(tr("校核意见"), this);
    this->verifyOpinionLabel = new QLabel(tr("审核意见"), this);



    this->checkStateLineedit = new QLineEdit(this);
    this->checkStateLineedit->setReadOnly(true);
    this->checkOpinionTextedit = new QTextEdit(this);
    this->checkOpinionTextedit->setReadOnly(true);
    this->verifyOpinionTextEdit = new QTextEdit(this);
    this->verifyOpinionTextEdit->setReadOnly(true);

    this->layout->addWidget(this->checkStateLabel, 0, 0, 1, 3);
    this->layout->addWidget(this->checkStateLineedit, 0, 3, 1, 3);
    this->layout->addWidget(this->checkOpinionLabel, 1, 0, 3, 3);
    this->layout->addWidget(this->checkOpinionTextedit, 1, 3, 3, 3);
    this->layout->addWidget(this->verifyOpinionLabel, 4, 0, 3, 3);
    this->layout->addWidget(this->verifyOpinionTextEdit, 4, 3, 3, 3);
    this->initTextEdit();
    this->showNormal();
}

void window_project_check_opinion::initTextEdit()
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
            QString sqlStatement = QString("SELECT prstate, prcheckinf, prverifyinf FROM projects WHERE prid='%1'").arg(otherPar::prid);
            qDebug() << sqlStatement;
            query = new QSqlQuery(db);
            this->query->exec(sqlStatement);
            if (query->next())
            {
                qDebug() << "query.value(0) = " << query->value(0).toString();

                this->checkStateLineedit->setText(query->value(0).toString());
                this->checkOpinionTextedit->setText(query->value(1).toString());
                this->verifyOpinionTextEdit->setText(query->value(2).toString());
            }
            delete query;
            this->close();
        }
    }
    else
    {
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
    }


}

window_project_check_opinion::~window_project_check_opinion()
{
    window_project_check_opinion::num -= 1;
}

