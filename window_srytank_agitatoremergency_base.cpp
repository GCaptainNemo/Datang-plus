#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_srytank_agitatoremergency_base.h"

int emergencySryTankAndAgitatorWindow::num = 0;

emergencySryTankAndAgitatorWindow::emergencySryTankAndAgitatorWindow(float & Dshg, float & Hshg, float & HDshg, float & Vshg, float & VTshg, float & Yshg,
                                                                     float & Nbshg, float & Nfshg, float & Neshg, float & Nkshg, QWidget *parent) :
    Dshg(Dshg), Hshg(Hshg), HDshg(HDshg), Vshg(Vshg), VTshg(VTshg), Yshg(Yshg), Nbshg(Nbshg), Nfshg(Nfshg), Neshg(Neshg), Nkshg(Nkshg), QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    this->setWindowTitle(tr("事故浆液箱及搅拌器"));
    emergencySryTankAndAgitatorWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 事故浆液箱

    this->emeSryTankWidget = new QWidget(this);
    this->layout1 = new QGridLayout(this->emeSryTankWidget);
    emeSryTankLabel = new QLabel(tr("事故浆液箱"), emeSryTankWidget);
    dLabel = new QLabel(tr("直径(m):"), emeSryTankWidget);
    hLabel = new QLabel(tr("高度(m):"), emeSryTankWidget);
    hdLabel = new QLabel(tr("高径比"), emeSryTankWidget);
    veLabel = new QLabel(tr("有效容积(m3):"), emeSryTankWidget);
    vLabel = new QLabel(tr("总容积(m3)"), emeSryTankWidget);
    vevLabel = new QLabel(tr("有效/总容积(%)"), emeSryTankWidget);
    dLineedit= new QLineEdit(emeSryTankWidget);
    hLineedit= new QLineEdit(emeSryTankWidget);
    hdLineedit = new QLineEdit(emeSryTankWidget);
    hdLineedit->setReadOnly(true);
    veLineedit = new QLineEdit(emeSryTankWidget);
    veLineedit->setReadOnly(true);
    vLineedit = new QLineEdit(emeSryTankWidget);
    vLineedit->setReadOnly(true);
    vevLineedit = new QLineEdit(emeSryTankWidget);
    this->dLineedit->setText(QString("%1").arg(round(this->Dshg * 10) / 10));
    this->hLineedit->setText(QString("%1").arg(round(this->Hshg * 10) / 10));
    this->hdLineedit->setText(QString("%1").arg(round(this->HDshg * 10) / 10));
    this->veLineedit->setText(QString("%1").arg(round(this->Vshg)));
    this->vLineedit->setText(QString("%1").arg(round(this->VTshg)));
    this->vevLineedit->setText(QString("%1").arg(round(this->Yshg * 100)));


    this->layout1->addWidget(this->emeSryTankLabel, 0, 0, 1, 6);
    this->layout1->addWidget(this->dLabel, 1, 0, 1, 3);
    this->layout1->addWidget(this->dLineedit, 1, 3, 1, 3);
    this->layout1->addWidget(this->hLabel, 2, 0, 1, 3);
    this->layout1->addWidget(this->hLineedit, 2, 3, 1, 3);
    this->layout1->addWidget(this->hdLabel, 3, 0, 1, 3);
    this->layout1->addWidget(this->hdLineedit, 3, 3, 1, 3);
    this->layout1->addWidget(this->veLabel, 4, 0, 1, 3);
    this->layout1->addWidget(this->veLineedit, 4, 3, 1, 3);
    this->layout1->addWidget(this->vLabel, 5, 0, 1, 3);
    this->layout1->addWidget(this->vLineedit, 5, 3, 1, 3);
    this->layout1->addWidget(this->vevLabel, 6, 0, 1, 3);
    this->layout1->addWidget(this->vevLineedit, 6, 3, 1, 3);

    // 事故浆液箱搅拌器

    this->emeAgitatorWidget = new QWidget(this);
    this->emeAgitatorLabel = new QLabel(tr("事故浆液箱搅拌器"), emeAgitatorWidget);
    this->rPowerLabel = new QLabel(tr("比功率(kW):"), emeAgitatorWidget);
    this->shaftPowerLabel = new QLabel(tr("轴功率(kW):"), emeAgitatorWidget);
    this->motorPowerLabel = new QLabel(tr("电机功率(kW):"), emeAgitatorWidget);
    this->kdLabel = new QLabel(tr("电机功率靠档(kW):"), emeAgitatorWidget);
    this->rPowerLineedit = new QLineEdit(emeAgitatorWidget);
    this->rPowerLineedit->setReadOnly(true);
    this->shaftPowerLineedit= new QLineEdit(emeAgitatorWidget);
    this->shaftPowerLineedit->setReadOnly(true);
    this->motorPowerLineedit= new QLineEdit(emeAgitatorWidget);
    this->motorPowerLineedit->setReadOnly(true);
    this->kdComBox = new QComboBox(emeAgitatorWidget);
    this->kdComBox->setEditable(false);
    utils::setKdComboBox(kdComBox, Nkshg);
    this->rPowerLineedit->setText(QString("%1").arg(round(this->Nbshg * 1000) / 1000));
    this->shaftPowerLineedit->setText(QString("%1").arg(round(this->Nfshg * 10) / 10));
    this->motorPowerLineedit->setText(QString("%1").arg(round(this->Neshg * 10) / 10));

    this->layout2 = new QGridLayout(this->emeAgitatorWidget);
    this->layout2->addWidget(this->emeAgitatorLabel, 0, 0, 1, 6);
    this->layout2->addWidget(this->rPowerLabel, 1, 0, 1, 3);
    this->layout2->addWidget(this->rPowerLineedit, 1, 3, 1, 3);
    this->layout2->addWidget(this->shaftPowerLabel, 2, 0, 1, 3);
    this->layout2->addWidget(this->shaftPowerLineedit, 2, 3, 1, 3);
    this->layout2->addWidget(this->motorPowerLabel, 3, 0, 1, 3);
    this->layout2->addWidget(this->motorPowerLineedit, 3, 3, 1, 3);
    this->layout2->addWidget(this->kdLabel, 4, 0, 1, 3);
    this->layout2->addWidget(this->kdComBox, 4, 3, 1, 3);



    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));



    this->layout = new QVBoxLayout(this);
    this->layout->addWidget(this->emeSryTankWidget);
    this->layout->addWidget(this->emeAgitatorWidget);
    this->layout->addWidget(this->buttonWidget);
    this->show();
}

