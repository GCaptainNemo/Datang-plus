#include "main_window.h"
#include "widget_central.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

int MainWindow::first = 0;

void MainWindow::closeEvent(QCloseEvent *event)
{
    switch(QMessageBox::question(this, tr("关闭窗口"), tr("你还未保存，确定要退出程序？"),
                                 QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes))

    {
    case QMessageBox::Yes:{
        event->accept();
        break;
    }
    case QMessageBox::No:
        event->ignore();
        break;
    default:
        break;
    }
    return;

    qDebug() << "I am closing!";
}


void MainWindow::createAction()
{

    //    file menu

    this->newAction = new QAction(QIcon("..//FML//icon//new.ico"), tr("新建项目"), this);
    this->newAction->setShortcut(tr("Ctrl+N"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newSLOT()));

    this->openAction = new QAction(QIcon("..//FML//icon//open.ico"), tr("打开项目"), this);
    this->openAction->setShortcut(tr("Ctrl+O"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openSLOT()));

    this->saveAction = new QAction(QIcon("..//FML//icon//save.bmp"), tr("保存项目"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveSLOT()));

    this->submitCheckingAction = new QAction(tr("提交校审"), this);
    connect(submitCheckingAction, SIGNAL(triggered(bool)), this, SLOT(submitCheckingSLOT()));


    this->checkingProjectAction = new QAction(tr("校核项目"), this);
    connect(checkingProjectAction, SIGNAL(triggered()), this, SLOT(checkProjectSLOT()));

    this->verifyProjectAction = new QAction(tr("审核项目"), this);
    connect(verifyProjectAction, SIGNAL(triggered()), this, SLOT(verifyProjectSLOT()));

    this->checkOpinionAction = new QAction(tr("校审意见"), this);
    connect(checkOpinionAction, SIGNAL(triggered(bool)), this, SLOT(checkOpinionSLOT()));


    this->closeAction = new QAction(tr("关闭"), this);
    connect(closeAction , SIGNAL(triggered()), this, SLOT(close()));

    //    setting menu

    this->systemSettingAction = new QAction(QIcon("..//FML//icon//setting.ico"), tr("系统配置选择"), this);
    connect(systemSettingAction, SIGNAL(triggered(bool)), this, SLOT(configureSystemSLOT()));
    this->createPdfAction = new QAction(tr("流程图生成"), this);
    connect(createPdfAction, SIGNAL(triggered(bool)), this, SLOT(createPdfSLOT()));
    //    parameter input menu

    this->inputParAction = new QAction(QIcon("..//FML//icon//input.ico"), tr("输入参数"), this);
    connect(inputParAction, SIGNAL(triggered(bool)), this, SLOT(inputParSLOT()));
    this->coalQualityCalculationAction = new QAction(tr("辅助煤质计算"), this);

    //    equipment menu

    this->absorberParAction = new QAction(tr("吸收塔参数"), this);
    this->pressureAirBlowerAction = new QAction(tr("增压风机"), this);
    connect(pressureAirBlowerAction, SIGNAL(triggered(bool)), this, SLOT(pressureAirBlowerSLOT()));
    this->heatExchangerAction = new QAction(tr("烟气换热器"), this);
    connect(heatExchangerAction, SIGNAL(triggered(bool)), this, SLOT(heatExchangeSLOT()));
     //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->oxidationAirBlowerAction = new QAction(tr("氧化风机"), this);
    connect(oxidationAirBlowerAction, SIGNAL(triggered(bool)), this, SLOT(oxidationAiBlowerSLOT()));
    this->slurryCirculationPumpAction = new QAction(tr("浆液循环泵"), this);
    connect(slurryCirculationPumpAction, SIGNAL(triggered(bool)), this, SLOT(absorberSryCirPumpSLOT()));


    this->caso4DischargePumpAction = new QAction(tr("石膏排出泵"), this);
    connect(caso4DischargePumpAction, SIGNAL(triggered(bool)), this, SLOT(caso4DischargePumpSLOT()));

    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->caso4RotationalFlowAction = new QAction(tr("石膏旋流器"), this);
    connect(caso4RotationalFlowAction, SIGNAL(triggered(bool)), this, SLOT(caso4RotationalFlowSLOT()));

    this->vacuumBeltDehydratorAction = new QAction(tr("真空皮带脱水机"), this);
    connect(vacuumBeltDehydratorAction, SIGNAL(triggered(bool)), this, SLOT(vacuumBeltDeWindowSLOT()));

    this->filterTankAndAgitatorAction = new QAction(tr("滤液箱及搅拌器"), this);
    connect(filterTankAndAgitatorAction, SIGNAL(triggered(bool)), this, SLOT(filterSryAndAgitatorSLOT()));
    this->filterPumpAction = new QAction(tr("滤液泵"), this);
    connect(filterPumpAction, SIGNAL(triggered(bool)), this, SLOT(filterPumpSLOT()));


    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->caco3HouseAction = new QAction(tr("石灰石仓"), this);
    connect(caco3HouseAction, SIGNAL(triggered(bool)), this, SLOT(caco3HouseSLOT()));
    this->wetBallMillAction = new QAction(tr("湿式球磨机"), this);
    connect(wetBallMillAction, SIGNAL(triggered(bool)), this, SLOT(wetMillSLOT()));

    this->caco3CirculantTankAndAgitatorAction = new QAction(tr("石灰石浆液循环箱及搅拌器"), this);
    connect(caco3CirculantTankAndAgitatorAction, SIGNAL(triggered(bool)), this, SLOT(caco3SryCirAndAgitatorSLOT()));
    this->caco3SlurryCirculantPumpAction= new QAction(tr("石灰石浆液循环泵"), this);
    connect(caco3SlurryCirculantPumpAction, SIGNAL(triggered(bool)), this, SLOT(caco3SryPumpCirSLOT()));


    this->caco3RotationalFlowAction = new QAction(tr("石灰石旋流器"), this);
    connect(caco3RotationalFlowAction, SIGNAL(triggered(bool)), this, SLOT(caco3RotationalFlowSLOT()));
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->caco3PowderHouseAction = new QAction(tr("石灰石粉仓"), this);
    this->caco3SlurryTankAndAgitatorAction = new QAction(tr("石灰石浆液箱及搅拌器"), this);
    connect(caco3SlurryTankAndAgitatorAction, SIGNAL(triggered(bool)), this, SLOT(caco3SryAndAgitatorSLOT()));
    this->caco3SlurryPumpAction = new QAction(tr("石灰石浆液泵"), this);
    connect(caco3SlurryPumpAction, SIGNAL(triggered(bool)), this, SLOT(caco3SryPumpSLOT()));

    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->processWaterTankAction = new QAction(tr("工艺水箱"), this);
    connect(processWaterTankAction, SIGNAL(triggered(bool)), this, SLOT(proH2OtankSLOT()));
    this->processWaterPumpAction = new QAction(tr("工艺水泵"), this);
    connect(processWaterPumpAction, SIGNAL(triggered(bool)), this, SLOT(proH2OpumpSLOT()));

    this->waterPumpAction = new QAction(tr("除雾器冲洗水泵"), this);
    connect(waterPumpAction, SIGNAL(triggered(bool)), this, SLOT(waterPumpSLOT()));
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->emergencySlurryTankAndAgitatorAction = new QAction(tr("事故浆液箱及搅拌器"), this);
    connect(emergencySlurryTankAndAgitatorAction, SIGNAL(triggered(bool)), this, SLOT(emergencySryAndAgitatorSLOT()));

    this->emergencySlurryPumpAction = new QAction(tr("事故浆液箱泵"), this);
    connect(emergencySlurryPumpAction, SIGNAL(triggered(bool)), this, SLOT(emergencySryPumpSLOT()));

    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->wasteH2OrotationalFlowAction = new QAction(tr("废水旋流器"), this);
    connect(wasteH2OrotationalFlowAction, SIGNAL(triggered(bool)), this, SLOT(wasteH2OrotationalFlowSLOT()));
    this->wasteH2OfeedAction = new QAction(tr("废水旋流器给料泵"), this);
    connect(wasteH2OfeedAction, SIGNAL(triggered(bool)), this, SLOT(wasteH2oFeedPumpSLOT()));
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->equipmentParSetAction = new QAction(QIcon("..//FML//icon//equip.ico"), tr("设备参数汇总"), this);
    connect(equipmentParSetAction, SIGNAL(triggered(bool)), this, SLOT(equipmentParSetSLOT()));

    //    data process menu

    this->balanceDataAction = new QAction(QIcon("..//FML//icon//data.ico"), tr("物料平衡计算结果"), this);
    connect(balanceDataAction, SIGNAL(triggered(bool)), this, SLOT(balanceDataSLOT()));

    this->curveAction = new QAction(QIcon("..//FML//icon//curve.ico"), tr("性能曲线"), this);

    //    System arrangement menu

    this->changePasswordAction = new QAction(tr("修改密码"), this);
    connect(changePasswordAction, SIGNAL(triggered(bool)), this, SLOT(passwordManageSLOT()));
    this->usrManageAction = new QAction(tr("用户管理"), this);
    connect(usrManageAction, SIGNAL(triggered(bool)), this, SLOT(userManageSLOT()));

    this->projectManageAction = new QAction(tr("项目管理"), this);
    connect(projectManageAction, SIGNAL(triggered(bool)), this, SLOT(projectManageSLOT()));


    this->usageRecordAction = new QAction(tr("使用记录"), this);
    connect(usageRecordAction, SIGNAL(triggered(bool)), this, SLOT(recordsManageSLOT()));

    this->experParAction = new QAction(tr("经验参数"), this);
    connect(experParAction, SIGNAL(triggered(bool)), this, SLOT(experienceParManageSLOT()));


    //    System arrangement menu

    this->helpAction = new QAction(tr("帮助"), this);
    this->aboutAction = new QAction(tr("关于"), this);
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
    this->filemenu->addAction(this->verifyProjectAction);
    this->filemenu->addAction(this->checkOpinionAction);
    this->filemenu->addSeparator();
    this->filemenu->addAction(this->closeAction);

    //    setting menu

    this->settingmenu = menuBar()->addMenu(tr("系统配置"));
    this->settingmenu->addAction(this->systemSettingAction);
    this->settingmenu->addAction(this->createPdfAction);

    //    parameter input menu


    this->inputmenu = menuBar()->addMenu(tr("参数输入"));
    this->inputmenu->addAction(this->inputParAction);
    this->inputmenu->addAction(this->coalQualityCalculationAction);

    //    equipment menu

    this->equipmentmenu= menuBar()->addMenu(tr("设备参数"));
    this->equipmentmenu->addAction(this->absorberParAction);

    this->smokeSystemmenu = this->equipmentmenu->addMenu(tr("烟气系统"));
    this->smokeSystemmenu->addAction(this->pressureAirBlowerAction);
    this->smokeSystemmenu->addAction(this->heatExchangerAction);


    this->so2AbsorbSystemmenu = this->equipmentmenu->addMenu(tr("SO2吸收系统"));
    this->so2AbsorbSystemmenu ->addAction(this->oxidationAirBlowerAction);
    this->so2AbsorbSystemmenu ->addAction(this->slurryCirculationPumpAction);
    this->so2AbsorbSystemmenu ->addAction(this->caso4DischargePumpAction);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->caso4DehydrationSystemmenu = this->equipmentmenu->addMenu(tr("石膏脱水系统"));
    this->caso4DehydrationSystemmenu->addAction(this->caso4RotationalFlowAction);
    this->caso4DehydrationSystemmenu->addAction(this->vacuumBeltDehydratorAction);
    this->caso4DehydrationSystemmenu->addAction(this->filterTankAndAgitatorAction);
    this->caso4DehydrationSystemmenu->addAction(this->filterPumpAction);

    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->wetPulpingSystemmenu = this->equipmentmenu->addMenu(tr("湿式制浆系统"));
    this->wetPulpingSystemmenu->addAction(this->caco3HouseAction);
    this->wetPulpingSystemmenu->addAction(this->wetBallMillAction);
    this->wetPulpingSystemmenu->addAction(this->caco3CirculantTankAndAgitatorAction);
    this->wetPulpingSystemmenu->addAction(this->caco3SlurryCirculantPumpAction);
    this->wetPulpingSystemmenu->addAction(this->caco3RotationalFlowAction);

    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->powderPulpingSystemmenu = this->equipmentmenu->addMenu(tr("粉制浆系统"));
    this->powderPulpingSystemmenu ->addAction(this->caco3PowderHouseAction);
    this->powderPulpingSystemmenu ->addAction(this->caco3SlurryTankAndAgitatorAction);
    this->powderPulpingSystemmenu ->addAction(this->caco3SlurryPumpAction);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->processWaterSystemmenu = this->equipmentmenu->addMenu(tr("工艺水系统"));
    this->processWaterSystemmenu->addAction(this->processWaterTankAction);
    this->processWaterSystemmenu->addAction(this->processWaterPumpAction);
    this->processWaterSystemmenu->addAction(this->waterPumpAction);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->emergencySlurrySystemmenu = this->equipmentmenu->addMenu(tr("事故浆液系统"));
    this->emergencySlurrySystemmenu->addAction(emergencySlurryTankAndAgitatorAction);
    this->emergencySlurrySystemmenu->addAction(emergencySlurryPumpAction);

    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    this->wasteH2Osystemmenu = this->equipmentmenu->addMenu(tr("废水处理系统"));
    this->wasteH2Osystemmenu->addAction(wasteH2OrotationalFlowAction);
    this->wasteH2Osystemmenu->addAction(wasteH2OfeedAction);
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    this->equipmentmenu->addAction(this->equipmentParSetAction);


    //    data process menu

    this->dataProcessMenu = menuBar()->addMenu(tr("数据分析"));
    this->dataProcessMenu->addAction(this->balanceDataAction);
    this->dataProcessMenu->addAction(this->curveAction);

    //    System arrangement menu

    this->systemArrangeMenu = menuBar()->addMenu(tr("系统管理"));
    this->systemArrangeMenu->addAction(this->changePasswordAction);
    this->systemArrangeMenu->addAction(this->usrManageAction);
    this->systemArrangeMenu->addAction(this->projectManageAction);
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
    this->outputTool->addAction(this->balanceDataAction);
    this->outputTool->addAction(this->curveAction);
}



