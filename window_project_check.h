#ifndef CHECKPROJECTWINDOW_H
#define CHECKPROJECTWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>
#include <QDialog>

class checkPjWindow : public QDialog
{
    Q_OBJECT
public:
    explicit checkPjWindow(QWidget *parent = nullptr);
    ~checkPjWindow();
    static int num;

signals:

public slots:
    void operatingModeSLOT();


private:
    QTextEdit * checkOpinionTextedit;
    QRadioButton * passRadioButton;
    QRadioButton * recalculateRadioButton;
    QPushButton * okButton;
    QPushButton * cancelButton;
    QButtonGroup * bg;
    QVBoxLayout * layout;
    QHBoxLayout * hlayout1;
    QHBoxLayout * hlayout2;


};

#endif // CHECKPROJECTWINDOW_H
