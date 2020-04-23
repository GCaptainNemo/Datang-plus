#include "window_project_open.h"



setParObject::setParObject(const int &prid):prid(prid){
    QString pd = QString::number(this->prid);
    sqlPinf = "SELECT * FROM Pinf with(nolock) WHERE prid=" + pd;
    sqlGasResult = "SELECT * FROM GasResult WHERE prid=" + pd;
    sqlGSLResult = "SELECT * FROM GSLResult WHERE prid=" + pd;
    sqlEquip = "SELECT * FROM Equip WHERE prid=" + pd;
    sqlCoal = "SELECT * FROM Coal WHERE prid=" + pd;
    sqlExp = "SELECT * FROM Experience  WHERE Eid=" +pd;
}

void setParObject::start()
{
    qDebug() << "in successfully";
    if (QSqlDatabase::contains("SQLserver"))
        this->db = QSqlDatabase::database("SQLserver");
    else{
        this->db = QSqlDatabase::addDatabase("QODBC", "SQLserver");   //数据库驱动类型为SQL Server
        QString dsn = "DRIVER={SQL SERVER};SERVER=" + Login_window::ip + ";DATABASE=p;"
                "UID=sa;PWD=123456;";
        db.setDatabaseName(dsn);
    }

    if (db.open())
    {
        this->query = new QSqlQuery(this->db);

        //        设置Coal 参数


        this->query->exec(sqlCoal);
        if (query->next()){
            this->coalPtr = new Coal(query->value(0).toFloat(), query->value(1).toFloat(),
                             query->value(2).toFloat(), query->value(3).toFloat(),
                             query->value(4).toFloat(), query->value(5).toFloat(),
                             query->value(6).toFloat(), query->value(7).toFloat(),
                             query->value(8).toFloat());
            delete coalPtr;
            qDebug() << "煤气参数 = "<<Coal::Ap << Coal::S;
        }


        //        设置Equip 参数

        this->query->exec(sqlEquip);
        if (query->next()){
            equipPtr = new Equip(query);
            delete equipPtr;
        }
        else
            qDebug() << "error";


        qDebug() << "sqlGasResult = " << sqlGasResult;
        this->query->exec(sqlGasResult);
        if (query->next()){
            gasResultPtr = new gasResultPar(query);
            delete gasResultPtr;
        }
        else
            qDebug() << "error";

        this->query->exec(sqlGSLResult);
        if(query->next()){
            gslResultPtr = new gslResultPar(query);
            delete gslResultPtr;
        }

        this->query->exec(sqlPinf);
        if(query->next()){
            pinf::pinfPar(query);
        }

        this->query->exec(sqlExp);
        if(query->next()){
            experiencePar *exParPtr = new experiencePar(query);
            delete exParPtr;
            qDebug() << "end load in data";
        }

    }
    delete query;
    db.close();
    emit finishedSIGNAL();
}



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
            projects::setPar(query.value(1).toString().toStdString(), query.value(2).toInt());
            qDebug() << "pj_name = " << QString::fromStdString(projects::pj_name);
            emit threadStart(prid.toInt());
            this->close();
        }
    }
}



void openPjWindow::setPjModel()
{
    if (utils::ping(Login_window::ip)==0)
    {
        if (QSqlDatabase::contains("SQLserver"))
            this->db = QSqlDatabase::database("SQLserver");
        else{
            this->db = QSqlDatabase::addDatabase("QODBC", "SQLserver");   //数据库驱动类型为SQL Server
            QString dsn = "DRIVER={SQL SERVER};SERVER=" + Login_window::ip + ";DATABASE=p;"
                    "UID=sa;PWD=123456;";
            db.setDatabaseName(dsn);
        }
        if(!db.open())                                      //打开数据库
        {
            QMessageBox::information(this, tr("连接结果"), tr("数据库连接失败"));
        }
        else
        {
            this->pjModel = new QSqlQueryModel(this->tableView);
            pjModel->setQuery(QString("SELECT prid, prname, prstate, preditnum, prdesigh, prcheck, prverify FROM projects ORDER BY prid ASC"), db);

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



openPjWindow::openPjWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);


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
    this->showMaximized();

}