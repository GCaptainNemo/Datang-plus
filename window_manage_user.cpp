#include "window_manage_user.h"

int window_manage_user::num = 0;


window_manage_user::window_manage_user(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    this->setAttribute(Qt::WA_DeleteOnClose);
    window_manage_user::num += 1;
    this->setWindowTitle(tr("用户管理"));

    this->tableWidget = new QTableWidget(this);
    this->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->layout = new QVBoxLayout(this);


    this->widget = new QWidget(this);
    this->managerPasswordLabel = new QLabel("请输入登录密码:", this->widget);
    this->managerPasswordLineedit = new QLineEdit(this->widget);
    this->managerPasswordLineedit->setEchoMode(QLineEdit::Password);

    this->okPasswordLabel = new QLabel("确认密码:", this->widget);
    this->okPasswordLineedit = new QLineEdit(this->widget);
    this->okPasswordLineedit->setEchoMode(QLineEdit::Password);

    this->initPasswordLabel = new QLabel("初始密码:", this->widget);
    this->initPasswordLineedit = new QLineEdit(this->widget);
    this->initPasswordLineedit->setEchoMode(QLineEdit::Password);
    this->usridLabel = new QLabel("用户名:", this->widget);
    this->usridLineedit = new QLineEdit(this->widget);

    this->usrLimitLabel = new QLabel("权限:", this->widget);
    this->usrlimitCombobox = new QComboBox(this);
    QStringList items;
    items << "设计" << "校核" << "审核" << "系统管理员";
    this->usrlimitCombobox->addItems(items);
    this->usrnameLabel = new QLabel("备注:", this->widget);
    this->usrnameLineedit = new QLineEdit(this->widget);
    this->deleteButton = new QPushButton("删除", this->widget);
    this->addButton = new QPushButton("添加", this->widget);
    this->saveButton = new QPushButton("保存", this->widget);
    this->correctButton = new QPushButton("修改", this->widget);
    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(addSLOT()));
    connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteSLOT()));
    connect(saveButton, SIGNAL(clicked(bool)), this, SLOT(saveSLOT()));
    connect(correctButton, SIGNAL(clicked(bool)), this, SLOT(updateSLOT()));




    this->gridLayout = new QGridLayout(this->widget);
    this->gridLayout ->addWidget(this->usridLabel, 0, 0, 1, 3);
    this->gridLayout ->addWidget(this->usridLineedit, 0, 3, 1 ,3);
    this->gridLayout ->addWidget(this->usrnameLabel, 0, 6, 1, 3);
    this->gridLayout ->addWidget(this->usrnameLineedit, 0, 9, 1, 3);

    this->gridLayout ->addWidget(this->initPasswordLabel, 1, 0, 1, 3);
    this->gridLayout ->addWidget(this->initPasswordLineedit, 1, 3, 1 ,3);
    this->gridLayout ->addWidget(this->okPasswordLabel, 1, 6, 1, 3);
    this->gridLayout ->addWidget(this->okPasswordLineedit, 1, 9, 1, 3);


    this->gridLayout ->addWidget(this->usrLimitLabel, 2, 0, 1, 3);
    this->gridLayout ->addWidget(this->usrlimitCombobox, 2, 3, 1, 3);
    this->gridLayout ->addWidget(this->managerPasswordLabel, 2, 6, 1, 3);
    this->gridLayout ->addWidget(this->managerPasswordLineedit, 2, 9, 1, 3);


    buttonWidget = new QWidget(this);
    hlayout = new QHBoxLayout(buttonWidget);
    hlayout->addWidget(addButton);
    hlayout->addWidget(deleteButton);
    hlayout->addWidget(saveButton);
    hlayout->addWidget(correctButton);


    this->layout->addWidget(this->tableWidget);
    this->layout->addWidget(this->widget);
    this->layout->addWidget(buttonWidget);
    this->setUserModel();
    connect(tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(setLineeditTextSLOT(int)));

    this->resize(800, 1000);
    this->showNormal();

}

window_manage_user::~window_manage_user()
{
    window_manage_user::num -= 1;
    delete query;
}


