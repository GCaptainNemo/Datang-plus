#ifndef WASTEH2OROTATIONALFLOW_WINDOW_H
#define WASTEH2OROTATIONALFLOW_WINDOW_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include "par_equip.h"
#include "widget_okcancel.h"


class wasteH2OrotationalFlow_window : public QDialog
{
    Q_OBJECT
public:
    explicit wasteH2OrotationalFlow_window(float & qfx, float & xzfx,QWidget *parent = nullptr);
    ~wasteH2OrotationalFlow_window();
    static int num;

signals:

public slots:
    void okSLOT();

    
private:
    widget_okcancel * buttonWidget;
    QGridLayout * layout;
    QLabel * qfxLabel, * xzfxLabel;
    QPushButton * okButton, *cancelButton;
    QLineEdit * qfxLineedit, * xzfxLineedit;
    float & qfx;
    float & xzfx;
};

#endif // WASTEH2OROTATIONALFLOW_WINDOW_H
