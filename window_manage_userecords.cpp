#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_manage_userecords.h"



int manageaRecordsWindow::num = 0;

manageaRecordsWindow::manageaRecordsWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    this->setAttribute(Qt::WA_DeleteOnClose);
    manageaRecordsWindow::num += 1;
    this->setWindowTitle(tr("使用记录管理"));

    this->widget = new QWidget(this);
    this->widget->setFixedHeight(400);
    this->dateLabel = new QLabel("开始时间+结束时间(格式为2018-1-1):", this->widget);
    this->initDateLineedit = new QLineEdit(this->widget);
    this->lastDateLineedit = new QLineEdit(this->widget);
    this->passwordLabel = new QLabel("请输入登录密码:", this->widget);
    this->passwordLineedit = new QLineEdit(this->widget);
    this->passwordLineedit->setEchoMode(QLineEdit::Password);


    this->deleteButton = new QPushButton("删除记录", this->widget);
    this->exportButton = new QPushButton("导出Excel文件", this->widget);
    connect(exportButton, SIGNAL(clicked(bool)), this, SLOT(exportExcelSLOT()));
    this->previousPageButton = new QPushButton("上一页", this->widget);
    connect(previousPageButton, SIGNAL(clicked(bool)), this, SLOT(previousPageSLOT()));
    this->nextPageButton = new QPushButton("下一页", this->widget);
    connect(nextPageButton, SIGNAL(clicked(bool)), this, SLOT(nextPageSLOT()));
    this->firstPageButton = new QPushButton("第一页", this->widget);
    connect(firstPageButton, SIGNAL(clicked(bool)), this, SLOT(firstPageSLOT()));
    this->lastPageButton = new QPushButton("最后一页", this->widget);
    connect(lastPageButton, SIGNAL(clicked(bool)), this, SLOT(lastPageSLOT()));

    this->calenderButton1 = new QPushButton(tr("日历"), this->widget);
    this->calenderButton2 = new QPushButton(tr("日历"), this->widget);
    buttonGroup = new QButtonGroup(this->widget);
    buttonGroup->addButton(calenderButton1, 1);
    buttonGroup->addButton(calenderButton2, 2);

    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(calenderShowSLOT(const int &)));

    this->currentPageLabel = new QLabel(tr(""), this->widget);
    currentPageLabel->setAlignment(Qt::AlignCenter);
    this->totalPageLabel = new QLabel(tr(""), this->widget);
    totalPageLabel->setAlignment(Qt::AlignCenter);
    this->totalRecordsLabel = new QLabel(tr(""), this->widget);
    totalRecordsLabel->setAlignment(Qt::AlignCenter);
    this->eachPageRecordsLabel = new QLabel(tr("每页100条"), this->widget);
    eachPageRecordsLabel->setAlignment(Qt::AlignCenter);

    connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteSLOT()));

    this->tableWidget = new QTableWidget(this);
    this->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->gridLayout = new QGridLayout(this->widget);
    this->gridLayout->addWidget(this->dateLabel, 0, 0, 1, 6);
    this->gridLayout->addWidget(this->initDateLineedit, 1, 0, 1, 4);
    this->gridLayout->addWidget(this->calenderButton1, 1, 4, 1, 2);
    this->gridLayout->addWidget(this->lastDateLineedit, 2, 0, 1, 4);
    this->gridLayout->addWidget(this->calenderButton2, 2, 4, 1, 2);
    this->gridLayout->addWidget(this->passwordLabel, 3, 0, 1, 3);
    this->gridLayout->addWidget(this->passwordLineedit, 3, 3, 1, 3);


    this->gridLayout->addWidget(this->exportButton, 4, 0, 1, 3);
    this->gridLayout->addWidget(this->deleteButton, 4, 3, 1, 3);
    this->gridLayout->addWidget(this->previousPageButton, 5, 0, 1, 3);
    this->gridLayout->addWidget(this->nextPageButton, 5, 3, 1, 3);
    this->gridLayout->addWidget(this->firstPageButton, 6, 0, 1, 3);
    this->gridLayout->addWidget(this->lastPageButton, 6, 3, 1, 3);

    this->gridLayout->addWidget(this->currentPageLabel, 7, 0, 1, 6);
    this->gridLayout->addWidget(this->totalPageLabel, 8, 0, 1, 6);
    this->gridLayout->addWidget(this->totalRecordsLabel, 9, 0, 1, 6);
    this->gridLayout->addWidget(this->eachPageRecordsLabel, 10, 0, 1, 6);



    this->layout = new QHBoxLayout(this);
    this->layout->addWidget(this->tableWidget);
    this->layout->addWidget(this->widget);
    this->setRecordsModel();
    this->showMaximized();

}

