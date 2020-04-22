#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QImage>
#include <QIcon>
#include <QDebug>
#include <iostream>
#include <exception>

#include "window_login.h"
#include "window_projectnew.h"
#include "window_projectopen.h"
#include "window_projectcheck.h"
#include "window_about.h"
#include "utils.h"
#include "par_equip.h"
#include "par_projects.h"


#include "window_rotationalflowwasteh2o_base.h"
#include "window_rotationalflowcaso4.h"
#include "window_rotationalflowcaco3.h"
#include "window_pumpcaso4discharge_base.h"
#include "window_pumpcaco3slurry.h"
#include "window_pumpfilter.h"
#include "window_pumpcaco3slurrycurculant.h"
#include "window_pumpemergencyslurry.h"
#include "window_pumpwasteh2ofeed.h"
#include "window_pumpproccessh2o.h"
#include "window_pumpwaterwindow.h"
#include "window_pumpabsorberslurrycirculant.h"

#include "window_vacuumbeltdehydrator.h"

#include "window_srytank_agitatoremergency_base.h"
#include "window_srytank_agitatorcaco3_base.h"
#include "window_srycirtank_agitatorcaco3.h"
#include "window_srytank_agitatorfilter.h"

#include "window_tankproh2o.h"
#include "window_wetballmill.h"
#include "window_heatexchange.h"
#include "window_housecaco3.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createAction();
    void createMenus();
    void createToolBars();


signals:
    void setParThreadStart();


private slots:
    void newSLOT();
    void openSLOT();
    void saveSLOT();
    void checkSLOT();
    void aboutSLOT();
    void wasteH2OrotationalFlowSLOT();
    void caso4RotationalFlowSLOT();
    void caco3RotationalFlowSLOT();
    void wasteH2oFeedPumpSLOT();

    void setParSLOT(int prid);
    void caso4DischargePumpSLOT();
    void filterPumpSLOT();
    void caco3SryPumpSLOT();
    void waterPumpSLOT();
    void caco3SryPumpCirSLOT();
    void emergencySryPumpSLOT();
    void proH2OpumpSLOT();
    void absorberSryCirPumpSLOT();
    void setTitleSLOT();
    void vacuumBeltDeWindowSLOT();
    void emergencySryAndAgitatorSLOT();
    void caco3SryAndAgitatorSLOT();
    void caco3SryCirAndAgitatorSLOT();
    void filterSryAndAgitatorSLOT();
    void proH2OtankSLOT();
    void wetMillSLOT();
    void heatExchangeSLOT();
    void caco3HouseSLOT();


private:
    setParObject * setparObj;
    QThread * myThread;


    QSqlDatabase db;
//    QSqlQuery query;

    Login_window * loginWindow;
    newPjWindow * newWindow;
    openPjWindow * openProjectwindow;
    checkPjWindow * checkOpinionWindow ;
    about_window * aboutWindow ;
    wasteH2OrotationalFlow_window * wasteH2OroFlowWindow ;
    caso4RotationalFlow_window * caso4RoFlowWindow;
    caco3RotationalFlow_window * caco3RoFlowWindow;
    caso4DischargePumpWindow * caso4DisPumpWindow;
    caco3SlurryPumpWindow * caco3SryPumpWindow;
    caco3SlurryCurculantPumpWindow * caco3SryPumpCirWindow;
    filterPumpWindow * filtPumpWindow;
    emergencySlurryPumpWindow * emeSlurryPumpWindow;
    wasteh2ofeedPumpWindow * wasteh2oFeedPumpWindow;
    processH2OpumpWindow * proH2OpumpWindow;
    waterPumpWindow * wateringPumpWindow;
    absorberSryCirPumpWindow * absorberSlrCirWindow;
    vacuumBeltDehydratorWindow * vacuumBeltDeWindow;
    emergencySryTankAndAgitatorWindow * emeSryTankAndAgitatorWindow;
    caco3SryTankAndAgitatorWindow * caco3SryTankAgitatorWindow;
    caco3SryCirTankAndAgitatorWindow * caco3SryCirTankAgitatorWindow;
    filterSryTankAndAgitatorWindow * filterSryTankAgitatorWindow;
    proH2OtankWindow * processH2OtankWindow;
    wetBallMillWindow * wetMillWindow;
    heatExchangeWindow * heatExWindow;
    caco3HouseWindow * caco3HosWindow;

    //    工具栏

    QToolBar *fileTool;
    QToolBar *inputTool;
    QToolBar *outputTool;


    //    菜单栏
    //    file menu

    QMenu *filemenu;
    QAction *openAction;
    QAction *newAction;
    QAction *saveAction;
    QAction *submitCheckingAction;
    QAction *checkingProjectAction;
    QAction *reviewProjectAction;
    QAction *checkOpinionAction;
    QAction *closeAction;

    //    setting menu

    QMenu *settingmenu;
    QAction *systemSettingAction;
    QAction *proccessGenratorAction;

    //    input parameter menu

    QMenu *inputmenu;
    QAction * inputParAction;
    QAction * coalQualityCalculationAction;

    //    equiment parameter menu

    QMenu * equipmentmenu;
    QAction * absorberParAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * smokeSystemmenu;
    QAction * boosterFanAction;
    QAction * heatExchangerAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * so2AbsorbSystemmenu;
    QAction * oxidationAirBlowerAction;
    QAction * slurryCirculationPumpAction;
    QAction * absorberAgitatorAction;
    QAction * caso4DischargePumpAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * caso4DehydrationSystemmenu;
    QAction * caso4RotationalFlowAction;
    QAction * vacuumBeltDehydratorAction;
    QAction * filterTankAndAgitatorAction;
    QAction * filterPumpAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * wetPulpingSystemmenu;
    QAction * caco3HouseAction;
    QAction * wetBallMillAction;
    QAction * caco3CirculantTankAndAgitatorAction;
    QAction * caco3SlurryCirculantPumpAction;
    QAction * caco3RotationalFlowAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * powderPulpingSystemmenu;
    QAction * caco3PowderHouseAction;
    QAction * caco3SlurryTankAndAgitatorAction;
    QAction * caco3SlurryPumpAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * processWaterSystemmenu;
    QAction * processWaterTankAction;
    QAction * processWaterPumpAction;
    QAction * waterPumpAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * emergencySlurrySystemmenu;
    QAction * emergencySlurryTankAndAgitatorAction;
    QAction * emergencySlurryPumpAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * wasteH2Osystemmenu;
    QAction * wasteH2OrotationalFlowAction;
    QAction * wasteH2OfeedAction;\
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QAction * equipmentParSetAction;\

    
    //    Data proccess menu

    QMenu * dataProcessMenu;
    QAction * balanceAction;
    QAction * curveAction;

    //    System arrangement menu

    QMenu * systemArrangeMenu;
    QAction * changePasswordAction;
    QAction * usrArrangeAction;
    QAction * projectArrangeAction;
    QAction * usageRecordAction;
    QAction * experParAction;

    //    Help menu

    QMenu * helpMenu;
    QAction * helpAction;
    QAction * aboutAction;



};

#endif // MAINWINDOW_H
