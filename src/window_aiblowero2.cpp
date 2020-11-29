#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_aiblowero2.h"

int oxidationAiBlowerWindow::num = 0;

oxidationAiBlowerWindow::oxidationAiBlowerWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    oxidationAiBlowerWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("氧化风机"));


    gridLayout = new QGridLayout(this);
    this->efficiencyLabel = new QLabel(tr("效率(%):"), this);
    this->efficiencyLineedit = new QLineEdit(this);
    this->efficiencyLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Yyang * 100)));
    gridLayout->addWidget(efficiencyLabel, 0, 0, 1, 3);
    gridLayout->addWidget(efficiencyLineedit, 0, 3, 1, 3);



    this->wetFlowLabel = new QLabel(tr("湿基标态流量(m3/h):"), this);
    this->wetFlowLineedit = new QLineEdit(this);
    this->wetFlowLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Qyang)));
    this->wetFlowLineedit->setReadOnly(true);
    gridLayout->addWidget(wetFlowLabel, 1, 0, 1, 3);
    gridLayout->addWidget(wetFlowLineedit, 1, 3, 1, 3);


    this->windStyleFlowLabel = new QLabel(tr("风机选型流量(m3/h):"), this);
    this->windStyleFlowLineedit = new QLineEdit(this);
    this->windStyleFlowLineedit->setReadOnly(true);
    this->windStyleFlowLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::QXyang)));
    gridLayout->addWidget(windStyleFlowLabel, 2, 0, 1, 3);
    gridLayout->addWidget(windStyleFlowLineedit, 2, 3, 1, 3);


    this->pressureUpLabel = new QLabel(tr("压升(mbar):"), this);
    this->pressureUpLineedit = new QLineEdit(this);
    this->pressureUpLineedit->setReadOnly(true);
    this->pressureUpLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Pyang)));
    gridLayout->addWidget(pressureUpLabel, 3, 0, 1, 3);
    gridLayout->addWidget(pressureUpLineedit, 3, 3, 1, 3);



    this->shaftPowerLabel = new QLabel(tr("轴功率(kW):"), this);
    this->shaftPowerLineedit = new QLineEdit(this);
    this->shaftPowerLineedit->setReadOnly(true);
    this->shaftPowerLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Nfyang * 10) / 10));
    gridLayout->addWidget(shaftPowerLabel, 4, 0, 1, 3);
    gridLayout->addWidget(shaftPowerLineedit, 4, 3, 1, 3);


    this->motorPowerLabel = new QLabel(tr("电机功率(kW):"), this);
    this->motorPowerLineedit = new QLineEdit(this);
    this->motorPowerLineedit->setReadOnly(true);

    this->motorPowerLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Neyang * 10) / 10));
    gridLayout->addWidget(motorPowerLabel, 5, 0, 1, 3);
    gridLayout->addWidget(motorPowerLineedit, 5, 3, 1, 3);

    this->kdLabel = new QLabel(tr("电机功率靠档(kW):"), this);
    this->kdComboBox = new QComboBox(this);
    utils::setKdComboBox(kdComboBox, so2AbsorbSystem::Neyang);

    this->kdComboBox->setEditable(false);
    gridLayout->addWidget(kdLabel, 6,  0, 1, 3);
    gridLayout->addWidget(kdComboBox, 6, 3, 1, 3);


    buttonWidget = new widget_okcancel(this);
    gridLayout->addWidget(buttonWidget, 7, 0, 1, 6);
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    this->show();
}

oxidationAiBlowerWindow::~oxidationAiBlowerWindow()
{
    oxidationAiBlowerWindow::num -= 1;
}


void oxidationAiBlowerWindow::okSLOT()
{
    bool ok;
    float a = this->efficiencyLineedit->text().toFloat(&ok);
    if (ok && a>=0 && a<=100)
    {
        so2AbsorbSystem::Yyang = a / 100.0;
        so2AbsorbSystem::Qyang = gasResultPar::Gas[0][6][0];
        so2AbsorbSystem::QXyang = ceil(round(so2AbsorbSystem::Qyang * 0.01) / 0.01);
        so2AbsorbSystem::Pyang = gslResultPar::GSL[0][3][15] * 9.8 * absorberSystem::B/ 100 + 200;
        so2AbsorbSystem::Pyang = ceil(so2AbsorbSystem::Pyang * 10) / 10.0;
        so2AbsorbSystem::Nfyang = so2AbsorbSystem::Qyang* so2AbsorbSystem::Pyang *
                100 / 1000.0 / 3600 / so2AbsorbSystem::Yyang / 0.99;
        so2AbsorbSystem::Nfyang  = ceil(so2AbsorbSystem::Nfyang  * 10) / 10.0;
        so2AbsorbSystem::Neyang = so2AbsorbSystem::Nfyang * 1.15;
        so2AbsorbSystem::Nkyang = utils::KD(so2AbsorbSystem::Neyang);

        this->wetFlowLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Qyang )));
        this->windStyleFlowLineedit ->setText(QString("%1").arg(round(so2AbsorbSystem::QXyang)));
        this-> pressureUpLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Pyang)));
        this->shaftPowerLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Nfyang * 10) / 10.0));
        this->motorPowerLineedit->setText(QString("%1").arg(round(so2AbsorbSystem::Neyang * 10) / 10.0));
        utils::setKdComboBox(this->kdComboBox, so2AbsorbSystem::Nkyang);
        QMessageBox::information(this, tr("信息"), tr("数据修改成功"));
    }
    else
        QMessageBox::warning(this, tr("错误"), tr("数据输入错误"));
}


