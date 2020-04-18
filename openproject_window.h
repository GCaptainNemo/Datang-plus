#ifndef OPENWINDOW_H
#define OPENWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>

#include "login_window.h"

class openPjWindow : public QWidget
{
    Q_OBJECT
public:
    static int num;
    explicit openPjWindow(QWidget *parent = nullptr);
    ~openPjWindow();


signals:
    void pridSIGNAL(int);
    

public slots:
    void setLineeditTextSLOT(const QModelIndex &index);
    void openPjSLOT();


private:

    QLabel * pjLabel;
    QLineEdit * pjLineedit;
    QPushButton * openButton;
    QVBoxLayout * layout;
    QHBoxLayout * hlayout;
    QSqlTableModel * projectModel;
    QTableView * tableView;
    QSqlDatabase db;
    QSqlQueryModel * pjModel;
    void setPjModel();
};




#endif // OPENWINDOW_H
