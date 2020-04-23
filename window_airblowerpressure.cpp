#include "window_airblowerpressure.h"


int pressureAirBlowerWindow::num = 0;

pressureAirBlowerWindow::pressureAirBlowerWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    pressureAirBlowerWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("增压风机"));


    gridLayout = new QGridLayout(this);
    this->efficiencyLabel = new QLabel(tr("效率(%):"));
    this->efficiencyLineedit = new QLineEdit;
    this->efficiencyLineedit->setText(QString("%1").arg(round(flueGasSystem::Yfan * 100)));
    gridLayout->addWidget(efficiencyLabel, 0, 0, 1, 3);
    gridLayout->addWidget(efficiencyLineedit, 0, 3, 1, 3);


    this->flowLabel = new QLabel(tr("实际流量(m3/h):"));
    this->flowLineedit = new QLineEdit;
    this->flowLineedit->setText(QString("%1").arg(round(flueGasSystem::Qfan * 10) / 10.0));
    this->flowLineedit->setReadOnly(true);
    gridLayout->addWidget(flowLabel, 1, 0, 1, 3);
    gridLayout->addWidget(flowLineedit, 1, 3, 1, 3);


    this->pressureUpLabel = new QLabel(tr("压升(mbar):"));
    this->pressureUpLineedit = new QLineEdit;

    this->pressureUpLineedit->setText(QString("%1").arg(round(flueGasSystem::Pfan * 10) / 10.0));
    this->pressureUpLineedit->setReadOnly(true);
    gridLayout->addWidget(pressureUpLabel, 2, 0, 1, 3);
    gridLayout->addWidget(pressureUpLineedit, 2, 3, 1, 3);


    this->shaftPowerLabel = new QLabel(tr("轴功率(kW):"));
    this->shaftPowerLineedit = new QLineEdit;
    this->shaftPowerLineedit->setReadOnly(true);

    this->shaftPowerLineedit->setText(QString("%1").arg(round(flueGasSystem::Nffan * 10) / 10));
    gridLayout->addWidget(shaftPowerLabel, 3, 0, 1, 3);
    gridLayout->addWidget(shaftPowerLineedit, 3, 3, 1, 3);


    this->tbFlowLabel = new QLabel(tr("T.B.点流量(m3/h):"));
    this->tbFlowLineedit = new QLineEdit;
    this->tbFlowLineedit->setReadOnly(true);

    this->tbFlowLineedit->setText(QString("%1").arg(round(flueGasSystem::Qfand * 10) / 10.0));
    gridLayout->addWidget(tbFlowLabel, 4, 0, 1, 3);
    gridLayout->addWidget(tbFlowLineedit, 4, 3, 1, 3);


    this->tbPressureUpLabel = new QLabel(tr("T.B.点压升(mbar):"));
    this->tbPressureUpLineedit = new QLineEdit;
    this->tbPressureUpLineedit->setReadOnly(true);

    this->tbPressureUpLineedit->setText(QString("%1").arg(round(flueGasSystem::Pfand * 10) / 10.0));
    gridLayout->addWidget(tbPressureUpLabel, 5, 0, 1, 3);
    gridLayout->addWidget(tbPressureUpLineedit, 5, 3, 1, 3);


    this->tbShaftPowerLabel = new QLabel(tr("T.B.点轴功率(kW):"));
    this->tbShaftPowerLineedit = new QLineEdit;
    this->tbShaftPowerLineedit->setReadOnly(true);

    this->tbShaftPowerLineedit->setText(QString("%1").arg(round(flueGasSystem::Ndfan * 10) / 10.0));
    gridLayout->addWidget(tbShaftPowerLabel, 6, 0, 1, 3);
    gridLayout->addWidget(tbShaftPowerLineedit, 6, 3, 1, 3);


    this->motorPowerLabel = new QLabel(tr("电机功率(kW):"));
    this->motorPowerLineedit = new QLineEdit;
    this->motorPowerLineedit->setReadOnly(true);
    this->motorPowerLineedit->setText(QString("%1").arg(round(flueGasSystem::Nefan * 10) / 10.0));
    gridLayout->addWidget(motorPowerLabel, 7, 0, 1, 3);
    gridLayout->addWidget(motorPowerLineedit, 7, 3, 1, 3);


    this->kdLabel = new QLabel(tr("电机功率靠档(kW):"));
    this->kdComboBox = new QComboBox;
    utils::setKdComboBox(kdComboBox, flueGasSystem::Nefan);
    this->kdComboBox->setEditable(false);
    gridLayout->addWidget(kdLabel, 8,  0, 1, 3);
    gridLayout->addWidget(kdComboBox, 8, 3, 1, 3);

    this->okButton = new QPushButton(tr("确定"));
    this->cancelButton = new QPushButton(tr("关闭"));
    gridLayout->addWidget(okButton, 9, 0, 1, 3);
    gridLayout->addWidget(cancelButton, 9, 3, 1, 3);
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    this->show();
}


