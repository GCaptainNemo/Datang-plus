#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include <QWidget>
#include <QVBoxLayout>
#include <QOpenGLWidget>
#include <QTreeWidget>
#include <QTableWidget>
#include <QSplitter>
#include <QPainter>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPalette>

#include "window_parameter_flue_gas.h"
#include "window_parameter_slurry.h"

class middleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit middleWidget(QWidget *parent = nullptr);
    QWidget * widgetMain, *widgetFlowChart;
    QPushButton *pushButton;

    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout * vlayout;
    window_parameter_flue_gas * windowParFlueGas;
    window_parameter_slurry * windowParSry;


private:

signals:

public slots:
    void showFlueGasParSLOT();
    void showSrySLOT();
protected:

};

#endif // CENTRALWIDGET_H