emergencySryTankAndAgitatorWindow::~emergencySryTankAndAgitatorWindow()
{
    emergencySryTankAndAgitatorWindow::num -= 1;
}


void emergencySryTankAndAgitatorWindow::okSLOT()
{
    bool ok1,ok2, ok3;
    float a = this->vevLineedit->text().toFloat(&ok1);
    float d = this->dLineedit->text().toFloat(&ok2);
    float h = this->hLineedit->text().toFloat(&ok3);
    if (ok1 && ok2 && ok3 && a>=0 && a<=100 && d > 0 && h >0)
    {

        Yshg = a / 100;
        Dshg = d;
        Hshg = h;
        HDshg = h / d;
        emergencySlurrySystem::VTjshg = ceil(3.1415 * pow(Dshg / 2, 2) * Hshg);
        emergencySlurrySystem::Vjshg = Yshg * emergencySlurrySystem::VTjshg;
        this->veLineedit->setText(QString("%1").arg(round(Vshg)));
        this->vLineedit->setText(QString("%1").arg(round(VTshg)));
        this->hdLineedit->setText(QString("%1").arg(round(HDshg * 10) / 10));
        this->dLineedit->setText(QString("%1").arg(round(Dshg * 10) / 10));
        this->hLineedit->setText(QString("%1").arg(round(Hshg * 10) / 10));
        this->vevLineedit->setText(QString("%1").arg(round(Yshg * 100)));

        qDebug() << "GSL[0][1][16] = " << gslResultPar::GSL[0][1][16];
        Nbshg = emergencySlurrySystem::BGL(gslResultPar::GSL[0][1][16]) / 1000.0; // 比功率
        Nfshg = ceil(emergencySlurrySystem::Vjshg / 3 * Nbshg * 10) / 10;    //轴功率
        Neshg = Nfshg * (1 + utils::YL(Nfshg)) / 0.98;                       //电机功率
        Nkshg = utils::KD(Neshg);                                            //电机功率靠档


        this->rPowerLineedit->setText(QString("%1").arg(round(this->Nbshg * 1000) / 1000));
        this->shaftPowerLineedit->setText(QString("%1").arg(round(this->Nfshg * 10) / 10));
        this->motorPowerLineedit->setText(QString("%1").arg(round(this->Neshg * 10) / 10));
        utils::setKdComboBox(this->kdComBox, Nkshg);
        QMessageBox::information(this, tr("信息"), tr("数据修改成功"));

    }
    else
        QMessageBox::warning(this, tr("错误"), tr("数据输入错误"));
}


