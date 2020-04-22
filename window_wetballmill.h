#ifndef WINDOW_WETBALLMILL_H
#define WINDOW_WETBALLMILL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QDialog>

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
    QPushButton * okButton, *cancelButton;
    QGridLayout * gridLayout;
    QHBoxLayout * hlayout;
    QVBoxLayout * layout;


};

#endif // WINDOW_WETBALLMILL_H
