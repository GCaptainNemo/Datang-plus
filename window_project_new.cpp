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

                this->setInitValue();

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
                query->exec(QString("INSERT INTO pinf(prid, Pequip, Eid) VALUES(%1, '%2', '%3')").arg(projectPar::prid).arg(pinfPar::ss).arg(pinfPar::Expid));
                query->exec(QString("INSERT INTO Equip(prid) VALUES(%1)").arg(projectPar::prid));
                query->exec(QString("INSERT INTO Coal VALUES(%1, %2, %3, %4, %5, %6, %7, %8, %9, %10)").arg(projectPar::prid).arg(Coal::Ap).arg(Coal::bj).arg(Coal::W).arg(Coal::A).arg(Coal::S).arg(Coal::H).arg(Coal::C).arg(Coal::N).arg(Coal::O));
                query->exec("SELECT MAX(recid) FROM records");
                query->next();
                int recid = query->value(0).toInt() + 1;
                QString sqlInsertRecord = QString ("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '新建项目%5')").arg(recid).
                        arg(userPar::userid).arg(ipv4).arg(date).arg(projectPar::prid);
                query->exec(sqlInsertRecord);



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

    Coal::Ap = 1.37;
    Coal::bj = 0;
    Coal::W = 0;
    Coal::A = 0;
    Coal::S = 0;
    Coal::H = 0;
    Coal::C = 0;
    Coal::N = 0;
    Coal::O = 0;

    // 输入参数

    inputParameterWindow::bz1 = 0;
    inputParameterWindow::bz2 = 0;

    for(int i=0; i<23; ++i)
    {
        gasResultPar::Gas[0][0][i] = 0;
    }
    pinfPar::VCaCO3 = 92.95;
    pinfPar::VMgCO3 = 2.95;
    pinfPar::Vother = 0;
    gslResultPar::GSL[0][19][14] = 15;
    pinfPar::yS = 0.95; // 脱硫效率
    gslResultPar::GSL[0][11][14] = 20000;
    gslResultPar::GSL[0][5][16] = 0.04;
    pinfPar::zysh = 0.5;
    gasResultPar::Gas[0][4][22] = 80;
    pinfPar::Pcaco3 = 2.5;

    pinfPar::PP1 = 2;
    pinfPar::PP2 = 0.3;
    pinfPar::PP3 = 0.5;
    pinfPar::PP4 = 1.5;
    pinfPar::PP5 = 0;
    pinfPar::PP6 = 1.2;
    pinfPar::PP7 = 0.5;
    pinfPar::PP8 = 0;
    pinfPar::PP9 = 1.5;
    pinfPar::PP10 = 0.3;
    pinfPar::PP11 = 1.2;
    pinfPar::PP12 = 3;
    pinfPar::PP13 = 12;

    absorberSystem::FGDnum = 2;
    absorberSystem::vin = 13.3;
    absorberSystem::vout = 15.5;
    absorberSystem::u = 3.8;
    absorberSystem::bc = 2.5;
    absorberSystem::cd = 1.3;
    absorberSystem::D = 1.5;
    absorberSystem::pc = 3;
    so2AbsorbSystem::xg = 3;
    absorberSystem::E = 1.8;
    absorberSystem::g = 2.5;
    absorberSystem::k = 0.5;
    absorberSystem::hx = 0.8;
    absorberSystem::NUMjb = 3;

    // 设备经验参数
    flueGasSystem::Yfan = 0.85;
    so2AbsorbSystem::Yyang = 0.6;
    so2AbsorbSystem::Yjxb = 0.86;
    so2AbsorbSystem::Yshpb = 0.5;
    so2AbsorbSystem::Hshpb = 40;

    caso4ExtractH2Osystem::Dlb = 1.8;
    caso4ExtractH2Osystem::Hlb = 1.5;
    caso4ExtractH2Osystem::Tlx = 0.5;
    caso4ExtractH2Osystem::Ylx = 0.9;
    caso4ExtractH2Osystem::HDlx = 1.2;
    caso4ExtractH2Osystem::Ylyb = 0.45;
    caso4ExtractH2Osystem::Hlyb = 35;

    slurryPreSystem::Tshc = 60;
    slurryPreSystem::NUMshc = 1;
    slurryPreSystem::Yshc = 0.9;
    slurryPreSystem::Ashc = 55;
    slurryPreSystem::Tsjx = 0.1;
    slurryPreSystem::Ysjx = 0.9;
    slurryPreSystem::HDsjx = 1.2;
    slurryPreSystem::Yshjxb = 0.45;
    slurryPreSystem::Hshjxb = 40;
    slurryPreSystem::Tsj = 6;
    slurryPreSystem::Ysj = 0.9;
    slurryPreSystem::HDsj = 1.2;
    slurryPreSystem::Yshjb = 0.45;
    slurryPreSystem::Hshjb = 35;

    processH2Osystem::Tgy = 0.5;
    processH2Osystem::Ygy = 0.9;
    processH2Osystem::HDgy = 1.2;
    processH2Osystem::Ygyb = 0.65;
    processH2Osystem::Hgyb = 65;
    processH2Osystem::Yccb = 0.65;
    processH2Osystem::Qccb = 150;
    processH2Osystem::Hccb = 65;

    emergencySlurrySystem::Yshg = 0.9;
    emergencySlurrySystem::HDshg = 1.2;
    emergencySlurrySystem::Yshgb = 0.55;
    emergencySlurrySystem::Hshgb = 30;
    emergencySlurrySystem::Yshgb = 0.55;
    emergencySlurrySystem::Hshgb = 30;

    wasteH2OproSystem::Yfshb = 0.3;
    wasteH2OproSystem::Hfshb = 35;

    //
    pinfPar::ss = "0010100";

    // GAS


}


