#ifndef WINDOW_HEATEXCHANGE_H
#define WINDOW_HEATEXCHANGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QDialog>
#include "par_gasresult.h"
#include "widget_okcancel.h"

class heatExchangeWindow : public QDialog
{
    Q_OBJECT
public:
    explicit heatExchangeWindow(QWidget *parent = nullptr);
    static int num;
    ~heatExchangeWindow();
    
public slots:
    void okSLOT();

protected:
    QLabel * gasInputTLabel, * gasOutputTLabel, * outputTLabel, *gasFlowLabel;
    QLineEdit* gasInputTLineedit, * gasOutputTLineedit, * outputTLineedit, *gasFlowLineedit;
    QGridLayout * gridLayout;
    QVBoxLayout * layout;
    QWidget * gridWidget;
    widget_okcancel * buttonWidget;

};

#endif // WINDOW_HEATEXCHANGE_H