void MainWindow::createPdfSLOT()
{
    switch(QMessageBox::question(this, tr("导出PDF图"), tr("确定将此流程图导出？"),
                                 QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))

    {
    case QMessageBox::Ok:{
        QString a = "..\\FML\\dwg2PDF\\" ;
        QString b = ".pdf";
        QString qtManulFile = a + pinfPar::ss.left(5) + b;
        qDebug() << qtManulFile;
        QDesktopServices::openUrl(QUrl::fromLocalFile(qtManulFile));
        break;
    }
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }
    return;

}


void MainWindow::configureSystemSLOT()
{
    if (systemConfigurationWindow::num == 0){
        this->sysConfigWindow = new systemConfigurationWindow(this);
    }
    else{
        this->sysConfigWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->sysConfigWindow->showNormal();
    }
}

void MainWindow::experienceParManageSLOT()
{
    if (window_manage_experience_par::num == 0){
        this->manageExpParWindow = new window_manage_experience_par(this);
    }
    else{
        this->manageExpParWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->manageExpParWindow->showNormal();
    }

}


void MainWindow::balanceDataSLOT()
{
    if (window_total_calculationresult::num == 0){
        this->calculationReslutTotalWindow = new window_total_calculationresult(this);
    }
    else{
        this->calculationReslutTotalWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->calculationReslutTotalWindow->showMaximized();
    }
}