void window_manage_user::saveSLOT()
{
    QString pw = this->managerPasswordLineedit->text();
    QString pw1 = this->initPasswordLineedit->text();
    QString pw2 = this->okPasswordLineedit->text();

    QString usrid = this->usridLineedit->text();
    QString usrname = this->usrnameLineedit->text();
    QString usrlimit = this->usrlimitCombobox->currentText();
    this->managerPasswordLineedit->clear();
    if(pw == otherPar::usercode)
    {
        if (db.open())
        {
            this->query->exec("SELECT * FROM users WHERE userid='" + usrid + "'");
            if(!query->next()){
                if(pw1 == pw2)
                {
                    switch (QMessageBox::question(this, tr("删除提示信息"), "你确定要保存" + usrid + "用户吗？",
                                          QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
                    {
                    case QMessageBox::Ok:
                    {
                        qDebug() << QString("INSERT INTO users VALUES('%1', '%2', '%3', '%4')").arg(usrid).arg(pw1).arg(usrname).arg(usrlimit);

                        this->query->exec(QString("INSERT INTO users VALUES('%1', '%2', '%3', '%4')").arg(usrid).arg(pw1).arg(usrname).arg(usrlimit));

                        QString ipv4 = utils::getIPV4address();
                        QDateTime curDateTime = QDateTime::currentDateTime();
                        QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");

                        this->query->exec("SELECT MAX(recid) FROM records");
                        this->query->next();
                        int recid = this->query->value(0).toInt() + 1;
                        QString sqlInsertRecord = QString("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '添加用户").arg(recid).
                                arg(otherPar::userid).arg(ipv4).arg(date) + usrid + "')";
                        this->query->exec(sqlInsertRecord);
                        this->loadModel();
                        break;
                    }
                    default:
                        break;
                    }
                }
                else{
                    QMessageBox::warning(this, tr("添加结果"), tr("两次密码输入错误！"));
                    this->initPasswordLineedit->clear();
                    this->okPasswordLineedit->clear();
                }
            }
            else{
                    QMessageBox::warning(this, tr("添加结果"), tr("该用户已存在！"));
                }
        }
    }
    else{
        QMessageBox::warning(this, tr("输入结果"), tr("密码出错!"));
    }

}

void window_manage_user::addSLOT()
{
    this->usridLineedit->clear();
    this->usrnameLineedit->clear();
    this->initPasswordLineedit->clear();
    this->okPasswordLineedit->clear();
    this->usrlimitCombobox->setCurrentText(tr("设计"));
    this->usridLineedit->setReadOnly(false);
}

void window_manage_user::updateSLOT()
{
    QString pw = this->managerPasswordLineedit->text();
    QString pw1 = this->initPasswordLineedit->text();
    QString pw2 = this->okPasswordLineedit->text();

    QString usrid = this->usridLineedit->text();
    QString usrname = this->usrnameLineedit->text();
    QString usrlimit = this->usrlimitCombobox->currentText();
    this->managerPasswordLineedit->clear();
    if(pw == otherPar::usercode)
    {
        if (db.open())
        {
            if(pw1 == pw2 && pw1!=""){
                if(usrlimit!=""){

                    switch (QMessageBox::question(this, tr("更改提示信息"), "你确定要更改" + usrid + "用户吗？",
                                          QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
                    {
                    case QMessageBox::Ok:
                        {
                        this->query->exec("SELECT * FROM users WHERE userid='" + usrid + "'");
                        if (query->next()){
                            this->query->exec(QString("UPDATE users SET userid='%1', usercode='%2', "
                                              "username='%3', userlimit='%4' WHERE userid='%5'").arg(usrid).arg(pw1).arg(usrname).arg(usrlimit).arg(usrid));

                            this->usridLineedit->clear();
                            this->usrnameLineedit->clear();
                            this->initPasswordLineedit->clear();
                            this->okPasswordLineedit->clear();
                            QString ipv4 = utils::getIPV4address();
                            QDateTime curDateTime = QDateTime::currentDateTime();
                            QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");

                            this->query->exec("SELECT MAX(recid) FROM records");
                            this->query->next();
                            int recid = this->query->value(0).toInt() + 1;
                            QString sqlInsertRecord = QString("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '更改用户").arg(recid).
                                    arg(otherPar::userid).arg(ipv4).arg(date) + usrid + "')";
                            this->query->exec(sqlInsertRecord);
                            this->loadModel();
                        }
                        else{
                            QMessageBox::warning(this, tr("更改结果"), tr("没有该用户！"));
                            }
                        break;
                    }
                    default:
                        break;
                    }
              }
              else
                {
                    QMessageBox::warning(this, tr("更改结果"), tr("请填入用户权限！"));
                }
           }
           else{
                QMessageBox::warning(this, tr("更改结果"), tr("两次密码输入错误！"));
                this->initPasswordLineedit->clear();
                this->okPasswordLineedit->clear();
            }
        }
    }
    else{
        QMessageBox::warning(this, tr("输入结果"), tr("密码出错!"));
    }


}

void window_manage_user::deleteSLOT()
{
    QString pw = this->managerPasswordLineedit->text();
    QString usrid = this->usridLineedit->text();
    this->managerPasswordLineedit->clear();
    if(pw == otherPar::usercode)
    {
        if (db.open())
        {
            switch (QMessageBox::question(this, tr("删除提示信息"), "你确定要删除" + usrid + "用户吗？",
                                  QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
            {
            case QMessageBox::Ok:{
                this->query->exec("SELECT * FROM users WHERE userid='" + usrid + "'");
                if (query->next()){
                    this->query->exec("DELETE FROM users WHERE userid='" + usrid + "'");

                    this->usridLineedit->clear();
                    this->usrnameLineedit->clear();
                    this->initPasswordLineedit->clear();
                    this->okPasswordLineedit->clear();
                    QString ipv4 = utils::getIPV4address();
                    QDateTime curDateTime = QDateTime::currentDateTime();
                    QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");

                    this->query->exec("SELECT MAX(recid) FROM records");
                    this->query->next();
                    int recid = this->query->value(0).toInt() + 1;
                    QString sqlInsertRecord = QString("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '删除用户").arg(recid).
                            arg(otherPar::userid).arg(ipv4).arg(date) + usrid + "')";
                    this->query->exec(sqlInsertRecord);
                    this->loadModel();
                }
                else{
                    QMessageBox::warning(this, tr("删除结果"), tr("没有该用户！"));
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




void window_manage_user::setUserModel()
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
            this->tableWidget->setColumnCount(4);//列数设置为与 headerText的行数相等
            this->loadModel();
        }
    }
    else
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
}


void window_manage_user::loadModel()
{
    this->tableWidget->clear();
    this->tableWidget->setRowCount(0);
    this->query->exec(QString("SELECT * FROM users"));
    while (query->next())
    {
        int rowCount = this->tableWidget->rowCount();
        this->tableWidget->insertRow(rowCount);
        for(int i=0;i<=3;i++){
            this->tableWidget->setItem(rowCount, i, new QTableWidgetItem(query->value(i).toString()));
        }
    }
    this->tableWidget->setColumnHidden(1, true);
    QStringList headerText;
    headerText<<"用户名"<<"密码"<<"备注"<<"权限";  //表头标题用QStringList来表示
    this->tableWidget->setHorizontalHeaderLabels(headerText);
}



void window_manage_user::setLineeditTextSLOT(int row)
{
    QString usrid = this->tableWidget->item(row, 0)->text();
    QString password = this->tableWidget->item(row, 1)->text();
    QString usrname = this->tableWidget->item(row, 2)->text();
    QString usrlimit = this->tableWidget->item(row, 3)->text();
    this->usridLineedit->setText(usrid);
    this->initPasswordLineedit->setText(password);
    this->okPasswordLineedit->setText(password);
    this->usrnameLineedit->setText(usrname);
    this->usrlimitCombobox->setCurrentText(usrlimit);
    this->usridLineedit->setReadOnly(true);

}




