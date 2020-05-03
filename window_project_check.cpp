#include "window_project_check.h"

int checkProjectWindow::num = 0;

checkProjectWindow::checkProjectWindow(QWidget *parent) : QDialog(parent)
{

    checkProjectWindow::num += 1;
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);


    this->setWindowTitle(tr("校核项目"));
    this->resize(1000, 800);


    this->checkOpinionTextedit = new QTextEdit(this);


    this->buttonGroup = new QButtonGroup(this);
    this->passRadioButton = new QRadioButton(tr("校核通过"), this);
    this->recalculateRadioButton= new QRadioButton(tr("重新计算"), this);
    this->buttonGroup->addButton(this->passRadioButton, 1);
    this->buttonGroup->addButton(this->recalculateRadioButton, 0);


    this->radioButtonWidget = new QWidget(this);
    this->hlayout1 = new QHBoxLayout(radioButtonWidget);
    this->hlayout1->addWidget(this->passRadioButton);
    this->hlayout1->addWidget(this->recalculateRadioButton);


    this->okCancelButtonWidget = new widget_okcancel(this);


    this->layout = new QVBoxLayout(this);
    this->layout->addWidget(this->checkOpinionTextedit);
    this->layout->addWidget(this->radioButtonWidget);
    this->layout->addWidget(this->okCancelButtonWidget);
    connect(okCancelButtonWidget->cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(okCancelButtonWidget->okButton, SIGNAL(clicked()), this, SLOT(okSLOT()));

    this->setAttribute(Qt::WA_DeleteOnClose);

    if (this->verifyLimit())
        this->showNormal();
    else{
        this->close();
    }
}

checkProjectWindow::~checkProjectWindow(){
    checkProjectWindow::num -= 1;
}

bool checkProjectWindow::verifyLimit()
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
            this->query = new QSqlQuery(this->db);
            QString sqlStatement = QString("SELECT prstate FROM projects WHERE prid='%1'").arg(otherPar::prid);
            this->query->exec(sqlStatement);
            if (query->next())
            {
               if (query->value(0).toString() == "设计中")
               {
                   QMessageBox::warning(this, tr("提示"), tr("未提交校审"));
                    return false;
               }
               else
                   return true;
            }
        }
    }
    else
    {
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
    }
    return false;
}


void checkProjectWindow::okSLOT()
{

    if(checkOpinionTextedit->toPlainText() == "")
    {
        QMessageBox::warning(this, tr("输入错误"), tr("意见输入不能为空"));
    }
    else if(!passRadioButton->isChecked() && !recalculateRadioButton->isChecked())
    {
        QMessageBox::warning(this, tr("输入错误"), tr("请选择“校核通过”或“重新计算”"));
    }
    else
    {
        this->checking();
    }

}


void checkProjectWindow::checking()
{
    if (utils::ping(otherPar::ip)==0)
    {
        if(!db.open())                                      //打开数据库
        {
            QMessageBox::warning(this, tr("连接结果"), tr("数据库连接失败"));
        }
        else
        {
            QString sqlStatement;
            if (passRadioButton->isChecked())
            {
                sqlStatement =  QString("UPDATE projects SET prstate = '校核通过', "
                                        "prcheck='%1', prcheckinf='%2' WHERE prid='%3'"
                                        ).arg(otherPar::userid).arg(checkOpinionTextedit->toPlainText()).arg(otherPar::prid);
            }
            else
            {
                sqlStatement =  QString("UPDATE projects SET prstate = '校核未通过返回重新计算', "
                                     "prcheck='%1', prcheckinf='%2' WHERE prid='%3'"
                                     ).arg(otherPar::userid).arg(checkOpinionTextedit->toPlainText()).arg(otherPar::prid);
            }
            this->query->exec(sqlStatement);
            QString ipv4 = utils::getIPV4address();
            QDateTime curDateTime = QDateTime::currentDateTime();
            QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
            QString sqlMax = "SELECT MAX(recid) FROM records";
            query->exec(sqlMax);
            query->next();
            int recid = query->value(0).toInt() + 1;
            QString sqlInsertRecords = QString ("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '校核项目%5')").arg(recid).
            arg(otherPar::userid).arg(ipv4).arg(date).arg(otherPar::prid);

            query->exec(sqlInsertRecords);
            delete query;
            QMessageBox::information(this, tr("提交结果"), tr("提交校核成功！"));
            this->close();
        }
    }
    else
    {
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
    }
}




