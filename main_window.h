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
#include <QThread>

#include "window_project_new.h"
#include "window_project_open.h"
#include "window_project_check.h"
#include "window_project_about.h"
#include "utils.h"
#include "par_equip.h"
#include "par_projects.h"


#include "window_rotationalflowwasteh2o_base.h"
#include "window_rotationalflowcaso4.h"
#include "window_rotationalflowcaco3.h"
#include "window_pump_caso4discharge_base.h"
#include "window_pump_caco3slurry.h"
#include "window_pump_filter.h"
#include "window_pump_caco3slurrycurculant.h"
#include "window_pump_emergencyslurry.h"
#include "window_pump_wasteh2ofeed.h"
#include "window_pump_proccessh2o.h"
#include "window_pump_waterwindow.h"
#include "window_pump_absorberslurrycirculant.h"

#include "window_vacuumbeltdehydrator.h"

#include "window_srytank_agitatoremergency_base.h"
#include "window_srytank_agitatorcaco3_base.h"
#include "window_srycirtank_agitatorcaco3.h"
#include "window_srytank_agitatorfilter.h"

#include "window_tankproh2o.h"
#include "window_wetballmill.h"
#include "window_heatexchange.h"
#include "window_housecaco3.h"
#include "window_aiblowero2.h"
#include "window_airblowerpressure.h"

#include "window_systemconfiguration.h"
#include "window_inputparameter.h"
#include "window_project_save.h"
#include <QDesktopServices>
#include "window_manage_project.h"
#include "window_manage_user.h"


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
    void setLimitSLOT(QString usrlimit);

    void projectManageSLOT();
    void userManageSLOT();

    void newSLOT();
    void openSLOT();
    void saveSLOT();
    void checkSLOT();
    void aboutSLOT();
    void wasteH2OrotationalFlowSLOT();
    void caso4RotationalFlowSLOT();
    void caco3RotationalFlowSLOT();
    void wasteH2oFeedPumpSLOT();

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
    void oxidationAiBlowerSLOT();
    void pressureAirBlowerSLOT();
    void configureSystemSLOT();
    void createPdfSLOT();
    void inputParSLOT();

    void messageboxShowSLOT(int num);


private:
    saveObject * saveObj;
    QThread * myThread;


    QSqlDatabase db;

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
    oxidationAiBlowerWindow * o2AirBlowerWindow;
    pressureAirBlowerWindow * pAirBlowerWindow;
    systemConfigurationWindow * sysConfigWindow;
    inputParameterWindow * inputParWindow;
    manageProjectWindow * managePjWindow;
    window_manage_user * manageUsrWindow;

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
    QAction *verifyProjectAction;
    QAction *checkOpinionAction;
    QAction *closeAction;

    //    setting menu

    QMenu *settingmenu;
    QAction *systemSettingAction;
    QAction *createPdfAction;

    //    input parameter menu

    QMenu *inputmenu;
    QAction * inputParAction;
    QAction * coalQualityCalculationAction;

    //    equiment parameter menu

    QMenu * equipmentmenu;
    QAction * absorberParAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMenu * smokeSystemmenu;
    QAction * pressureAirBlowerAction;
    QAction * heatExchangerAction;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    QMenu * so2AbsorbSystemmenu;
    QAction * oxidationAirBlowerAction;
    QAction * slurryCirculationPumpAction;
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
    QAction * usrManageAction;
    QAction * projectManageAction;
    QAction * usageRecordAction;
    QAction * experParAction;

    //    Help menu

    QMenu * helpMenu;
    QAction * helpAction;
    QAction * aboutAction;



};

#endif // MAINWINDOW_H
