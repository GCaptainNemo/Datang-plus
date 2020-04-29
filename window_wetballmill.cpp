#include "window_wetballmill.h"


int wetBallMillWindow::num = 0;

wetBallMillWindow::wetBallMillWindow(float & qmj, float & nfmj, float & nemj, QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    qDebug() << "in wetBallWindow";
    wetBallMillWindow::num += 1;
    this->setWindowTitle(tr("湿式球磨机"));
    this->setAttribute(Qt::WA_DeleteOnClose);


    millMaxForceLabel = new QLabel(tr("磨机最大出力(t/h):"), this);
    rotatePowerLabel = new QLabel(tr("旋转功耗(kW):"), this);
    motorPowerLabel = new QLabel(tr("电机功率(kW)"), this);
    millMaxForceLineedit = new QLineEdit(this);
    rotatePowerLineedit = new QLineEdit(this);
    motorPowerLineedit = new QLineEdit(this);
    millMaxForceLineedit->setText(QString("%1").arg(qmj));
    rotatePowerLineedit->setText(QString("%1").arg(nfmj));
    motorPowerLineedit->setText(QString("%1").arg(nemj));


    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(millMaxForceLabel, 0, 0, 1, 3);
    gridLayout->addWidget(millMaxForceLineedit, 0, 3, 1, 3);
    gridLayout->addWidget(rotatePowerLabel, 1, 0, 1, 3);
    gridLayout->addWidget(rotatePowerLineedit, 1, 3, 1, 3);
    gridLayout->addWidget(motorPowerLabel, 2, 0, 1, 3);
    gridLayout->addWidget(motorPowerLineedit, 2, 3, 1, 3);


    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    layout = new QVBoxLayout(this);
    layout->addLayout(gridLayout);
    layout->addWidget(buttonWidget);
    this->show();

}


wetBallMillWindow::~wetBallMillWindow()
{
    wetBallMillWindow::num -= 1;
}


void wetBallMillWindow::okSLOT()
{

}