manageaRecordsWindow::~manageaRecordsWindow()
{
    delete query;
    if (myCalender::calenderNum == 1)
        calenderWidget->close();

    manageaRecordsWindow::num -= 1;
}

void manageaRecordsWindow::calenderShowSLOT(const int & id)
{
    if (myCalender::calenderNum >= 1)
    {
        calenderWidget->close();
    }

    calenderWidget = new myCalender;
    if(id == 1)
        connect(calenderWidget, SIGNAL(clicked(QDate)), this, SLOT(initDateLineeditSLOT(QDate)));
    else{
        connect(calenderWidget, SIGNAL(clicked(QDate)), this, SLOT(lastDateLineeditSLOT(QDate)));

    }
}

void manageaRecordsWindow::exportExcelSLOT()
{

    //    construct function

    QString password = this->passwordLineedit->text();
    QString initdate = this->initDateLineedit->text();
    QString lastdate = this->lastDateLineedit->text();
    if(password == userPar::usercode)
    {
        if (db.open())
        {
            switch (QMessageBox::question(this, tr("导出提示信息"), QString("你确定要导出%1 0:0:0 - %2 23:59:59 的记录吗？").arg(initdate).arg(lastdate),
                                  QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
            {
            case QMessageBox::Ok:{
                QString sqlExportStatement = QString("SELECT * FROM records WHERE rectime between '%1' AND '%2 23:59:59' "
                                                     "ORDER BY recid DESC").arg(initdate).arg(lastdate);
                this->query->exec(sqlExportStatement);
                myexcel = new QAxObject("Excel.Application");
                //false显示窗体（看具体过程）
                myexcel->dynamicCall("SetVisible(bool)", true);
                //显示警告信息
                myexcel->setProperty("DisplayAlerts", true);

                mywork = myexcel->querySubObject("WorkBooks");
                mywork->dynamicCall("Add");
                workbook = myexcel->querySubObject("ActiveWorkBook");
                mysheet = workbook->querySubObject("Sheets");


                mysheet->dynamicCall("Add");
                QAxObject *sheet = workbook->querySubObject("ActiveSheet");
                sheet->setProperty("Name", "使用记录");

                QAxObject *cell;
                cell = sheet->querySubObject("Range(QVariant, QVariant)", "A1");
                cell->dynamicCall("SetValue(const QVariant&)", QVariant("编号"));
                cell = sheet->querySubObject("Range(QVariant, QVariant)", "B1");
                cell->dynamicCall("SetValue(const QVariant&)", QVariant("用户名"));
                cell = sheet->querySubObject("Range(QVariant, QVariant)", "C1");
                cell->dynamicCall("SetValue(const QVariant&)", QVariant("用户IP"));
                cell = sheet->querySubObject("Range(QVariant, QVariant)", "D1");
                cell->dynamicCall("SetValue(const QVariant&)", QVariant("操作时间"));
                cell = sheet->querySubObject("Range(QVariant, QVariant)", "E1");
                cell->dynamicCall("SetValue(const QVariant&)", QVariant("操作"));
                int num = 1;
                QAxObject * range;
                while(query->next())
                {
                    num += 1;
                    for(int i = 0; i<=4; ++i)
                    {
                        QString pos = this->excelMap[i] + QString("%1").arg(num);
                        cell = sheet->querySubObject("Range(QVariant, QVariant)", pos);
                        cell->dynamicCall("SetValue(const QVariant&)", QVariant(query->value(i).toString()));
                        range = sheet->querySubObject("Range(const QString&)", pos);
                        range->setProperty("HorizontalAlignment", -4108);
                    }
                }
                mysheet = workbook->querySubObject("Worksheets(int)",1);
                mysheet->querySubObject("UsedRange")->querySubObject("Columns")->dynamicCall("AutoFit");

                workbook->dynamicCall("Close()");
                myexcel->dynamicCall("Quit(void)");
                delete myexcel;

                delete query;
                this->setRecordsModel();
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

void manageaRecordsWindow::deleteSLOT()
{
    QString password = this->passwordLineedit->text();
    QString initdate = this->initDateLineedit->text();
    QString lastdate = this->lastDateLineedit->text();
    if(password == userPar::usercode)
    {
        if (db.open())
        {
            switch (QMessageBox::question(this, tr("删除提示信息"), QString("你确定要删除%1 0:0:0 - %2 23:59:59 的记录吗？").arg(initdate).arg(lastdate),
                                  QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
            {
            case QMessageBox::Ok:{
                QString sqldelete = QString("DELETE records WHERE rectime between '%1' AND '%2 23:59:59'").arg(initdate).arg(lastdate);
                this->query->exec(sqldelete);
                delete query;
                QMessageBox::information(this, tr("删除结果"), tr("删除成功"));
                this->setRecordsModel();
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



void manageaRecordsWindow::initDateLineeditSLOT(const QDate & initDate){
    this->initDateLineedit->setText(QString("%1-%2-%3").arg(initDate.year()).arg(initDate.month()).arg(initDate.day()));
}



void manageaRecordsWindow::lastDateLineeditSLOT(const QDate & lastDate){
    this->lastDateLineedit->setText(QString("%1-%2-%3").arg(lastDate.year()).arg(lastDate.month()).arg(lastDate.day()));

}


void manageaRecordsWindow::setRecordsModel()
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


        if(!db.open())                                      //打开数据库
        {
            QMessageBox::warning(this, tr("连接结果"), tr("数据库连接失败"));
        }
        else
        {
            this->query = new QSqlQuery(this->db);
            this->tableWidget->setColumnCount(5);//列数设置为与 headerText的行数相等
            this->query->exec(QString("SELECT * FROM records ORDER BY recid DESC"));
            this->query->last();
            this->totalRecordsNum = this->query->at() + 1;
            this->query->seek(-1);
            this->totalRecordsLabel->setText(QString("共%1条").arg(this->totalRecordsNum));
            this->totalPageLabel->setText(QString("共%1页").arg((this->totalRecordsNum - 1) / 100 + 1));
            this->loadModel();
        }
    }
    else
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
}


void manageaRecordsWindow::loadModel()
{
    this->tableWidget->clear();
    this->tableWidget->setRowCount(100);
    int num = 0;
    while (num <= 99 && query->next())
    {
        for(int i=0; i<=4; i++){
            this->tableWidget->setItem(num, i, new QTableWidgetItem(query->value(i).toString()));
            this->tableWidget->item(num, i)->setTextAlignment(Qt::AlignCenter);

        }
        num += 1;
    }
    qDebug() << "query.at() = "<<query->at();
    this->currentPageLabel->setText(QString("第%1页").arg(query->at() / 100 + 1));
    QStringList headerText;
    headerText<<"编号"<<"用户名"<<"用户IP"<<"操作时间"<<"操作";
    this->tableWidget->setHorizontalHeaderLabels(headerText);
    if(query->at() == 99){
        this->previousPageButton->setEnabled(false);
    }
    else{
        this->previousPageButton->setEnabled(true);
    }
    if (query->at() == - 2){
        this->nextPageButton->setEnabled(false);
        this->currentPageLabel->setText(QString("第%1页").arg((this->totalRecordsNum - 1) / 100 + 1));

    }
    else{
        this->nextPageButton->setEnabled(true);
    }


}

void manageaRecordsWindow::nextPageSLOT()
{
    this->loadModel();
}

void manageaRecordsWindow::previousPageSLOT()
{
    int index = this->query->at() - 200;
    qDebug() << "index = " << index;
    this->query->seek(index);
    this->loadModel();
}

void manageaRecordsWindow::firstPageSLOT()
{
    this->query->seek(-1);
    this->loadModel();
}

void manageaRecordsWindow::lastPageSLOT()
{
    this->query->last();

    this->query->seek(int(this->totalRecordsNum / 100) * 100 - 1);
    this->loadModel();

}