void MainWindow::equipmentParSetSLOT()
{
    if (window_total_equipment_parameter::num == 0){
        this->equipmentParTotalWindow = new window_total_equipment_parameter(this);
    }
    else{
        this->equipmentParTotalWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->equipmentParTotalWindow->showMaximized();
    }
}




void MainWindow::userManageSLOT()
{
    if (window_manage_user::num == 0){
        this->manageUsrWindow = new window_manage_user(this);
    }
    else{
        this->manageUsrWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->manageUsrWindow->showNormal();
    }
}

void MainWindow::recordsManageSLOT()
{
    if (manageaRecordsWindow::num == 0){
        this->manageRecWindow = new manageaRecordsWindow(this);
    }
    else{
        this->manageRecWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->manageRecWindow->showNormal();
    }
}

void MainWindow::passwordManageSLOT()
{
    qDebug() << "window_manage_password::num = " << window_manage_password::num;
    if (window_manage_password::num == 0){
        this->managePwWindow = new window_manage_password(this);
    }
    else{
        this->managePwWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->managePwWindow->showNormal();
    }
}

void MainWindow::projectManageSLOT()
{
    if (manageProjectWindow::num == 0){
        this->managePjWindow = new manageProjectWindow(this);
    }
    else{
        this->managePjWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->managePjWindow->showNormal();
    }
}




