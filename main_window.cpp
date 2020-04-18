#include "main_window.h"
#include "central_widget.h"

setCoalParThread::setCoalParThread(int prid):prid(prid){}



void setCoalParThread::run()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    QString dsn = "DRIVER={SQL SERVER};SERVER=" + Login_window::ip + ";DATABASE=p;"
            "UID=sa;PWD=123456;";
    db.setDatabaseName(dsn);

    if(!db.open())                                      //打开数据库
    {
//        QMessageBox::information(this, tr("连接结果"), tr("数据库连接失败"));
    }
    else
    {
        QSqlQuery query(db); //查询Card表并输出，测试能否正常操作数据库
        QString pd = QString::number(this->prid);
        QString sqlprojects = "SELECT * FROM projects WHERE prid=" + pd;
        QString sqlPinf = "SELECT * FROM Pinf WHERE prid=" + pd;
        QString sqlGasResult = "SELECT * FROM GasResult WHERE prid=" + pd;
        QString sqlGSLResult = "SELECT * FROM GSLResult WHERE prid=" + pd;
        QString sqlEquip = "SELECT * FROM Equip WHERE prid=" + pd;
        QString sqlCoal = "SELECT * FROM Coal WHERE prid=" + pd;
        query.exec(sqlCoal);
        if (query.next()){
            qDebug() << "煤气参数 = "<<query.value(0).toString();
            Coal::setCoalPar(query.value(0).toFloat(), query.value(1).toFloat(),
                             query.value(2).toFloat(), query.value(3).toFloat(),
                             query.value(4).toFloat(), query.value(5).toFloat(),
                             query.value(6).toFloat(), query.value(7).toFloat(),
                             query.value(8).toFloat());
            qDebug() << "煤气参数 = "<<Coal::Ap << Coal::S;
        }
//        query.exec(sqlEquip);
//        if (query.next()){
//            std::cout << query.value(0).toString().toStdString()<< query.value(1).toString().toStdString()<<
//                        query.value(2).toString().toStdString();
                    //                               query.value(3).toString().toStdString()
//            Equip::setEquipPar(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString());
//            Equip::setEquipPar(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString(),
//                               query.value(3).toString().toStdString(), query.value(4).toString().toStdString(),
//                               query.value(5).toString().toStdString(), query.value(6).toString().toStdString(),
//                               query.value(7).toString().toStdString(), query.value(8).toString().toStdString(),
//                               query.value(9).toString().toStdString(), query.value(10).toString().toStdString(),
//                               query.value(11).toString().toStdString(), query.value(12).toString().toStdString(),
//                               query.value(13).toString().toStdString(), query.value(14).toString().toStdString(),
//                               query.value(15).toString().toStdString(), query.value(16).toString().toStdString(),
//                               query.value(17).toString().toStdString(), query.value(18).toString().toStdString(),
//                               query.value(19).toString().toStdString(), query.value(20).toString().toStdString(),
//                               query.value(21).toString().toStdString(), query.value(22).toString().toStdString(),
//                               query.value(23).toString().toStdString(), query.value(24).toString().toStdString(),
//                               query.value(25).toString().toStdString(), query.value(26).toString().toStdString(),
//                               query.value(27).toString().toStdString(), query.value(28).toString().toStdString(),
//                               query.value(29).toString().toStdString(), query.value(30).toString().toStdString(),
//                               query.value(31).toString().toStdString());
//        std::cout << "EQ1 = " << Equip::eq1;

//        }

    }
    db.close();

}


setEquipParThread::setEquipParThread(int prid):prid(prid){}
setEquipParThread::~setEquipParThread(){}

