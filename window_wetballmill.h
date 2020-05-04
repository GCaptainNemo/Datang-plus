#ifndef WINDOW_WETBALLMILL_H
#define WINDOW_WETBALLMILL_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QDialog>
#include "widget_okcancel.h"

class wetBallMillWindow : public QDialog
{
    Q_OBJECT
public:
    explicit wetBallMillWindow(float & qmj, float & nfmj, float & nemj, QWidget *parent = nullptr);
    static int num;
    ~wetBallMillWindow();
signals:

public slots:
    void okSLOT();

protected:
    QLabel * millMaxForceLabel, * rotatePowerLabel, * motorPowerLabel;
    QLineEdit* millMaxForceLineedit, * rotatePowerLineedit, * motorPowerLineedit;
    widget_okcancel * buttonWidget;
    QGridLayout * gridLayout;
    QVBoxLayout * layout;


};

#endif // WINDOW_WETBALLMILL_H
