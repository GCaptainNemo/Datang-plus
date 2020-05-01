#ifndef WINDOW_MANAGE_USER_H
#define WINDOW_MANAGE_USER_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QStringList>
#include <QComboBox>
#include "utils.h"
#include "par_others.h"




class window_manage_user: public QDialog
{
    Q_OBJECT
public:
    explicit window_manage_user(QWidget *parent = nullptr);
    static int num;
    ~window_manage_user();

signals:

public slots:
    void deleteSLOT();
    void addSLOT();
    void saveSLOT();
    void updateSLOT();
    void setLineeditTextSLOT(int row);

protected:
    QLabel * managerPasswordLabel, *okPasswordLabel, *initPasswordLabel, *usridLabel, *usrnameLabel, *usrLimitLabel;
    QComboBox * usrlimitCombobox;
    QLineEdit * managerPasswordLineedit, *okPasswordLineedit, *initPasswordLineedit, *usridLineedit, *usrnameLineedit;
    QPushButton * deleteButton, *addButton, *saveButton, *correctButton;
    QVBoxLayout * layout;
    QGridLayout * gridLayout;
    QTableWidget * tableWidget;
    QSqlDatabase db;
    QWidget * widget, *buttonWidget;
    QHBoxLayout * hlayout;
    QSqlQuery * query;
    void initSqlStatement(QString prid);
    void setUserModel();
    void start(QString prid);
private:
    QString sqlPinf, sqlEquip, sqlGas, sqlGSL, sqlCoal, sqlProject;
    void loadModel();
};

#endif // WINDOW_MANAGE_USER_H
