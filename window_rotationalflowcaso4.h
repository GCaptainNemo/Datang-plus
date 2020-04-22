#ifndef CASO4ROTATIONALFLOW_WINDOW_H
#define CASO4ROTATIONALFLOW_WINDOW_H

#include <QWidget>
#include <QDialog>
#include "window_rotationalflowwasteh2o_base.h"

class caso4RotationalFlow_window : public wasteH2OrotationalFlow_window
{
    Q_OBJECT
public:
    explicit caso4RotationalFlow_window(float & qshgx, float & xzshgx, QWidget *parent = nullptr):wasteH2OrotationalFlow_window(qshgx, xzshgx, parent){
        this->setWindowTitle(tr("石膏旋流器"));
    }

signals:


public slots:

};

#endif // CASO4ROTATIONALFLOW_WINDOW_H
