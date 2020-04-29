#ifndef WINDOW_OXIDATIONAIBLOWER_H
#define WINDOW_OXIDATIONAIBLOWER_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>

#include <QComboBox>
#include "utils.h"
#include "par_equip.h"
#include "par_gasresult.h"
#include "par_gslresult.h"
#include "widget_okcancel.h"

class oxidationAiBlowerWindow : public QDialog
{
    Q_OBJECT
public:
    explicit oxidationAiBlowerWindow(QWidget *parent = nullptr);
    static int num ;
    ~oxidationAiBlowerWindow();

signals:

public slots:
    void okSLOT();

protected:
    QLabel * efficiencyLabel, *wetFlowLabel, *windStyleFlowLabel, *pressureUpLabel, *shaftPowerLabel, *motorPowerLabel, *kdLabel;
    QLineEdit * efficiencyLineedit, *wetFlowLineedit, *windStyleFlowLineedit, *pressureUpLineedit, *shaftPowerLineedit, *motorPowerLineedit;

    QComboBox * kdComboBox;
    QGridLayout * gridLayout;

    widget_okcancel * buttonWidget;
};

#endif // WINDOW_OXIDATIONAIBLOWER_H
