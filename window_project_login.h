#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QMessageBox>
#include<QSql>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QThread>
#include<iostream>
#include <QtCore/QProcess>
#include <QtNetwork/QHostInfo>
#include <QDateTime>
#include <QObject>

#include "utils.h"
#include "par_others.h"


class Login_window : public QDialog
{
    Q_OBJECT

public:
    Login_window(QWidget *parent = nullptr);

    ~Login_window(){
        loginThread.quit();
        loginThread.exit();
    }


signals:
    void startLoginSIGNAL();
    void setLimitSIGNAL(QString usrlimit);

public slots:
    void clearSLOT();
    void okSLOT();
    void exitSLOT();
    void testNetSLOT();

private:
    QLabel *usrnameLabel, *passwordLabel, *ipAddressLabel;
    QLineEdit *usrnameLineedit, *pwordLineedit, *ipLineedit;
    QPushButton *testNetButton, *okButton, *clearButton, *exitButton;
    QGridLayout * layout, *layout1;
    QThread loginThread;
    QWidget * buttonWidget;
    QSqlDatabase db;

    void start();

};


#endif // LOGIN_WINDOW_H
