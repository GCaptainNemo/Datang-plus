#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
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


class loginThreadObject;
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

public slots:
    void clearSLOT();
    void okSLOT();
    void exitSLOT();
    void testNetSLOT();
    void showMsgboxSLOT(int);

private:
    QLabel *usrnameLabel, *passwordLabel, *ipAddressLabel;
    QLineEdit *usrnameLineedit, *pwordLineedit, *ipLineedit;
    QPushButton *testNetButton, *okButton, *clearButton, *exitButton;
    QHBoxLayout *hlayout1, *hlayout2, *hlayout3, *hlayout4;
    QVBoxLayout *layout;
    loginThreadObject *threadObject;
    QThread loginThread;
//    MainWindow * mainWindow;
};


class loginThreadObject: public QObject
{
    Q_OBJECT
signals:
    void msgboxShowSIGNAL(const int &res);
    void finishedSIGNAL();

public:
    loginThreadObject(QString nm, QString pw, QString ip);

public slots:
    void start();


private:
    QString name;
    QString password;
    QString ip;

};



//class loginThread: public QThread
//{
//    Q_OBJECT
//signals:
//    void msgboxShowSIGNAL(const int &res);

//public:
//    loginThread(QString nm, QString pw, QString ip);

//protected:
//    void run();


//private:
//    QString name;
//    QString password;
//    QString ip;

//};

#endif // LOGIN_WINDOW_H