void MainWindow::setLimitSLOT(QString usrlimit)
{
    qDebug() << "in设计";
    qDebug() << "otherPar::userLimit";
    if (usrlimit == "设计")
    {
        qDebug() << "in设计";
        newAction->setEnabled(true);
        openAction->setEnabled(true);
        saveAction->setEnabled(true);
        submitCheckingAction->setEnabled(true);
        closeAction->setEnabled(true);
        checkOpinionAction->setEnabled(false);
        checkingProjectAction->setEnabled(false);
        verifyProjectAction->setEnabled(false);

        changePasswordAction->setEnabled(true);
        usrManageAction->setEnabled(false);
        projectManageAction->setEnabled(false);
        usageRecordAction->setEnabled(false);
        experParAction->setEnabled(false);
    }
    else if(usrlimit == "校核"){
        newAction->setEnabled(true);
        openAction->setEnabled(true);
        saveAction->setEnabled(true);
        submitCheckingAction->setEnabled(true);
        closeAction->setEnabled(true);
        checkOpinionAction->setEnabled(true);
        checkingProjectAction->setEnabled(true);

        verifyProjectAction->setEnabled(false);

        changePasswordAction->setEnabled(true);
        usrManageAction->setEnabled(false);
        projectManageAction->setEnabled(false);
        usageRecordAction->setEnabled(false);
        experParAction->setEnabled(false);
    }
    else if(usrlimit == "审核"){
        newAction->setEnabled(true);
        openAction->setEnabled(true);
        saveAction->setEnabled(true);
        submitCheckingAction->setEnabled(true);
        closeAction->setEnabled(true);
        checkOpinionAction->setEnabled(true);
        checkingProjectAction->setEnabled(true);
        verifyProjectAction->setEnabled(true);

        changePasswordAction->setEnabled(true);
        usrManageAction->setEnabled(false);
        projectManageAction->setEnabled(false);
        usageRecordAction->setEnabled(false);
        experParAction->setEnabled(false);

    }
    else if(usrlimit == "用户管理员"){
        newAction->setEnabled(true);
        openAction->setEnabled(true);
        saveAction->setEnabled(true);
        submitCheckingAction->setEnabled(true);
        closeAction->setEnabled(true);
        checkOpinionAction->setEnabled(true);
        checkingProjectAction->setEnabled(true);
        verifyProjectAction->setEnabled(true);

        changePasswordAction->setEnabled(true);
        usrManageAction->setEnabled(true);
        projectManageAction->setEnabled(true);
        usageRecordAction->setEnabled(true);
        experParAction->setEnabled(true);
    }
}




