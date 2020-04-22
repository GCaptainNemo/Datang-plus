#ifndef WINDOW_VACUUMBELTDEHYDRATOR_H
#define WINDOW_VACUUMBELTDEHYDRATOR_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class vacuumBeltDehydratorWindow : public QDialog
{
    Q_OBJECT
public:
    explicit vacuumBeltDehydratorWindow(float & Qzhk,
                                        float & Szhk, float & Nezhk, float & Qzhb,
                                        float & Nfzhb, float & Nezhb, float & Dlb,
                                        float & Hlb, float & Vjlb, float & Qlbb,
                                        float & Hlbb, float & Nelbb, QWidget *parent = nullptr);
    static int num;
    ~vacuumBeltDehydratorWindow();
    
signals:

public slots:
    
    
private:
    
    QLabel * vacuumBeltLabel, *vacuumPumpLabel, *waterTankLabel, *waterPumpLabel;

    QPushButton * okButton, *cancelButton;
    QLabel * maxForceLabel, * filtAreaLabel, * motorPowerLabel; 
    QLineEdit * maxForceLineeidt, * filtAreaLineeidt, * motorPowerLineeidt; 
    
    QLabel * vacuumForceLabel, * shaftPowerLabel, *vacuumPumpPowerLabel;
    QLineEdit * vacuumForceLineedit, * shaftPowerLineedit, *vacuumPumpPowerLineedit;
    
    QLabel * dLabel, * hLabel, *vLabel;
    QLineEdit * dLineedit, * hLineedit, *vLineedit;
    
    QLabel * flowLabel, *liftLabel, * waterPumpPowerLabel;
    QLineEdit * flowLineedit, *liftLineedit, * waterPumpPowerLineedit;
     
    QWidget * vacuumBeltWidget, *vacuumPumpWidget, *waterTankWidget, *waterPumpWidget;
    QGridLayout * layout1, *layout2, *layout3, *layout4;
    
    QVBoxLayout * vlayout;
    QHBoxLayout * hlayout;
};

#endif // WINDOW_VACUUMBELTDEHYDRATOR_H