void setEquipParThread::run()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    QString dsn = "DRIVER={SQL SERVER};SERVER=" + Login_window::ip + ";DATABASE=p;"
            "UID=sa;PWD=123456;";
    db.setDatabaseName(dsn);

    if(!db.open())                                      //打开数据库
    {
//        QMessageBox::information(this, tr("连接结果"), tr("数据库连接失败"));
    }
    else
    {
        QSqlQuery query(db); //查询Card表并输出，测试能否正常操作数据库
        QString pd = QString::number(this->prid);
//        QString sqlprojects = "SELECT * FROM projects WHERE prid=" + pd;
//        QString sqlPinf = "SELECT * FROM Pinf WHERE prid=" + pd;
//        QString sqlGasResult = "SELECT * FROM GasResult WHERE prid=" + pd;
//        QString sqlGSLResult = "SELECT * FROM GSLResult WHERE prid=" + pd;
        QString sqlEquip = "SELECT * FROM Equip WHERE prid=" + pd;
        query.exec(sqlEquip);
        if (query.next()){
//            Equip::setEquipPar(query);
//            std::cout << "size = " << query.size();
            qDebug() << query.value(0).toString()<< query.value(1).toString()<<
                        query.value(2).toString();
                    //                               query.value(3).toString().toStdString()
//            Equip::setEquipPar(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString());
//            Equip::setEquipPar(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString(),
//                               query.value(3).toString().toStdString(), query.value(4).toString().toStdString(),
//                               query.value(5).toString().toStdString(), query.value(6).toString().toStdString(),
//                               query.value(7).toString().toStdString(), query.value(8).toString().toStdString(),
//                               query.value(9).toString().toStdString(), query.value(10).toString().toStdString(),
//                               query.value(11).toString().toStdString(), query.value(12).toString().toStdString(),
//                               query.value(13).toString().toStdString(), query.value(14).toString().toStdString(),
//                               query.value(15).toString().toStdString(), query.value(16).toString().toStdString(),
//                               query.value(17).toString().toStdString(), query.value(18).toString().toStdString(),
//                               query.value(19).toString().toStdString(), query.value(20).toString().toStdString(),
//                               query.value(21).toString().toStdString(), query.value(22).toString().toStdString(),
//                               query.value(23).toString().toStdString(), query.value(24).toString().toStdString(),
//                               query.value(25).toString().toStdString(), query.value(26).toString().toStdString(),
//                               query.value(27).toString().toStdString(), query.value(28).toString().toStdString(),
//                               query.value(29).toString().toStdString(), query.value(30).toString().toStdString(),
//                               query.value(31).toString().toStdString());
//        std::cout << "EQ1 = " << Equip::eq1;

        }

    }
    db.close();

}



void MainWindow::createAction()
{

    //    file menu

    this->newAction = new QAction(QIcon("/icon/new.ico"), tr("新建项目"), this);
    this->newAction->setShortcut(tr("Ctrl+N"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newSLOT()));

    this->openAction = new QAction(QIcon("1.jpg"), tr("打开项目"), this);
    this->openAction->setShortcut(tr("Ctrl+O"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openSLOT()));

    this->saveAction = new QAction(tr("保存项目"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveSLOT()));

    this->submitCheckingAction = new QAction(tr("提交校审"), this);

    this->checkingProjectAction = new QAction(tr("校核项目"), this);
    connect(checkingProjectAction, SIGNAL(triggered()), this, SLOT(checkSLOT()));

    this->reviewProjectAction = new QAction(tr("审核项目"), this);
    this->checkOpinionAction = new QAction(tr("校核意见"), this);

    this->closeAction = new QAction(tr("关闭"), this);
    connect(closeAction , SIGNAL(triggered()), this, SLOT(close()));

    //    setting menu

    this->systemSettingAction = new QAction(tr("系统配置选择"), this);
    this->proccessGenratorAction = new QAction(tr("流程图生成"), this);

    //    parameter input menu

    this->inputParAction = new QAction(tr("输入参数"), this);
    this->coalQualityCalculationAction = new QAction(tr("辅助煤质计算"), this);

    //    equipment menu

    this->absorberParAction = new QAction(tr("吸收塔参数"), this);
    this->boosterFanAction = new QAction(tr("增压风机"), this);
    this->heatExchangerAction = new QAction(tr("烟气换热器"), this);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->oxidationAirBlowerAction = new QAction(tr("氧化风机"), this);
    this->slurryCirculationPumpAction = new QAction(tr("浆液循环泵"), this);
    this->absorberAgitatorAction = new QAction(tr("吸收塔搅拌器"), this);
    this->caso4DischargePumpAction = new QAction(tr("石膏排出泵"), this);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->caso4RotationalFlowAction = new QAction(tr("石膏旋流器"), this);
    this->vacuumBeltDehydratorAction = new QAction(tr("真空皮带脱水机"), this);
    this->filterTankAndAgitatorAction = new QAction(tr("滤液箱机搅拌器"), this);
    this->filterPumpAction = new QAction(tr("滤液泵"), this);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->caco3HouseAction = new QAction(tr("石灰石仓"), this);
    this->wetBallMillAction = new QAction(tr("湿式球磨机"), this);
    this->caco3CirculantTankAndAgitatorAction = new QAction(tr("石灰石浆液循环箱及搅拌器"));
    this->caco3CirculantPumpAction= new QAction(tr("石灰石浆液循环泵"));
    this->caco3RotationalFlowAction = new QAction(tr("石灰石旋流器"));
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->caco3PowderHouseAction = new QAction(tr("石灰石粉仓"));
    this->caco3SlurryTankAndAgitatorAction = new QAction(tr("石灰石浆液箱及搅拌器"));
    this->caco3SlurryPumpAction = new QAction(tr("石灰石浆液泵"));
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->processWaterTankAction = new QAction(tr("工艺水箱"));
    this->processWaterPumpAction = new QAction(tr("工艺水泵"));
    this->waterPumpAction = new QAction(tr("除雾器冲洗水泵"));
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->emergencySlurryTankAndAgitatorAction = new QAction(tr("事故浆液箱及搅拌器"));
    this->emergencySlurryPumpAction = new QAction(tr("事故浆液箱泵"));
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->wasteH2OrotationalFlowAction = new QAction(tr("废水旋流器"));
    this->wasteH2OfeedAction = new QAction(tr("废水旋流器给料泵"));
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->equipmentParSetAction = new QAction(tr("设备参数汇总"));

    //    data process menu

    this->balanceAction = new QAction(tr("物料平衡计算结果"));
    this->curveAction = new QAction(tr("性能曲线"));

    //    System arrangement menu

    this->changePasswordAction = new QAction(tr("修改密码"));
    this->usrArrangeAction = new QAction(tr("用户管理"));
    this->projectArrangeAction = new QAction(tr("项目管理"));
    this->usageRecordAction = new QAction(tr("使用记录"));
    this->experParAction = new QAction(tr("经验参数"));

    //    System arrangement menu

    this->helpAction = new QAction(tr("帮助"));
    this->aboutAction = new QAction(tr("关于"));
    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(aboutSLOT()));

}