void MainWindow::inputParSLOT()
{
    if (inputParameterWindow::num == 0){
        this->inputParWindow = new inputParameterWindow(this);
    }
    else{
        this->inputParWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->inputParWindow->showNormal();
    }
}


void MainWindow::caco3SryCirAndAgitatorSLOT()
{
    if (caco3SryCirTankAndAgitatorWindow::num == 0){
        this->caco3SryCirTankAgitatorWindow= new caco3SryCirTankAndAgitatorWindow(
                slurryPreSystem::Qsjx, absorberSystem::FGDnum, slurryPreSystem::Tsjx, slurryPreSystem::Dsjx, slurryPreSystem::Hsjx, slurryPreSystem::HDsjx,  slurryPreSystem::Vjsjx, slurryPreSystem::VTjsjx, slurryPreSystem::Ysjx,
                slurryPreSystem::Nbsjx, slurryPreSystem::Nfsjx, slurryPreSystem::Nesjx, slurryPreSystem::Nksjx, this);
    }
    else{
        this->caco3SryCirTankAgitatorWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->caco3SryCirTankAgitatorWindow->showNormal();
    }
}

void MainWindow::caco3HouseSLOT()
{
    if (caco3HouseWindow::num == 0)
    {
        this->caco3HosWindow = new caco3HouseWindow(this);
    }
    else{
        this->caco3HosWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->caco3HosWindow->showNormal();
    }
}


void MainWindow::wetMillSLOT()
{
    if (wetBallMillWindow::num == 0)
    {
        this->wetMillWindow = new wetBallMillWindow(slurryPreSystem::Qmj, slurryPreSystem::Nfmj, slurryPreSystem::Nemj ,this);
    }
    else{
        this->wetMillWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->wetMillWindow->showNormal();
    }
}


void MainWindow::filterSryAndAgitatorSLOT()
{
    if (filterSryTankAndAgitatorWindow::num == 0)
    {
        this->filterSryTankAgitatorWindow = new filterSryTankAndAgitatorWindow(caso4ExtractH2Osystem::Qlx, absorberSystem::FGDnum, caso4ExtractH2Osystem::Tlx, caso4ExtractH2Osystem::Dlx, caso4ExtractH2Osystem::Hlx, caso4ExtractH2Osystem::HDlx, caso4ExtractH2Osystem::Vjlx, caso4ExtractH2Osystem::VTjlx, caso4ExtractH2Osystem::Ylx,
                caso4ExtractH2Osystem::Nblx, caso4ExtractH2Osystem::Nflx, caso4ExtractH2Osystem::Nelx, caso4ExtractH2Osystem::Nklx, this);
    }
    else{
        this->filterSryTankAgitatorWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->filterSryTankAgitatorWindow->showNormal();
    }
}


void MainWindow::caco3SryAndAgitatorSLOT()
{
    if (caco3SryTankAndAgitatorWindow::num == 0)
        this->caco3SryTankAgitatorWindow= new caco3SryTankAndAgitatorWindow(
                slurryPreSystem::Qsj, absorberSystem::FGDnum, slurryPreSystem::Tsj, slurryPreSystem::Dsj, slurryPreSystem::Hsj, slurryPreSystem::HDsj,  slurryPreSystem::Vjsj, slurryPreSystem::VTjsj, slurryPreSystem::Ysj,
                slurryPreSystem::Nbsj, slurryPreSystem::Nfsj, slurryPreSystem::Nesj, slurryPreSystem::Nksj, this);
    else{
        this->caco3SryTankAgitatorWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->caco3SryTankAgitatorWindow->showNormal();
    }


}