pressureAirBlowerWindow ::~pressureAirBlowerWindow()
{
    pressureAirBlowerWindow ::num -= 1;
}


void pressureAirBlowerWindow ::okSLOT()
{
    bool ok1, ok2;
    float a = this->efficiencyLineedit->text().toFloat(&ok1);
    float b = this->pressureUpLineedit->text().toFloat(&ok2);

    if (ok1 && a>=0 && a<=100)
    {
        flueGasSystem::Yfan = a / 100.0;
        flueGasSystem::Pfans = b;

        flueGasSystem::Qfan = gasResultPar::Gas[0][0][5];
        flueGasSystem::Qfand = 1.1 * flueGasSystem::Qfan;

        flueGasSystem::Pfand = 1.2 * flueGasSystem::Pfans;
        flueGasSystem::Pfand = ceil(flueGasSystem::Pfand * 10) / 10.0;

        flueGasSystem::Nffan = flueGasSystem::Qfan * flueGasSystem::Pfans * 100 / 1000 / 3600
                / flueGasSystem::Yfan / 0.99;
        flueGasSystem::Nffan = ceil(flueGasSystem::Nffan* 10) / 10.0;

        flueGasSystem::Ndfan = flueGasSystem::Qfand * flueGasSystem::Pfand * 100 / 1000 / 3600
                / flueGasSystem::Yfan / 0.99;
        flueGasSystem::Nefan = flueGasSystem::Ndfan * 1.15;

        flueGasSystem::Nkfan = utils::KD(flueGasSystem::Nefan);

        this->efficiencyLineedit->setText(QString("%1").arg(round(flueGasSystem::Yfan * 100)));
        this->flowLineedit->setText(QString("%1").arg(round(flueGasSystem::Qfan * 10) / 10.0));
        this->pressureUpLineedit->setText(QString("%1").arg(round(flueGasSystem::Pfan * 10) / 10.0));
        this->shaftPowerLineedit->setText(QString("%1").arg(round(flueGasSystem::Nffan * 10) / 10));
        this->tbFlowLineedit->setText(QString("%1").arg(round(flueGasSystem::Qfand * 10) / 10.0));
        this->tbPressureUpLineedit->setText(QString("%1").arg(round(flueGasSystem::Pfand * 10) / 10.0));
        this->tbShaftPowerLineedit->setText(QString("%1").arg(round(flueGasSystem::Ndfan * 10) / 10.0));
        this->motorPowerLineedit->setText(QString("%1").arg(round(flueGasSystem::Nefan * 10) / 10.0));
        utils::setKdComboBox(this->kdComboBox, flueGasSystem::Nkfan);
        QMessageBox::information(this, tr("信息"), tr("数据修改成功"));
    }
    else
        QMessageBox::warning(this, tr("错误"), tr("数据输入错误"));
}





