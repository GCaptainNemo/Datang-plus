#include "window_pump_caso4discharge_base.h"

int caso4DischargePumpWindow::num = 0;

caso4DischargePumpWindow::caso4DischargePumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                                                   float & neshpb, float & nkshpb, QWidget *parent): QDialog(parent),
    yshpb(yshpb), qshpb(qshpb),  hshpb(hshpb), nfshpb(nfshpb), neshpb(neshpb), nkshpb(nkshpb)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    caso4DischargePumpWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("石灰石排出泵");

    layout = new QGridLayout(this);
    this->efficiencyLabel = new QLabel(tr("效率(%):"));
    this->efficiencyLineedt = new QLineEdit;
    this->efficiencyLineedt->setText(QString("%1").arg(round(yshpb * 100)));
    layout->addWidget(efficiencyLabel, 0, 0, 1, 3);
    layout->addWidget(efficiencyLineedt, 0, 3, 1, 3);


    this->flowLabel = new QLabel(tr("流量(m3/h):"));
    this->flowLineedt = new QLineEdit;
    this->flowLineedt->setText(QString("%1").arg(round(qshpb * 10) / 10.0));
    this->flowLineedt->setReadOnly(true);
    layout->addWidget(flowLabel, 1, 0, 1, 3);
    layout->addWidget(flowLineedt, 1, 3, 1, 3);


    this->liftLabel = new QLabel(tr("扬程(m):"));
    this->liftLineedt = new QLineEdit;
    this->liftLineedt->setReadOnly(true);
    this->liftLineedt->setText(QString("%1").arg(round(hshpb)));
    layout->addWidget(liftLabel, 2, 0, 1, 3);
    layout->addWidget(liftLineedt, 2, 3, 1, 3);


    this->shaftPowerLabel = new QLabel(tr("轴功率(kW):"));
    this->shaftPowerLineedt = new QLineEdit;
    this->shaftPowerLineedt->setReadOnly(true);
    this->shaftPowerLineedt->setText(QString("%1").arg(round(nfshpb * 10) / 10));
    layout->addWidget(shaftPowerLabel, 3, 0, 1, 3);
    layout->addWidget(shaftPowerLineedt, 3, 3, 1, 3);


    this->motorPowerLabel = new QLabel(tr("电机功率(kW):"));
    this->motorPowerLineedt = new QLineEdit;
    this->motorPowerLineedt->setReadOnly(true);
    qDebug() << "neshpb = " << neshpb;
    this->motorPowerLineedt->setText(QString("%1").arg(round(neshpb * 10) / 10));
    layout->addWidget(motorPowerLabel, 4, 0, 1, 3);
    layout->addWidget(motorPowerLineedt, 4, 3, 1, 3);



    this->kdLabel = new QLabel(tr("电机功率靠档(kW):"));
    this->kdComboBox = new QComboBox;
    qDebug() << "nkshpb = " << nkshpb;
    utils::setKdComboBox(kdComboBox, neshpb);

    this->kdComboBox->setEditable(false);
    layout->addWidget(kdLabel, 5,  0, 1, 3);
    layout->addWidget(kdComboBox, 5, 3, 1, 3);

    this->okButton = new QPushButton(tr("确定"));
    this->cancelButton = new QPushButton(tr("关闭"));
    layout->addWidget(okButton, 6, 0, 1, 3);
    layout->addWidget(cancelButton, 6, 3, 1, 3);
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    this->show();
}





void caso4DischargePumpWindow::okSLOT()
{
    bool ok;
    float a = this->efficiencyLineedt->text().toFloat(&ok);
    if (ok && a>=0 && a<=100)
    {

        yshpb = a / 100;
        qshpb = gslResultPar::GSL[0][3][1] + 6;
        hshpb = 40;
        nfshpb = qshpb * hshpb * gslResultPar::GSL[0][3][15] * 9.81 / 1000 / 3600 / yshpb;
        nfshpb = ceil(nfshpb * 100) / 100; // 向上取整
        neshpb = nfshpb * (1 + utils::YL(nfshpb)); // 余量计算
        nkshpb = utils::KD(neshpb);    // 靠档

        this->flowLineedt->setText(QString("%1").arg(round(qshpb * 10) / 10.0));
        this->liftLineedt->setText(QString("%1").arg(round(hshpb)));
        this-> shaftPowerLineedt->setText(QString("%1").arg(round(nfshpb * 10) / 10.0));
        this->motorPowerLineedt->setText(QString("%1").arg(round(neshpb * 10) / 10.0));
        utils::setKdComboBox(this->kdComboBox, nkshpb);
        QMessageBox::information(this, tr("信息"), tr("数据修改成功"));

    }
    else
        QMessageBox::warning(this, tr("错误"), tr("数据输入错误"));
}





caso4DischargePumpWindow::~caso4DischargePumpWindow()
{
    caso4DischargePumpWindow::num -= 1;

}