void MainWindow::emergencySryAndAgitatorSLOT()
{
    if (newProjectWindow::num == 0)
        this->emeSryTankAndAgitatorWindow = new emergencySryTankAndAgitatorWindow(
                emergencySlurrySystem::Dshg, emergencySlurrySystem::Hshg, emergencySlurrySystem::HDshg, emergencySlurrySystem::Vshg, emergencySlurrySystem::VTshg, emergencySlurrySystem::Yshg,
                emergencySlurrySystem::Nbshg, emergencySlurrySystem::Nfshg, emergencySlurrySystem::Neshg, emergencySlurrySystem::Nkshg, this);
    else{

        this->emeSryTankAndAgitatorWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->emeSryTankAndAgitatorWindow->showNormal();
    }
}


void MainWindow::newSLOT()
{
    if (newProjectWindow::num == 0)
    {
        this->newWindow = new newProjectWindow(this);
        connect(newWindow, SIGNAL(changeTitleSIGNAL()), this, SLOT(setTitleSLOT()));
    }
    else{
        this->newWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->newWindow->showNormal();
    }
}

void MainWindow::openSLOT()
{
    if (openPjWindow::num == 0)
    {
        qDebug() << "openPj SLOT thread id = " << QThread::currentThreadId();

        this->openProjectwindow = new openPjWindow(this);
        connect(openProjectwindow, SIGNAL(finishedSIGNAL()), this, SLOT(setTitleSLOT()));
    }
    else{
        this->openProjectwindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->openProjectwindow->showNormal();
    }
}


void MainWindow::submitCheckingSLOT()
{
    this->askForCheckingObj = new askForCheckingObject;
    connect(askForCheckingObj, SIGNAL(messageboxShowSIGNAL(int)), this, SLOT(messageboxShowSLOT(int)));
    this->saveObj = new saveObject;
    connect(saveObj, SIGNAL(messageboxShowSIGNAL(int)), this, SLOT(messageboxShowSLOT(int)));

    switch(QMessageBox::question(this, tr("提交校审"), tr("是否保存项目并提交校审项目？"),
                                 QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))

    {
    case QMessageBox::Ok:{
        this->saveObj->start();
        this->askForCheckingObj->start();
        break;
    }
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }
    delete askForCheckingObj;
    delete saveObj;
    return;
}

void MainWindow::setTitleSLOT()
{

    this->setWindowTitle("湿法烟气脱硫系统 - [" + projectPar::pj_name + "]");
    systemConfigurationWindow::pzh = 1;

    MainWindow::first = 1;

}


void MainWindow::wasteH2OrotationalFlowSLOT()
{
    if (wasteH2OrotationalFlow_window::num == 0)
        this->wasteH2OroFlowWindow = new wasteH2OrotationalFlow_window(wasteH2OproSystem::Qfx, wasteH2OproSystem::XZfx, this);
    else{
        this->wasteH2OroFlowWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->wasteH2OroFlowWindow->showNormal();

    }
}

void MainWindow::vacuumBeltDeWindowSLOT()
{
    if (vacuumBeltDehydratorWindow::num == 0)
        this->vacuumBeltDeWindow = new vacuumBeltDehydratorWindow(caso4ExtractH2Osystem::Qzhk,  caso4ExtractH2Osystem::Szhk,  caso4ExtractH2Osystem::Nezhk,
                                                                  caso4ExtractH2Osystem::Qzhb,  caso4ExtractH2Osystem::Nfzhb, caso4ExtractH2Osystem::Nezhb,
                                                                  caso4ExtractH2Osystem::Dlb,   caso4ExtractH2Osystem::Hlb,   caso4ExtractH2Osystem::Vjlb,
                                                                  caso4ExtractH2Osystem::Qlbb,  caso4ExtractH2Osystem::Hlbb,  caso4ExtractH2Osystem::Nelbb, this);
    else{
        this->vacuumBeltDeWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->vacuumBeltDeWindow->showNormal();

    }
}

void MainWindow::heatExchangeSLOT()
{
    if (heatExchangeWindow::num == 0)
        this->heatExWindow = new heatExchangeWindow(this);
    else{
        this->heatExWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->heatExWindow->showNormal();

    }
}


void MainWindow::caso4RotationalFlowSLOT()
{
    if (caso4RotationalFlow_window::num == 0)
        this->caso4RoFlowWindow = new caso4RotationalFlow_window(caso4ExtractH2Osystem::Qshgx, caso4ExtractH2Osystem::XZshgx, this);
    else{
        this->caso4RoFlowWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->caso4RoFlowWindow->showNormal();
    }
}

void MainWindow::caso4DischargePumpSLOT()
{
    if (caso4DischargePumpWindow::num == 0)
        this->caso4DisPumpWindow = new caso4DischargePumpWindow(so2AbsorbSystem::Yshpb, so2AbsorbSystem::Qshpb, so2AbsorbSystem::Hshpb, so2AbsorbSystem::Nfshpb,
                                                                so2AbsorbSystem::Neshpb, so2AbsorbSystem::Nkshpb, this);
    else{
        this->caso4DisPumpWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->caso4DisPumpWindow->showNormal();
    }

}


