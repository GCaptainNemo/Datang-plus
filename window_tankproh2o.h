#ifndef WINDOW_TANKPROH2O_H
#define WINDOW_TANKPROH2O_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>

class proH2OtankWindow: public QDialog
{
    Q_OBJECT
public:
    explicit proH2OtankWindow(float & Qgy, int & FGDnum, float & Tgy, float & Dgy,
                              float & Hgy, float & HDgy,  float & Vjgy, float & VTjgy,  float & Ygy, QWidget *parent = nullptr);
    static int num;
    ~proH2OtankWindow();


signals:

public slots:
    void okSLOT();

protected:
    QWidget * proWaterTankWidget;
    QLabel * sryTankLabel;
    QLabel  *singleFurnaceLabel, * fgdNumLabel, *bufferTimeLabel,  * dLabel, *hLabel, *hdLabel, *veLabel, *vLabel, * vevLabel;
    QLineEdit *singleFurnaceLineedit, *fgdNumLineedit, *bufferTimeLineedit,  * dLineedit, *hLineedit, *hdLineedit, *veLineedit, *vLineedit, * vevLineedit;
    QGridLayout *layout1;
    QHBoxLayout * hlayout;
    QPushButton * okButton, *calButton, *cancelButton;
    QVBoxLayout * layout;
    float &Qgy, &Tgy, &Dgy, &Hgy, &HDgy, &Vjgy, &VTjgy, &Ygy;
    int & FGDnum;
};

#endif // WINDOW_TANKPROH2O_H
