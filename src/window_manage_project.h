#ifndef WINDOW_MANAGE_PROJECT_H
#define WINDOW_MANAGE_PROJECT_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QStringList>
#include "utils.h"
#include "par_users.h"

class manageProjectWindow : public QDialog
{
    Q_OBJECT
public:
    explicit manageProjectWindow(QWidget *parent = nullptr);
    static int num;
    ~manageProjectWindow();

signals:

public slots:
    void deleteProjectSLOT();
    void setLineeditTextSLOT(int row);

protected:
    QLabel * passwordLabel, *pridLabel;
    QLineEdit * passwordLineedit, *pridLineedit;
    QPushButton * deleteButton, *cancelButton;
    QVBoxLayout * layout;
    QHBoxLayout * hlayout;
    QTableWidget * tableWidget;
    QWidget * widget;
    QSqlDatabase db;
    QSqlQuery * query;
    void initSqlStatement(QString prid);
    void setPjModel();
    void start(QString prid);
private:
    QString sqlPinf, sqlEquip, sqlGas, sqlGSL, sqlCoal, sqlProject;
    void loadModel();
};

#endif // WINDOW_MANAGE_PROJECT_H
