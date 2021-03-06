﻿#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_tankproh2o.h"

int proH2OtankWindow::num = 0;

proH2OtankWindow::proH2OtankWindow(float & Qgy, int & FGDnum, float & Tgy, float & Dgy,
                                   float & Hgy, float & HDgy,  float & Vjgy, float & VTjgy,  float & Ygy, QWidget *parent):
   Qgy(Qgy), FGDnum(FGDnum), Tgy(Tgy), Dgy(Dgy), Hgy(Hgy), HDgy(HDgy),  Vjgy(Vjgy), VTjgy(VTjgy), Ygy(Ygy), QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    this->setWindowTitle(tr("石灰石浆液箱及搅拌器"));
    proH2OtankWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 工艺水箱

    this->proWaterTankWidget = new QWidget(this);
    this->layout1 = new QGridLayout(this->proWaterTankWidget);
    sryTankLabel = new QLabel(tr("工艺水箱"), proWaterTankWidget);


    singleFurnaceLabel = new QLabel(tr("单台炉耗量(m3/h):"), proWaterTankWidget);
    fgdNumLabel = new QLabel(tr("FGD数量:"), proWaterTankWidget);
    bufferTimeLabel = new QLabel(tr("要求的缓冲时间(h):"), proWaterTankWidget);
    dLabel = new QLabel(tr("直径(m):"), proWaterTankWidget);
    hLabel = new QLabel(tr("高度(m):"), proWaterTankWidget);
    hdLabel = new QLabel(tr("高径比"), proWaterTankWidget);
    veLabel = new QLabel(tr("有效容积(m3):"), proWaterTankWidget);
    vLabel = new QLabel(tr("总容积(m3)"), proWaterTankWidget);
    vevLabel = new QLabel(tr("有效/总容积(%)"), proWaterTankWidget);
    singleFurnaceLineedit = new QLineEdit(proWaterTankWidget);
    fgdNumLineedit= new QLineEdit(proWaterTankWidget);
    bufferTimeLineedit = new QLineEdit(proWaterTankWidget);
    dLineedit= new QLineEdit(proWaterTankWidget);
    hLineedit= new QLineEdit(proWaterTankWidget);
    hdLineedit = new QLineEdit(proWaterTankWidget);
    hdLineedit->setReadOnly(true);
    veLineedit = new QLineEdit(proWaterTankWidget);
    veLineedit->setReadOnly(true);
    vLineedit = new QLineEdit(proWaterTankWidget);
    vLineedit->setReadOnly(true);
    vevLineedit = new QLineEdit(proWaterTankWidget);
    this->singleFurnaceLineedit->setText(QString("%1").arg(round(this->Qgy* 10) / 10));
    this->fgdNumLineedit->setText(QString("%1").arg(round(this->FGDnum)));
    this->bufferTimeLineedit->setText(QString("%1").arg(round(this->Tgy* 10) / 10));
    this->dLineedit->setText(QString("%1").arg(round(this->Dgy * 10) / 10));
    this->hLineedit->setText(QString("%1").arg(round(this->Hgy * 10) / 10));
    this->hdLineedit->setText(QString("%1").arg(round(this->HDgy * 10) / 10));
    this->veLineedit->setText(QString("%1").arg(round(this->Vjgy)));
    this->vLineedit->setText(QString("%1").arg(round(this->VTjgy)));
    this->vevLineedit->setText(QString("%1").arg(round(this->Ygy * 100)));


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

    buttonWidget = new QWidget(this);
    hlayout = new QHBoxLayout(buttonWidget);
    okButton = new QPushButton("确定", buttonWidget);
    cancelButton = new QPushButton("关闭", buttonWidget);
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    calButton = new QPushButton("计算", buttonWidget);
    hlayout->addWidget(calButton);
    hlayout->addWidget(okButton);
    hlayout->addWidget(cancelButton);
    layout = new QVBoxLayout(this);
    layout->addWidget(proWaterTankWidget);
    layout->addWidget(buttonWidget);
    this->show();
}

proH2OtankWindow::~proH2OtankWindow()
{
    proH2OtankWindow::num -= 1;
}


void proH2OtankWindow::okSLOT()
{

}

