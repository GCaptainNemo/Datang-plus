#include "openproject_window.h"

int openPjWindow::num = 0;


void openPjWindow::setLineeditTextSLOT(const QModelIndex & index)
{
    QModelIndex i = pjModel->index(index.row(), 0);
    QString prid = pjModel->data(i).toString();
    this->pjLineedit->setText(prid);
}

void openPjWindow::openPjSLOT()
{
    QString prid = this->pjLineedit->text();
    if (prid == "")
        QMessageBox::information(this, tr("打开结果"), tr("请输入项目编号"));
    else{
        QSqlQuery query(this->db); //查询Card表并输出，测试能否正常操作数据库
        QString sqlVerify = "SELECT * FROM projects WHERE prid=" + prid;
        query.exec(sqlVerify);
        if (!query.next())
            QMessageBox::information(this, tr("打开结果"), tr("没有该项目"));
        else{
            QMessageBox::information(this, tr("打开结果"), tr("项目打开成功"));
            emit pridSIGNAL(prid.toInt());
            this->close();
        }
    }
}



void openPjWindow::setPjModel()
{
    if (dbUtils::ping(Login_window::ip)==0)
    {
        this->db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
        QString dsn = "DRIVER={SQL SERVER};SERVER=" + Login_window::ip + ";DATABASE=p;"
                "UID=sa;PWD=123456;";
        db.setDatabaseName(dsn);

        if(!db.open())                                      //打开数据库
        {
            QMessageBox::information(this, tr("连接结果"), tr("数据库连接失败"));
        }
        else
        {
            this->pjModel = new QSqlQueryModel(this->tableView);
            pjModel->setQuery(QString("SELECT prid, prname, prstate, preditnum, prdesigh, prcheck, prverify FROM projects ORDER BY prid ASC"));

            pjModel->setHeaderData(0, Qt::Horizontal,QObject::tr("编号"));
            pjModel->setHeaderData(1, Qt::Horizontal,QObject::tr("项目名称"));
            pjModel->setHeaderData(2, Qt::Horizontal,QObject::tr("状态"));
            pjModel->setHeaderData(3, Qt::Horizontal,QObject::tr("版次"));
            pjModel->setHeaderData(4, Qt::Horizontal,QObject::tr("设计人编号"));
            pjModel->setHeaderData(5, Qt::Horizontal,QObject::tr("校核人编号"));
            pjModel->setHeaderData(6, Qt::Horizontal,QObject::tr("审核人编号"));
            this->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
            this->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            this->tableView->setModel(pjModel);
        }
    }
    else
        QMessageBox::information(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
}


openPjWindow::~openPjWindow(){
    openPjWindow::num -= 1;
    qDebug() << "openPjWindow::num =  " <<openPjWindow::num ;
}



openPjWindow::openPjWindow(QWidget *parent) : QWidget(parent)
{
    openPjWindow::num += 1;
    qDebug() << "openPjWindow::num =  " <<openPjWindow::num ;
    this->setWindowTitle(tr("打开项目"));

    this->pjLabel = new QLabel("点击项目或输入项目号");
    this->pjLineedit = new QLineEdit;
    this->openButton = new QPushButton("打开");
    connect(openButton, SIGNAL(clicked(bool)), this, SLOT(openPjSLOT()));
    this->tableView = new QTableView;

    this->projectModel = new QSqlTableModel;
 
    this->hlayout = new QHBoxLayout;
    this->hlayout->addWidget(this->pjLabel);
    this->hlayout->addWidget(this->pjLineedit);
    this->hlayout->addWidget(this->openButton);

    this->layout = new QVBoxLayout(this);
    this->layout->addWidget(this->tableView);
    this->layout->addLayout(this->hlayout);

    this->setPjModel();
    connect(tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(setLineeditTextSLOT(const QModelIndex &)));

    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

}