void MainWindow::createMenus()
{

    //    file menu

    this->filemenu = menuBar()->addMenu(tr("项目管理"));
    this->filemenu->addAction(this->newAction);
    this->filemenu->addAction(this->openAction);
    this->filemenu->addAction(this->saveAction);
    this->filemenu->addSeparator();
    this->filemenu->addAction(this->submitCheckingAction);
    this->filemenu->addAction(this->checkingProjectAction);
    this->filemenu->addAction(this->reviewProjectAction);
    this->filemenu->addAction(this->checkOpinionAction);
    this->filemenu->addSeparator();
    this->filemenu->addAction(this->closeAction);

    //    setting menu

    this->settingmenu = menuBar()->addMenu(tr("系统配置"));
    this->settingmenu->addAction(this->systemSettingAction);
    this->settingmenu->addAction(this->proccessGenratorAction);

    //    parameter input menu

    this->inputmenu = menuBar()->addMenu(tr("参数输入"));
    this->inputmenu->addAction(this->inputParAction);
    this->inputmenu->addAction(this->coalQualityCalculationAction);

    //    equipment menu

    this->equipmentmenu= menuBar()->addMenu(tr("设备参数"));
    this->equipmentmenu->addAction(this->absorberParAction);
    
    this->smokeSystemmenu = new QMenu("烟气系统");
    this->smokeSystemmenu->addAction(this->boosterFanAction);
    this->smokeSystemmenu->addAction(this->heatExchangerAction);
    this->equipmentmenu->addMenu(this->smokeSystemmenu);
    
    this->so2AbsorbSystemmenu = new QMenu("SO2吸收系统");
    this->so2AbsorbSystemmenu ->addAction(this->oxidationAirBlowerAction);
    this->so2AbsorbSystemmenu ->addAction(this->slurryCirculationPumpAction);
    this->so2AbsorbSystemmenu ->addAction(this->absorberAgitatorAction);
    this->so2AbsorbSystemmenu ->addAction(this->caso4DischargePumpAction);
    this->equipmentmenu->addMenu(this->so2AbsorbSystemmenu );
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->caso4DehydrationSystemmenu = new QMenu("石膏脱水系统");
    this->caso4DehydrationSystemmenu->addAction(this->caso4RotationalFlowAction);
    this->caso4DehydrationSystemmenu->addAction(this->vacuumBeltDehydratorAction);
    this->caso4DehydrationSystemmenu->addAction(this->filterTankAndAgitatorAction);
    this->caso4DehydrationSystemmenu->addAction(this->filterPumpAction);
    this->equipmentmenu->addMenu(this->caso4DehydrationSystemmenu);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->wetPulpingSystemmenu = new QMenu("湿式制浆系统");
    this->wetPulpingSystemmenu->addAction(this->caco3HouseAction);
    this->wetPulpingSystemmenu->addAction(this->wetBallMillAction);
    this->wetPulpingSystemmenu->addAction(this->caco3CirculantTankAndAgitatorAction);
    this->wetPulpingSystemmenu->addAction(this->caco3CirculantPumpAction);
    this->wetPulpingSystemmenu->addAction(this->caco3RotationalFlowAction);
    this->equipmentmenu->addMenu(this->wetPulpingSystemmenu);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->powderPulpingSystemmenu = new QMenu("粉制浆系统");
    this->powderPulpingSystemmenu ->addAction(this->caco3PowderHouseAction);
    this->powderPulpingSystemmenu ->addAction(this->caco3SlurryTankAndAgitatorAction);
    this->powderPulpingSystemmenu ->addAction(this->caco3SlurryPumpAction);
    this->equipmentmenu->addMenu(this->powderPulpingSystemmenu);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->processWaterSystemmenu = new QMenu("工艺水系统");
    this->processWaterSystemmenu->addAction(this->processWaterTankAction);
    this->processWaterSystemmenu->addAction(this->processWaterPumpAction);
    this->processWaterSystemmenu->addAction(this->waterPumpAction);
    this->equipmentmenu->addMenu(this->processWaterSystemmenu);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->emergencySlurrySystemmenu = new QMenu(tr("事故浆液系统"));
    this->emergencySlurrySystemmenu->addAction(emergencySlurryTankAndAgitatorAction);
    this->emergencySlurrySystemmenu->addAction(emergencySlurryPumpAction);
    this->equipmentmenu->addMenu(this->emergencySlurrySystemmenu);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->wasterH2Osystemmenu = new QMenu(tr("废水处理系统"));
    this->wasterH2Osystemmenu->addAction(wasteH2OrotationalFlowAction);
    this->wasterH2Osystemmenu->addAction(wasteH2OfeedAction);
    this->equipmentmenu->addMenu(this->wasterH2Osystemmenu);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->equipmentmenu->addAction(this->equipmentParSetAction);


    //    data process menu

    this->dataProcessMenu = menuBar()->addMenu(tr("数据分析"));
    this->dataProcessMenu->addAction(this->balanceAction);
    this->dataProcessMenu->addAction(this->curveAction);

    //    System arrangement menu

    this->systemArrangeMenu = menuBar()->addMenu(tr("系统管理"));
    this->systemArrangeMenu->addAction(this->changePasswordAction);
    this->systemArrangeMenu->addAction(this->usrArrangeAction);
    this->systemArrangeMenu->addAction(this->projectArrangeAction);
    this->systemArrangeMenu->addAction(this->usageRecordAction);
    this->systemArrangeMenu->addAction(this->experParAction);

    //    Help menu

    this->helpMenu = menuBar()->addMenu((tr("帮助")));
    this->helpMenu->addAction(this->helpAction);
    this->helpMenu->addAction(this->aboutAction);

};


