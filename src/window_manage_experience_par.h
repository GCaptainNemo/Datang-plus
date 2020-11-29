#ifndef WINDOW_MANAGE_EXPERIENCE_PAR_H
#define WINDOW_MANAGE_EXPERIENCE_PAR_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

#include "widget_okcancel.h"
#include "utils.h"
#include "par_experience.h"


class window_manage_experience_par : public QDialog
{
    Q_OBJECT
public:
    explicit window_manage_experience_par(QWidget *parent = nullptr);
    static int num;
    ~window_manage_experience_par();


signals:

public slots:
    void okSLOT();

protected:
    QWidget *widget1, *widget2, *widget3;
    QGridLayout * layout, *layout1, *layout2, *layout3;
    QLabel *leakLabel, *gghLabel, *gghSO3Label,*gghHFLabel, *gghDustLabel, * absorberLabel,
    *absorberSO3Label, *absorberHCLlabel, *absorberHFlabel, *absorberDustLabel;
    QLabel * casLabel, *caso4Label, *mgco3Label,*proH2Olabel, *circulantSryLabel, *stressLabel;
    QLineEdit *leakLineedit, *gghSO3Lineedit,*gghHFLineedit, *gghDustLineedit,
    *absorberSO3Lineedit, *absorberHCLlineedit, *absorberHFlineedit, *absorberDustLineedit;
    QLineEdit * casLineedit, *caso4Lineedit, *mgco3Lineedit,*proH2Olineedit, *circulantSryLineedit, *stressLineedit;
    widget_okcancel * buttonWidget;
    QSqlDatabase db;
    QSqlQuery * query;



    void initWidget1();
    void initWidget2();
    void initWidget3();
    void initParameter();


};

#endif // WINDOW_MANAGE_EXPERIENCE_PAR_H
