#-------------------------------------------------
#
# Project created by QtCreator 2020-03-14T15:51:40
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FML
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    central_widget.cpp \
    main_window.cpp \
    utils.cpp \
    par_pinf.cpp \
    par_gasresult.cpp \
    par_equip.cpp \
    par_gslresult.cpp \
    window_about.cpp \
    window_login.cpp \
    par_projects.cpp \
    window_projectnew.cpp \
    window_projectopen.cpp \
    window_projectcheck.cpp \
    window_pumpcaco3slurry.cpp \
    window_pumpcaso4discharge_base.cpp \
    window_pumpfilter.cpp \
    window_rotationalflowwasteh2o_base.cpp \
    window_pumpcaco3slurrycurculant.cpp \
    window_pumpemergencyslurry.cpp \
    window_pumpwasteh2ofeed.cpp \
    window_pumpproccessh2o.cpp \
    window_pumpwaterwindow.cpp \
    window_pumpabsorberslurrycirculant.cpp \
    window_vacuumbeltdehydrator.cpp \
    window_srycirtank_agitator_caco3.cpp \
    window_srytank_agitatorfilter.cpp \
    window_srytank_agitatoremergency_base.cpp \
    window_tankproh2o.cpp \
    window_srytank_agitatorcaco3_base.cpp \
    window_wetballmill.cpp \
    window_heatexchange.cpp \
    window_housecaco3.cpp

HEADERS += \
    central_widget.h \
    main_window.h \
    utils.h \
    par_equip.h \
    par_gasresult.h \
    par_gslresult.h \
    par_pinf.h \
    window_login.h \
    window_about.h \
    par_projects.h \
    window_projectnew.h \
    window_projectopen.h \
    window_projectcheck.h \
    window_pumpcaso4discharge_base.h \
    window_pumpcaco3slurry.h \
    window_pumpfilter.h \
    window_rotationalflowwasteh2o_base.h \
    window_rotationalflowcaco3.h \
    window_rotationalflowcaso4.h \
    window_pumpcaco3slurrycurculant.h \
    window_pumpemergencyslurry.h \
    window_pumpwasteh2ofeed.h \
    window_pumpproccessh2o.h \
    window_pumpwaterwindow.h \
    window_pumpabsorberslurrycirculant.h \
    window_vacuumbeltdehydrator.h \
    window_srytank_agitatorfilter.h \
    window_srytank_agitatoremergency_base.h \
    window_srycirtank_agitatorcaco3.h \
    window_srytank_agitatorcaco3_base.h \
    window_tankproh2o.h \
    window_wetballmill.h \
    window_heatexchange.h \
    window_housecaco3.h

DISTFILES += \
    icon/new.ico \
    icon/open.ico \
    icon/供应商.ico \
    icon/安全.ico \
    icon/审核.ico \
    icon/统计.ico \
    icon/退出.ico \
    icon/项目.ico
