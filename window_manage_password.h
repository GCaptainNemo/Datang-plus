#ifndef WINDOW_MANAGE_PASSWORD_H
#define WINDOW_MANAGE_PASSWORD_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>
#include <QDateTime>


#include "widget_okcancel.h"
#include "utils.h"
#include "par_others.h"

class window_manage_password : public QDialog
{
    Q_OBJECT
public:
    explicit window_manage_password(QWidget *parent = nullptr);
    static int num;
    ~window_manage_password();

signals:

public slots:
    void okSLOT();

protected:
    QLabel * usridLabel, *usrnameLabel, *usrlimitLabel, *initPasswordLabel, *newPasswordLabel, *okNewPasswordLabel;
    QLineEdit * usridLineedit, *usrnameLineedit, *usrlimitLineedit, *initPasswordLineedit, *newPasswordLineedit,
    *okNewPasswordLineedit;
    widget_okcancel * buttonWidget;
    QGridLayout * gridLayout;
    QSqlDatabase db;
    QSqlQuery * query;
    void updatePassword(const QString &newpw2);



};

#endif // WINDOW_MANAGE_PASSWORD_H
