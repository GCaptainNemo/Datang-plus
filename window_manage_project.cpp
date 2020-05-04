#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_manage_project.h"

int manageProjectWindow::num = 0;

manageProjectWindow::manageProjectWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    this->setAttribute(Qt::WA_DeleteOnClose);
    manageProjectWindow::num += 1;
    this->setWindowTitle(tr("项目管理"));

    this->widget = new QWidget(this);
    this->passwordLabel = new QLabel("请输入登录密码:", this->widget);
    this->passwordLineedit = new QLineEdit(this->widget);
    this->passwordLineedit->setEchoMode(QLineEdit::Password);
    this->pridLabel = new QLabel("项目编号:", this->widget);
    this->pridLineedit = new QLineEdit(this->widget);


    this->deleteButton = new QPushButton("删除", this->widget);
    this->cancelButton = new QPushButton("取消", this->widget);
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteProjectSLOT()));
    this->tableWidget = new QTableWidget(this);
    this->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->hlayout = new QHBoxLayout(this->widget);
    this->hlayout->addWidget(this->passwordLabel);
    this->hlayout->addWidget(this->passwordLineedit);
    this->hlayout->addWidget(this->pridLabel);
    this->hlayout->addWidget(this->pridLineedit);

    this->hlayout->addWidget(this->deleteButton);
    this->hlayout->addWidget(this->cancelButton);
    this->layout = new QVBoxLayout(this);
    this->layout->addWidget(this->tableWidget);
    this->layout->addWidget(this->widget);
    this->setPjModel();
    connect(tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(setLineeditTextSLOT(int)));

    this->showMaximized();

}

manageProjectWindow::~manageProjectWindow()
{
    manageProjectWindow::num -= 1;
    delete query;


}

void manageProjectWindow::setPjModel()
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
            this->tableWidget->setColumnCount(7);//列数设置为与 headerText的行数相等
            this->loadModel();
        }
    }
    else
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
}


void manageProjectWindow::loadModel()
{
    this->tableWidget->clear();
    this->tableWidget->setRowCount(0);
    this->query->exec(QString("SELECT prid, prname, prstate, preditnum, prdesigh, prcheck, prverify FROM projects ORDER BY prid ASC"));
    while (query->next())
    {
        int rowCount = this->tableWidget->rowCount();
        this->tableWidget->insertRow(rowCount);
        for(int i=0;i<=6;i++){
            this->tableWidget->setItem(rowCount, i, new QTableWidgetItem(query->value(i).toString()));
        }

    }
    QStringList headerText;
    headerText<<"编号"<<"项目名称"<<"状态"<<"版次"<<"设计人编号"<<"校核人编号"<<"审核人编号";  //表头标题用QStringList来表示
    this->tableWidget->setHorizontalHeaderLabels(headerText);

}



void manageProjectWindow::setLineeditTextSLOT(int row)
{
    QString prid = this->tableWidget->item(row, 0)->text();
    this->pridLineedit->setText(prid);
}



void manageProjectWindow::deleteProjectSLOT()
{
    QString name = this->passwordLineedit->text();
    QString prid = this->pridLineedit->text();
    if(name == otherPar::usercode)
    {
        this->initSqlStatement(prid);
        if (db.open())
        {
            switch (QMessageBox::question(this, tr("删除提示信息"), "你确定要删除" + prid + "项目吗？",
                                  QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
            {
            case QMessageBox::Ok:{
                this->query->exec("SELECT * FROM projects WHERE prid =" + prid);
                if (query->next()){
                    this->query->exec(sqlProject);
                    this->query->exec(sqlCoal);
                    this->query->exec(sqlGSL);
                    this->query->exec(sqlPinf);
                    this->query->exec(sqlEquip);
                    this->query->exec(sqlGas);

                    QString ipv4 = utils::getIPV4address();
                    QDateTime curDateTime = QDateTime::currentDateTime();
                    QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");

                    this->query->exec("SELECT MAX(recid) FROM records");
                    this->query->next();
                    int recid = this->query->value(0).toInt() + 1;
                    QString sqlInsertRecord = QString("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '删除项目").arg(recid).
                            arg(otherPar::userid).arg(ipv4).arg(date) + prid + "')";
                    this->query->exec(sqlInsertRecord);
                    this->loadModel();
                }
                else{
                    QMessageBox::warning(this, tr("删除结果"), tr("没有该项目！"));
                }
                break;
            }
            default:
                break;
            }
        }
    }
    else{
        QMessageBox::warning(this, tr("输入结果"), tr("密码出错!"));
    }
}

void manageProjectWindow::initSqlStatement(QString prid)
{
    this->sqlPinf = "DELETE Pinf WHERE prid =" +prid;
    this->sqlEquip = "DELETE Equip WHERE prid = " + prid;
    this->sqlGas = "DELETE GasResult WHERE prid = " + prid;
    this->sqlGSL = "DELETE GSLResult WHERE prid = " + prid;
    this->sqlCoal = "DELETE Coal WHERE prid = " + prid;
    this->sqlProject ="DELETE projects WHERE prid = " + prid;

}
