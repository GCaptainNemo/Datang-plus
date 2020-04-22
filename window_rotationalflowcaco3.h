#ifndef CACO3ROTATIONALFLOW_WINDOW_H
#define CACO3ROTATIONALFLOW_WINDOW_H


#include <QWidget>
#include <QDialog>
#include "window_rotationalflowwasteh2o_base.h"

class caco3RotationalFlow_window : public wasteH2OrotationalFlow_window
{
    Q_OBJECT
public:
    explicit caco3RotationalFlow_window(float & qshhx, float & xzshhx, QWidget *parent = nullptr):wasteH2OrotationalFlow_window(qshhx, xzshhx, parent){
        this->setWindowTitle(tr("石灰石旋流器"));
    }

signals:


public slots:

};





#endif // CACO3ROTATIONALFLOW_WINDOW_H
