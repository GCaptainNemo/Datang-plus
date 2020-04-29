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
    main_window.cpp \
    utils.cpp \
    par_pinf.cpp \
    par_gasresult.cpp \
    par_equip.cpp \
    par_gslresult.cpp \
    par_projects.cpp \
    window_rotationalflowwasteh2o_base.cpp \
    window_vacuumbeltdehydrator.cpp \
    window_srycirtank_agitator_caco3.cpp \
    window_srytank_agitatorfilter.cpp \
    window_srytank_agitatoremergency_base.cpp \
    window_tankproh2o.cpp \
    window_srytank_agitatorcaco3_base.cpp \
    window_wetballmill.cpp \
    window_heatexchange.cpp \
    window_housecaco3.cpp \
    window_aiblowero2.cpp \
    window_airblowerpressure.cpp \
    window_systemconfiguration.cpp \
    par_experience.cpp \
    window_project_about.cpp \
    window_project_check.cpp \
    window_project_login.cpp \
    window_project_new.cpp \
    window_project_open.cpp \
    window_inputparameter.cpp \
    window_pump_absorberslurrycirculant.cpp \
    window_pump_caco3slurry.cpp \
    window_pump_caco3slurrycurculant.cpp \
    window_pump_caso4discharge_base.cpp \
    window_pump_emergencyslurry.cpp \
    window_pump_filter.cpp \
    window_pump_proccessh2o.cpp \
    window_pump_wasteh2ofeed.cpp \
    window_pump_waterwindow.cpp \
    par_others.cpp \
    window_project_save.cpp \
    widget_central.cpp \
    widget_okcancel.cpp

HEADERS += \
    main_window.h \
    utils.h \
    par_equip.h \
    par_gasresult.h \
    par_gslresult.h \
    par_pinf.h \
    par_projects.h \
    window_rotationalflowwasteh2o_base.h \
    window_rotationalflowcaco3.h \
    window_rotationalflowcaso4.h \
    window_vacuumbeltdehydrator.h \
    window_srytank_agitatorfilter.h \
    window_srytank_agitatoremergency_base.h \
    window_srycirtank_agitatorcaco3.h \
    window_srytank_agitatorcaco3_base.h \
    window_tankproh2o.h \
    window_wetballmill.h \
    window_heatexchange.h \
    window_housecaco3.h \
    window_aiblowero2.h \
    window_airblowerpressure.h \
    window_systemconfiguration.h \
    par_experience.h \
    window_project_about.h \
    window_project_check.h \
    window_project_login.h \
    window_project_new.h \
    window_project_open.h \
    window_inputparameter.h \
    window_pump_absorberslurrycirculant.h \
    window_pump_caco3slurry.h \
    window_pump_caco3slurrycurculant.h \
    window_pump_caso4discharge_base.h \
    window_pump_emergencyslurry.h \
    window_pump_filter.h \
    window_pump_proccessh2o.h \
    window_pump_wasteh2ofeed.h \
    window_pump_waterwindow.h \
    par_others.h \
    window_project_save.h \
    widget_central.h \
    widget_okcancel.h

DISTFILES += \
    icon/new.ico \
    icon/open.ico \
    icon/供应商.ico \
    icon/安全.ico \
    icon/审核.ico \
    icon/统计.ico \
    icon/退出.ico \
    icon/项目.ico
