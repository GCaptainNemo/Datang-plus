#ifndef WINDOW_SYSTEMCONFIGURATION_H
#define WINDOW_SYSTEMCONFIGURATION_H

#include <QWidget>
#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QRadioButton>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QDebug>
#include <QVariant>
#include "par_equip.h"
#include "par_pinf.h"

class systemConfigurationWindow : public QDialog
{
    Q_OBJECT
public:
    static int pzh;
    explicit systemConfigurationWindow(QWidget *parent = nullptr);
    static int num;
    ~systemConfigurationWindow();
signals:

public slots:
    void okSLOT();
    void group1SLOT(int p);
    void group2SLOT(int p);
    void hideAddSLOT(const int &p);

protected:
    QCheckBox * gghSystemCheckbox, * pAirBlowerCheckbox, * vacuumCheckbox, *wasteH2Ocheckbox, * waterPumpCheckbox;
    QLabel * styleLabel;
    QRadioButton * wetCaco3Radiobutton, * caco3Radiobutton;
    QCheckBox * proH2Ocheckbox;
    QLabel * addLabel;
    QComboBox * addCombobox;
    QPushButton * okButton, *cancelButton;

    QWidget *widget1, *widget2, *widget3, *widget4;
    QGridLayout *gridLayout2, *gridLayout3, *gridLayout4;
    QVBoxLayout * layout, *vlayout1;
    QButtonGroup *group1, *group2;
    void initButtonState();
};

#endif // WINDOW_SYSTEMCONFIGURATION_H
