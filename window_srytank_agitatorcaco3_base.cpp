#include "window_srytank_agitatorcaco3_base.h"

int caco3SryTankAndAgitatorWindow::num = 0;

caco3SryTankAndAgitatorWindow::caco3SryTankAndAgitatorWindow(float & Qsj, int & FGDnum, float & Tsj, float & Dsj, float & Hsj, float & HDsj,  float & Vjsj, float & VTjsj, float & Ysj,
                                                             float & Nbsj, float & Nfsj, float & Nesj, float & Nksj, QWidget *parent):
    Qsj(Qsj), FGDnum(FGDnum), Tsj(Tsj),  Dsj(Dsj), Hsj(Hsj), HDsj(HDsj), Vjsj(Vjsj), VTjsj(VTjsj), Ysj(Ysj), Nbsj(Nbsj), Nfsj(Nfsj), Nesj(Nesj), Nksj(Nksj), QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    this->setWindowTitle(tr("石灰石浆液箱及搅拌器"));
    caco3SryTankAndAgitatorWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 事故浆液箱

    initSryTank();

    // 事故浆液箱搅拌器

    initAgitator();

    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    this->layout = new QVBoxLayout(this);
    this->layout->addWidget(this->sryTankWidget);
    this->layout->addWidget(this->agitatorWidget);
    this->layout->addWidget(this->buttonWidget);
    this->show();
}

caco3SryTankAndAgitatorWindow::~caco3SryTankAndAgitatorWindow()
{
    caco3SryTankAndAgitatorWindow::num -= 1;
}


void caco3SryTankAndAgitatorWindow::initSryTank()
{
    this->sryTankWidget = new QWidget(this);
    this->layout1 = new QGridLayout(this->sryTankWidget);
    sryTankLabel = new QLabel(tr("石灰石浆液箱"), sryTankWidget);


    singleFurnaceLabel = new QLabel(tr("单台炉耗量(m3/h):"), sryTankWidget);
    fgdNumLabel = new QLabel(tr("FGD数量:"), sryTankWidget);
    bufferTimeLabel = new QLabel(tr("要求的缓冲时间(h):"), sryTankWidget);
    dLabel = new QLabel(tr("直径(m):"), sryTankWidget);
    hLabel = new QLabel(tr("高度(m):"), sryTankWidget);
    hdLabel = new QLabel(tr("高径比"), sryTankWidget);
    veLabel = new QLabel(tr("有效容积(m3):"), sryTankWidget);
    vLabel = new QLabel(tr("总容积(m3)"), sryTankWidget);
    vevLabel = new QLabel(tr("有效/总容积(%)"), sryTankWidget);
    singleFurnaceLineedit = new QLineEdit(sryTankWidget);
    fgdNumLineedit= new QLineEdit(sryTankWidget);
    bufferTimeLineedit = new QLineEdit(sryTankWidget);
    dLineedit= new QLineEdit(sryTankWidget);
    hLineedit= new QLineEdit(sryTankWidget);
    hdLineedit = new QLineEdit(sryTankWidget);
    hdLineedit->setReadOnly(true);
    veLineedit = new QLineEdit(sryTankWidget);
    veLineedit->setReadOnly(true);
    vLineedit = new QLineEdit(sryTankWidget);
    vLineedit->setReadOnly(true);
    vevLineedit = new QLineEdit(sryTankWidget);
    this->singleFurnaceLineedit->setText(QString("%1").arg(round(this->Qsj* 10) / 10));
    this->fgdNumLineedit->setText(QString("%1").arg(round(this->FGDnum)));
    this->bufferTimeLineedit->setText(QString("%1").arg(round(this->Tsj* 10) / 10));
    this->dLineedit->setText(QString("%1").arg(round(this->Dsj * 10) / 10));
    this->hLineedit->setText(QString("%1").arg(round(this->Hsj * 10) / 10));
    this->hdLineedit->setText(QString("%1").arg(round(this->HDsj * 10) / 10));
    this->veLineedit->setText(QString("%1").arg(round(this->Vjsj)));
    this->vLineedit->setText(QString("%1").arg(round(this->VTjsj)));
    this->vevLineedit->setText(QString("%1").arg(round(this->Ysj * 100)));

    this->layout1->addWidget(this->sryTankLabel, 0, 0, 1, 6);
    this->layout1->addWidget(this->singleFurnaceLabel, 1, 0, 1, 3);
    this->layout1->addWidget(this->singleFurnaceLineedit, 1, 3, 1, 3);
    this->layout1->addWidget(this->fgdNumLabel, 2, 0, 1, 3);
    this->layout1->addWidget(this->fgdNumLineedit, 2, 3, 1, 3);
    this->layout1->addWidget(this->bufferTimeLabel, 3, 0, 1, 3);
    this->layout1->addWidget(this->bufferTimeLineedit, 3, 3, 1, 3);
    this->layout1->addWidget(this->dLabel, 4, 0, 1, 3);
    this->layout1->addWidget(this->dLineedit, 4, 3, 1, 3);
    this->layout1->addWidget(this->hLabel, 5, 0, 1, 3);
    this->layout1->addWidget(this->hLineedit, 5, 3, 1, 3);
    this->layout1->addWidget(this->hdLabel, 6, 0, 1, 3);
    this->layout1->addWidget(this->hdLineedit, 6, 3, 1, 3);
    this->layout1->addWidget(this->veLabel, 7, 0, 1, 3);
    this->layout1->addWidget(this->veLineedit, 7, 3, 1, 3);
    this->layout1->addWidget(this->vLabel, 8, 0, 1, 3);
    this->layout1->addWidget(this->vLineedit, 8, 3, 1, 3);
    this->layout1->addWidget(this->vevLabel, 9, 0, 1, 3);
    this->layout1->addWidget(this->vevLineedit, 9, 3, 1, 3);
}


