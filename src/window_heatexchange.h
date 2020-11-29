#ifndef WINDOW_HEATEXCHANGE_H
#define WINDOW_HEATEXCHANGE_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
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
    QLabel * gasInputLabel, * gasOutputLabel, * outputLabel, *gasFlowLabel;
    QLineEdit* gasInputLineedit, * gasOutputLineedit, * outputLineedit, *gasFlowLineedit;
    QGridLayout * gridLayout;
    QVBoxLayout * layout;
    QWidget * gridWidget;
    widget_okcancel * buttonWidget;

};

#endif // WINDOW_HEATEXCHANGE_H
