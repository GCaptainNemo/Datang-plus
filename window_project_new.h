#ifndef NEWPROJECTWINDOW_H
#define NEWPROJECTWINDOW_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QDateTime>
#include <QSqlQuery>
#include <QGridLayout>
#include <QDialog>

#include "utils.h"
#include "par_users.h"
#include "par_projects.h"
#include "widget_okcancel.h"
#include "par_pinf.h"
#include "par_equip.h"

class newProjectWindow : public QDialog
{
    Q_OBJECT
public:
    static int num;
    explicit newProjectWindow(QWidget *parent = nullptr);
    ~newProjectWindow();


signals:
    void changeTitleSIGNAL();

public slots:
    void okSLOT();

private:
    QLabel * nameLabel;
    QLineEdit * nameLineedit;
    widget_okcancel * buttonWidget;
    QGridLayout * layout;
    QSqlQuery * query;
    QSqlDatabase db;
    int testDb();
    void setInitValue();
};

#endif // NEWPROJECTWINDOW_H