void MainWindow::proH2OtankSLOT()
{
    if (proH2OtankWindow::num == 0)
    {
        qDebug() << "in PROH2oSLOT";
        this->processH2OtankWindow = new proH2OtankWindow(processH2Osystem::Qgy, absorberSystem::FGDnum, processH2Osystem::Tgy, processH2Osystem::Dgy,
                                                                processH2Osystem::Hgy, processH2Osystem::HDgy,  processH2Osystem::Vjgy, processH2Osystem::VTjgy,  processH2Osystem::Ygy, this);
    }
    else{
        this->processH2OtankWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->processH2OtankWindow->showNormal();
    }
}

void MainWindow::proH2OpumpSLOT()
{
    if (processH2OpumpWindow::num == 0)
        this->proH2OpumpWindow= new processH2OpumpWindow(processH2Osystem::Ygyb, processH2Osystem::Qgyb, processH2Osystem::Hgyb, processH2Osystem::Nfgyb,
                                                                processH2Osystem::Negyb, processH2Osystem::Nkgyb, this);
    else{
        this->proH2OpumpWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->proH2OpumpWindow->showNormal();
    }
}

void MainWindow::filterPumpSLOT()
{
    if (filterPumpWindow::num == 0)
        this->filtPumpWindow= new filterPumpWindow(caso4ExtractH2Osystem::Ylyb, caso4ExtractH2Osystem::Qlyb, caso4ExtractH2Osystem::Hlyb, caso4ExtractH2Osystem::Nflyb,
                                                                caso4ExtractH2Osystem::Nelyb, caso4ExtractH2Osystem::Nklyb, this);
    else{
        this->filtPumpWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->filtPumpWindow->showNormal();
    }
}


void MainWindow::emergencySryPumpSLOT()
{
    if (emergencySlurryPumpWindow::num == 0)
        this->emeSlurryPumpWindow = new emergencySlurryPumpWindow(emergencySlurrySystem::Yshgb,
                                                             emergencySlurrySystem::Qshgb, emergencySlurrySystem::Hshgb, emergencySlurrySystem::Nfshgb,
                                                                emergencySlurrySystem::Neshgb, emergencySlurrySystem::Nkshgb, this);
    else{
        this->emeSlurryPumpWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->emeSlurryPumpWindow->showNormal();
    }
}

void MainWindow::wasteH2oFeedPumpSLOT()
{
    if (wasteh2ofeedPumpWindow::num == 0)
        this->wasteh2oFeedPumpWindow = new wasteh2ofeedPumpWindow(wasteH2OproSystem::Yfshb,
                                                             wasteH2OproSystem::Qfshb, wasteH2OproSystem::Hfshb, wasteH2OproSystem::Nffshb,
                                                                wasteH2OproSystem::Nefshb, wasteH2OproSystem::Nkfshb, this);
    else{
        this->wasteh2oFeedPumpWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->wasteh2oFeedPumpWindow->showNormal();
    }
}

void MainWindow::waterPumpSLOT()
{
    if (waterPumpWindow::num == 0)
        this->wateringPumpWindow = new waterPumpWindow(processH2Osystem::Yccb,
                                                             processH2Osystem::Qccb, processH2Osystem::Hccb, processH2Osystem::Nfccb,
                                                                processH2Osystem::Neccb, processH2Osystem::Nkccb, this);
    else{
        this->wateringPumpWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->wateringPumpWindow->showNormal();
    }
}



void MainWindow::oxidationAiBlowerSLOT()
{
    if (oxidationAiBlowerWindow::num == 0)

        this->o2AirBlowerWindow = new oxidationAiBlowerWindow(this);
    else{
        this->o2AirBlowerWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->o2AirBlowerWindow->showNormal();
    }
}

void MainWindow::pressureAirBlowerSLOT()
{
    if (pressureAirBlowerWindow::num == 0)

        this->pAirBlowerWindow = new pressureAirBlowerWindow(this);
    else{
        this->pAirBlowerWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->pAirBlowerWindow->showNormal();
    }


}

void MainWindow::absorberSryCirPumpSLOT()
{
    if (absorberSryCirPumpWindow::num == 0)
        // 效率:yjxb, 数量:xg, 流量:Qjxb

        this->absorberSlrCirWindow = new absorberSryCirPumpWindow(so2AbsorbSystem::Yjxb, so2AbsorbSystem::Qjxb, so2AbsorbSystem::Hjxb, so2AbsorbSystem::Nfjxb, so2AbsorbSystem::Nejxb,
                                                                  so2AbsorbSystem::Nkjxb, so2AbsorbSystem::xg, this);
    else{
        this->absorberSlrCirWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->absorberSlrCirWindow->showNormal();
    }

}