void MainWindow::createToolBars()
{
    this->fileTool = this->addToolBar("File");
    this->fileTool->addAction(this->newAction);
    this->fileTool->addAction(this->openAction);
    this->fileTool->addAction(this->saveAction);
    this->inputTool = this->addToolBar("Input");
    this->inputTool->addAction(this->systemSettingAction);
    this->inputTool->addAction(this->inputParAction);
    this->inputTool->addAction(this->equipmentParSetAction);
    this->outputTool = this->addToolBar("Output");
    this->outputTool->addAction(this->balanceAction);
    this->outputTool->addAction(this->curveAction);
}


void MainWindow::newSLOT()
{
    if (newPjWindow::num == 0)
        this->newWindow = new newPjWindow;
    else{
        this->newWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->newWindow->show();
    }
}

void MainWindow::openSLOT()
{
    if (openPjWindow::num == 0)
    {
        this->openProjectwindow = new openPjWindow;
        connect(openProjectwindow, SIGNAL(pridSIGNAL(int)), this, SLOT(setParSLOT(int)));
    }
    else{
        this->openProjectwindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->openProjectwindow->show();
    }
}

void MainWindow::setParSLOT(int prid)
{
    if (dbUtils::ping(Login_window::ip)==0){
        setEquipThread = new setEquipParThread(prid);
        setEquipThread->start();
    }
    else
        QMessageBox::information(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
}



void MainWindow::saveSLOT()
{
    switch(QMessageBox::question(this, tr("保存项目"), tr("是否确定保存该项目？"),
                                 QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
    
    {
    case QMessageBox::Ok:
        QMessageBox::information(this, tr("保存结果"), tr("保存成功"));
        break;
    case QMessageBox::Cancel:
        break;
    default:
        break;   
    }
    return;
}

void MainWindow::checkSLOT()
{
    if (checkPjWindow::num == 0)
        this->checkOpinionWindow = new checkPjWindow;
    else{
        this->checkOpinionWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->checkOpinionWindow->show();
    }
}

void MainWindow::aboutSLOT()
{
    if (about_window::num == 0)
        this->aboutWindow = new about_window;
    else{
        this->aboutWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->aboutWindow->show();
    }
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->loginWindow = new Login_window(this);


    connect(loginWindow, SIGNAL(connectSIGNAL()), this, SLOT(show()));
    connect(loginWindow, SIGNAL(connectSIGNAL()), loginWindow, SLOT(close()));


    this->resize(1000, 800);
    this->setWindowTitle(tr("湿法烟气脱硫系统"));
    CentralWidget *central_widget = new CentralWidget(this);
    this->setCentralWidget(central_widget);
    this->createAction();
    this->createMenus();
    this->createToolBars();

}

MainWindow::~MainWindow()
{

}
