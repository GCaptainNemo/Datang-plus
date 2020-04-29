#ifndef WINDOW_PUMPABSORBERSLURRYCIRCULANT_H
#define WINDOW_PUMPABSORBERSLURRYCIRCULANT_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <QStringList>
#include "widget_okcancel.h"
#include "utils.h"



class absorberSryCirPumpWindow : public QDialog
{
    Q_OBJECT
public:
    static int num;
    explicit absorberSryCirPumpWindow(float & Yjxb, float & Qjxb, float * Hjxb, float * Nfjxb, float * Nejxb, float * Nkjxb, int & xg, QWidget *parent = nullptr);
    ~absorberSryCirPumpWindow();

signals:

public slots:
    
private:
    QLabel * efficiencyLabel, *numLabel, * flowLabel;
    QLineEdit * efficiencyLineedit, *numLineedit, * flowLineedit;
    QGridLayout * layout, *buttonLayout;
    QTableWidget * tableWidget;
    void initTableWidget();
    float & yjxb;
    float & qjxb;
    float * hjxb;
    float * nfjxb;
    float * nejxb;
    float * nkjxb;
    int  & xg;
    QStringList headers;
    widget_okcancel *buttonWidget;

};

#endif // WINDOW_PUMPABSORBERSLURRYCIRCULANT_H