void caco3SryTankAndAgitatorWindow::initAgitator()
{
    this->agitatorWidget = new QWidget(this);
    this->agitatorLabel = new QLabel(tr("石灰石浆液箱搅拌器"), agitatorWidget);
    this->rPowerLabel = new QLabel(tr("比功率(kW):"), agitatorWidget);
    this->shaftPowerLabel = new QLabel(tr("轴功率(kW):"), agitatorWidget);
    this->motorPowerLabel = new QLabel(tr("电机功率(kW):"), agitatorWidget);
    this->kdLabel = new QLabel(tr("电机功率靠档(kW):"), agitatorWidget);
    this->rPowerLineedit = new QLineEdit(agitatorWidget);
    this->rPowerLineedit->setReadOnly(true);
    this->shaftPowerLineedit= new QLineEdit(agitatorWidget);
    this->shaftPowerLineedit->setReadOnly(true);
    this->motorPowerLineedit= new QLineEdit(agitatorWidget);
    this->motorPowerLineedit->setReadOnly(true);
    this->kdComBox = new QComboBox(agitatorWidget);
    this->kdComBox->setEditable(false);
    utils::setKdComboBox(kdComBox, Nesj);
    this->rPowerLineedit->setText(QString("%1").arg(round(this->Nbsj * 1000) / 1000));
    this->shaftPowerLineedit->setText(QString("%1").arg(round(this->Nfsj * 10) / 10));
    this->motorPowerLineedit->setText(QString("%1").arg(round(this->Nesj * 10) / 10));

    this->layout2 = new QGridLayout(this->agitatorWidget);
    this->layout2->addWidget(this->agitatorLabel, 0, 0, 1, 6);
    this->layout2->addWidget(this->rPowerLabel, 1, 0, 1, 3);
    this->layout2->addWidget(this->rPowerLineedit, 1, 3, 1, 3);
    this->layout2->addWidget(this->shaftPowerLabel, 2, 0, 1, 3);
    this->layout2->addWidget(this->shaftPowerLineedit, 2, 3, 1, 3);
    this->layout2->addWidget(this->motorPowerLabel, 3, 0, 1, 3);
    this->layout2->addWidget(this->motorPowerLineedit, 3, 3, 1, 3);
    this->layout2->addWidget(this->kdLabel, 4, 0, 1, 3);
    this->layout2->addWidget(this->kdComBox, 4, 3, 1, 3);

}


void caco3SryTankAndAgitatorWindow::okSLOT()
{

    bool ok1, ok2, ok3;
    bool ok4, ok5, ok6;
    float fgd = this->fgdNumLabel->text().toFloat(&ok4);
    float tsj = this->bufferTimeLineedit->text().toFloat(&ok5);
    float ysj = this->vevLineedit->text().toFloat(&ok6);

    float a = this->vevLineedit->text().toFloat(&ok1);
    float d = this->dLineedit->text().toFloat(&ok2);
    float h = this->hLineedit->text().toFloat(&ok3);
    if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6
            && a>=0 && a<=100 && d > 0 && h >0 && fgd > 0 && tsj > 0 && ysj > 0)
    {
        Qsj = gslResultPar::GSL[0][1][1];
        FGDnum = fgd;
        Tsj = tsj;
        Ysj = ysj / 100;
        slurryPreSystem::Vsj = Qsj * FGDnum * Tsj;
        slurryPreSystem::VTsj = slurryPreSystem::Vsj / Ysj;
        Dsj = d;
        Hsj = h;
        HDsj = Hsj / Dsj;


        VTjsj = ceil(3.1415 * (pow(Dsj / 2, 2)) * Hsj);
        Vjsj = Ysj * VTjsj;


        this->fgdNumLineedit->setText(QString("%1").arg(round(FGDnum)));
        this->bufferTimeLineedit->setText(QString("%1").arg(round(FGDnum * 1000) / 1000));
        this->singleFurnaceLineedit->setText(QString("%1").arg(round(FGDnum * 1000) / 1000));


        this->dLineedit->setText(QString("%1").arg(round(Dsj * 10) / 10));
        this->hLineedit->setText(QString("%1").arg(round(Hsj * 10) / 10));
        this->hdLineedit->setText(QString("%1").arg(round(HDsj * 10) / 10));
        this->veLineedit->setText(QString("%1").arg(round(Vjsj)));
        this->vLineedit->setText(QString("%1").arg(round(VTjsj)));
        this->vevLineedit->setText(QString("%1").arg(round(Ysj * 100)));


        Nbsj = emergencySlurrySystem::BGL(gslResultPar::GSL[0][1][16]) / 1000.0; // 比功率
        Nfsj = ceil(slurryPreSystem::Vjsj * Nbsj *10) / 10;    //轴功率
        Nesj = Nfsj * (1 + utils::YL(Nfsj)) / 0.98;                       //电机功率
        Nksj = utils::KD(Nesj);                                            //电机功率靠档


        this->rPowerLineedit->setText(QString("%1").arg(round(this->Nbsj * 1000) / 1000));
        this->shaftPowerLineedit->setText(QString("%1").arg(round(this->Nfsj * 10) / 10));
        this->motorPowerLineedit->setText(QString("%1").arg(round(this->Nesj * 10) / 10));
        utils::setKdComboBox(this->kdComBox, Nksj);
        QMessageBox::information(this, tr("信息"), tr("数据修改成功"));

    }
    else
        QMessageBox::warning(this, tr("错误"), tr("数据输入错误"));
}




