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

#include "login_window.h"
#include "newproject_window.h"
#include "openproject_window.h"
#include "checkproject_window.h"
#include "about_window.h"
#include "db_utils.h"
#include "global_par.h"



class setCoalParThread: public QThread
{
    Q_OBJECT
signals:
    void msgboxShowSIGNAL(const int &res);

public:
    setCoalParThread(int prid);

protected:
    void run();


private:
    int prid;

};

class setEquipParThread: public QThread
{
    Q_OBJECT
signals:
    void msgboxShowSIGNAL(const int &res);

public:
    setEquipParThread(int prid);
    ~setEquipParThread();

protected:
    void run();


private:
    int prid;
};






class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createAction();
    void createMenus();
    void createToolBars();

private slots:
    void newSLOT();
    void openSLOT();
    void saveSLOT();
    void checkSLOT();
    void aboutSLOT();

    void setParSLOT(int);

private:

    QSqlDatabase db;
//    QSqlQuery query;
    setCoalParThread * setparThread;
    setEquipParThread * setEquipThread;

    Login_window * loginWindow = nullptr;
    newPjWindow * newWindow = nullptr;
    openPjWindow * openProjectwindow = nullptr;
    checkPjWindow * checkOpinionWindow = nullptr;
    about_window * aboutWindow = nullptr;

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
    QAction * caco3CirculantPumpAction;
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
    QMenu * wasterH2Osystemmenu;
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
