#include "window_vacuumbeltdehydrator.h"


int vacuumBeltDehydratorWindow::num = 0;

vacuumBeltDehydratorWindow::vacuumBeltDehydratorWindow(float & Qzhk,
                                                       float & Szhk, float & Nezhk, float & Qzhb,
                                                       float & Nfzhb, float & Nezhb, float & Dlb,
                                                       float & Hlb, float & Vjlb, float & Qlbb,
                                                       float & Hlbb, float & Nelbb, QWidget * parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    vacuumBeltDehydratorWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);
    vacuumBeltWidget = new QWidget;
    layout1 = new QGridLayout(vacuumBeltWidget);
    this->vacuumBeltLabel = new QLabel(tr("真空皮带脱水机"));
    this->maxForceLabel = new QLabel(tr("最大出力(t/h):"));
    this->maxForceLineeidt = new QLineEdit;
    this->maxForceLineeidt->setReadOnly(true);
    this->maxForceLineeidt->setText(QString("%1").arg(Qzhk));
    this->filtAreaLabel = new QLabel(tr("过滤面积(m2):"));
    this->filtAreaLineeidt = new QLineEdit;
    this->filtAreaLineeidt->setReadOnly(true);
    this->filtAreaLineeidt->setText(QString("%1").arg(Szhk));
    this->motorPowerLabel = new QLabel(tr("主驱动电机功率(kW):"));
    this->motorPowerLineeidt = new QLineEdit;
    this->motorPowerLineeidt->setReadOnly(true);
    this->motorPowerLineeidt->setText(QString("%1").arg(Nezhk));
    layout1->addWidget(this->vacuumBeltLabel);
    layout1->addWidget(this->maxForceLabel, 1, 0, 1, 3);
    layout1->addWidget(this->maxForceLineeidt, 1, 3, 1, 3);
    layout1->addWidget(this->filtAreaLabel, 2, 0, 1, 3);
    layout1->addWidget(this->filtAreaLineeidt, 2, 3, 1, 3);
    layout1->addWidget(this->motorPowerLabel, 3, 0, 1, 3);
    layout1->addWidget(this->motorPowerLineeidt, 3, 3, 1, 3);


    this->vacuumPumpWidget = new QWidget;
    this->vacuumPumpLabel = new QLabel(tr("真空泵"));
    this->layout2 = new QGridLayout(vacuumPumpWidget);
    this->vacuumForceLabel = new QLabel(tr("真空泵出力(m3/h):"));
    this->vacuumForceLineedit = new QLineEdit;
    this->vacuumForceLineedit ->setReadOnly(true);
    this->vacuumForceLineedit ->setText(QString("%1").arg(Qzhb));
    this->shaftPowerLabel = new QLabel(tr("轴功率(kW):"));
    this->shaftPowerLineedit = new QLineEdit;
    this->shaftPowerLineedit->setReadOnly(true);
    this->shaftPowerLineedit->setText(QString("%1").arg(Nfzhb));
    this->vacuumPumpPowerLabel= new QLabel(tr("功率(kW):"));
    this->vacuumPumpPowerLineedit = new QLineEdit;
    this->vacuumPumpPowerLineedit->setReadOnly(true);
    this->vacuumPumpPowerLineedit->setText(QString("%1").arg(Nezhb));
    layout2->addWidget(this->vacuumPumpLabel);
    layout2->addWidget(this->vacuumForceLabel, 1, 0, 1, 3);
    layout2->addWidget(this->vacuumForceLineedit, 1, 3, 1, 3);
    layout2->addWidget(this->shaftPowerLabel, 2, 0, 1, 3);
    layout2->addWidget(this->shaftPowerLineedit, 2, 3, 1, 3);
    layout2->addWidget(this->vacuumPumpPowerLabel, 3, 0, 1, 3);
    layout2->addWidget(this->vacuumPumpPowerLineedit, 3, 3, 1, 3);


    this->waterTankWidget = new QWidget;
    this->waterTankLabel = new QLabel(tr("滤布洗水箱"));
    this->layout3 = new QGridLayout(waterTankWidget);
    this->dLabel = new QLabel(tr("直径(m):"));
    this->dLineedit = new QLineEdit;
    this->dLineedit->setReadOnly(true);
    this->dLineedit->setText(QString("%1").arg(Dlb));
    this->hLabel = new QLabel(tr("高度(m):"));
    this->hLineedit = new QLineEdit;
    this->hLineedit ->setReadOnly(true);
    this->hLineedit ->setText(QString("%1").arg(Hlb));
    this->vLabel = new QLabel(tr("有效容积(m3):"));
    this->vLineedit = new QLineEdit;
    this->vLineedit->setReadOnly(true);
    this->vLineedit->setText(QString("%1").arg(Vjlb));
    layout3->addWidget(this->waterTankLabel, 0, 0, 1, 6);
    layout3->addWidget(this->dLabel, 1, 0, 1, 3);
    layout3->addWidget(this->dLineedit, 1, 3, 1, 3);
    layout3->addWidget(this->hLabel, 2, 0, 1, 3);
    layout3->addWidget(this->hLineedit, 2, 3, 1, 3);
    layout3->addWidget(this->vLabel, 3, 0, 1, 3);
    layout3->addWidget(this->vLineedit, 3, 3, 1, 3);



    this->waterPumpWidget = new QWidget;
    this->waterPumpLabel = new QLabel(tr("滤布冲洗水泵"));
    this->layout4 = new QGridLayout(waterPumpWidget);
    this->flowLabel = new QLabel(tr("流量(m3/h):"));
    this->flowLineedit = new QLineEdit;
    this->flowLineedit->setReadOnly(true);
    this->flowLineedit->setText(QString("%1").arg(Qlbb));
    this->liftLabel = new QLabel(tr("扬程(m):"));
    this->liftLineedit = new QLineEdit;
    this->liftLineedit->setReadOnly(true);
    this->liftLineedit->setText(QString("%1").arg(Hlbb));
    this->waterPumpPowerLabel = new QLabel(tr("功率(kW):"));
    this->waterPumpPowerLineedit = new QLineEdit;
    this->waterPumpPowerLineedit->setReadOnly(true);
    this->waterPumpPowerLineedit->setText(QString("%1").arg(Nelbb));
    layout4->addWidget(this->waterPumpLabel, 0, 0, 1, 6);
    layout4->addWidget(this->flowLabel, 1, 0, 1, 3);
    layout4->addWidget(this->flowLineedit, 1, 3, 1, 3);
    layout4->addWidget(this->liftLabel, 2, 0, 1, 3);
    layout4->addWidget(this->liftLineedit, 2, 3, 1, 3);
    layout4->addWidget(this->waterPumpPowerLabel, 3, 0, 1, 3);
    layout4->addWidget(this->waterPumpPowerLineedit, 3, 3, 1, 3);

    vlayout = new QVBoxLayout(this);
    vlayout->addWidget(vacuumBeltWidget);
    vlayout->addWidget(vacuumPumpWidget);
    vlayout->addWidget(waterTankWidget);
    vlayout->addWidget(waterPumpWidget);


    hlayout = new QHBoxLayout;
    this->okButton = new QPushButton(tr("确定"));
    this->cancelButton = new QPushButton(tr("关闭"));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    hlayout->addWidget(this->okButton);
    hlayout->addWidget(this->cancelButton);
    vlayout->addLayout(hlayout);
    this->setWindowTitle(tr("真空皮带脱水机"));
    this->show();
}

vacuumBeltDehydratorWindow::~vacuumBeltDehydratorWindow()
{
    vacuumBeltDehydratorWindow::num -= 1;
}

