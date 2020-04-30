#ifndef NEWPROJECTWINDOW_H
#define NEWPROJECTWINDOW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include "utils.h"
#include "par_others.h"


class newPjWindow : public QDialog
{
    Q_OBJECT
public:
    static int num;
    explicit newPjWindow(QWidget *parent = nullptr);
    ~newPjWindow();


signals:

public slots:
    void okSLOT();

private:
    QLabel * nameLabel;
    QLineEdit * nameLineedit;
    QPushButton * okButton;
    QHBoxLayout * layout;
    QSqlQuery * query;
    QSqlDatabase db;
    int testDb();
};

#endif // NEWPROJECTWINDOW_H