void MainWindow::caco3SryPumpSLOT()
{
    if (caco3SlurryPumpWindow::num == 0)
        this->caco3SryPumpWindow = new caco3SlurryPumpWindow(slurryPreSystem::Yshjb,
                                                             slurryPreSystem::Qshjb, slurryPreSystem::Hshjb, slurryPreSystem::Nfshjb,
                                                                slurryPreSystem::Neshjb, slurryPreSystem::Nkshjb, this);
    else{
        this->caco3SryPumpWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->caco3SryPumpWindow->showNormal();
    }
}

void MainWindow::caco3SryPumpCirSLOT()
{
    if (caco3SlurryCurculantPumpWindow::num == 0)
        this->caco3SryPumpCirWindow = new caco3SlurryCurculantPumpWindow(slurryPreSystem::Yshjxb,
                                                             slurryPreSystem::Qshjxb, slurryPreSystem::Hshjxb, slurryPreSystem::Nfshjxb,
                                                                slurryPreSystem::Neshjxb, slurryPreSystem::Nkshjxb, this);
    else{
        this->caco3SryPumpCirWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->caco3SryPumpCirWindow->showNormal();
    }
}

void MainWindow::caco3RotationalFlowSLOT()
{
    if (caco3RotationalFlow_window::num == 0)
        this->caco3RoFlowWindow = new caco3RotationalFlow_window(slurryPreSystem::Qshhx, slurryPreSystem::XZshhx, this);
    else{
        this->caco3RoFlowWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->caco3RoFlowWindow->showNormal();
    }
}


void MainWindow::saveSLOT()
{
    this->saveObj = new saveObject;
    connect(saveObj, SIGNAL(messageboxShowSIGNAL(int)), this, SLOT(messageboxShowSLOT(int)));

    switch(QMessageBox::question(this, tr("保存项目"), tr("是否确定保存该项目？"),
                                 QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))

    {
    case QMessageBox::Ok:{
        this->saveObj->start();
        break;
    }
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }
    delete saveObj;
    return;
}

void MainWindow::messageboxShowSLOT(int num)
{
    qDebug() << "in messageboxshowslot";
    switch(num)
    {
    case 0:
        QMessageBox::warning(this, tr("保存结果"), tr("未打开任何项目"));
        break;
    case 1:
        QMessageBox::warning(this, tr("连接结果"), tr("数据库连接失败"));
        break;
    case 2:
        QMessageBox::warning(this, tr("保存结果"), tr("项目为只读模式打开,无法保存"));
        break;
    case 3:
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
        break;
    case 4:
        QMessageBox::information(this, tr("保存结果"), tr("项目保存成功!"));
        break;
    case 5:
        QMessageBox::information(this, tr("提交校审结果"), tr("项目提交校审成功!"));
        break;

    default:
        break;
    }
}

void MainWindow::checkOpinionSLOT()
{
    if (window_project_check_opinion::num == 0 )
    {
        if (MainWindow::first == 1 && systemConfigurationWindow::pzh == 1)
        {
            this->checkOpinionWinow = new window_project_check_opinion(this);
        }
        else
        {
            QMessageBox::warning(this, tr("提示"), tr("须新建或打开项目"));
        }
    }
    else{
        this->checkOpinionWinow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->checkOpinionWinow->showNormal();
    }

}



void MainWindow::verifyProjectSLOT()
{
    if (window_project_check_verify::num == 0 )
    {
        if (MainWindow::first == 1 && systemConfigurationWindow::pzh == 1)
        {
            this->verifyProjectWindow = new window_project_check_verify(this);
        }
        else
        {
            QMessageBox::warning(this, tr("提示"), tr("须新建或打开项目"));
        }
    }
    else{
        this->verifyProjectWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->verifyProjectWindow->showNormal();
    }

}


void MainWindow::checkProjectSLOT()
{

    if (checkProjectWindow::num == 0 )
    {
        if (MainWindow::first == 1 && systemConfigurationWindow::pzh == 1)
        {
            this->checkPjWindow = new checkProjectWindow(this);
        }
        else
        {
            QMessageBox::warning(this, tr("提示"), tr("须新建或打开项目"));
        }
    }
    else{
        this->checkPjWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->checkPjWindow->showNormal();
    }
}


void MainWindow::aboutSLOT()
{
    if (about_window::num == 0)
        this->aboutWindow = new about_window(this);
    else{
        this->aboutWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->aboutWindow->showNormal();
    }
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setAttribute(Qt::WA_QuitOnClose, true);
    this->setAttribute(Qt::WA_DeleteOnClose, true);

    this->setWindowTitle(tr("湿法烟气脱硫系统"));
    this->midWidget = new middleWidget(this);

    this->setCentralWidget(this->midWidget);
    this->createAction();
    this->createMenus();
    this->createToolBars();
}


