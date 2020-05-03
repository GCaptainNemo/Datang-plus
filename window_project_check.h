#ifndef CHECKPROJECTWINDOW_H
#define CHECKPROJECTWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "widget_okcancel.h"
#include "utils.h"
#include "par_others.h"

class checkProjectWindow : public QDialog
{
    Q_OBJECT
public:
    explicit checkProjectWindow(QWidget *parent = nullptr);
    ~checkProjectWindow();
    static int num;
    virtual void checking();
    bool verifyLimit();


signals:

public slots:
    virtual void okSLOT();

protected:
    QTextEdit * checkOpinionTextedit;
    QRadioButton * passRadioButton;
    QRadioButton * recalculateRadioButton;
    QButtonGroup * buttonGroup;
    QVBoxLayout * layout;
    QHBoxLayout * hlayout1;
    widget_okcancel * okCancelButtonWidget;
    QWidget * radioButtonWidget;
    QSqlDatabase db;
    QSqlQuery * query;

};

#endif // CHECKPROJECTWINDOW_H
