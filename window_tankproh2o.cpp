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

    this->proWaterTankWidget = new QWidget;
    this->layout1 = new QGridLayout(this->proWaterTankWidget);
    sryTankLabel = new QLabel(tr("工艺水箱"));


    singleFurnaceLabel = new QLabel(tr("单台炉耗量(m3/h):"));
    fgdNumLabel = new QLabel(tr("FGD数量:"));
    bufferTimeLabel = new QLabel(tr("要求的缓冲时间(h):"));
    dLabel = new QLabel(tr("直径(m):"));
    hLabel = new QLabel(tr("高度(m):"));
    hdLabel = new QLabel(tr("高径比"));
    veLabel = new QLabel(tr("有效容积(m3):"));
    vLabel = new QLabel(tr("总容积(m3)"));
    vevLabel = new QLabel(tr("有效/总容积(%)"));
    singleFurnaceLineedit = new QLineEdit;
    fgdNumLineedit= new QLineEdit;
    bufferTimeLineedit = new QLineEdit;
    dLineedit= new QLineEdit;
    hLineedit= new QLineEdit;
    hdLineedit = new QLineEdit;
    hdLineedit->setReadOnly(true);
    veLineedit = new QLineEdit;
    veLineedit->setReadOnly(true);
    vLineedit = new QLineEdit;
    vLineedit->setReadOnly(true);
    vevLineedit = new QLineEdit;
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
    hlayout = new QHBoxLayout;
    okButton = new QPushButton("确定");
    cancelButton = new QPushButton("关闭");
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));            
    calButton = new QPushButton("计算");
    hlayout->addWidget(calButton);
    hlayout->addWidget(okButton);
    hlayout->addWidget(cancelButton);
    layout = new QVBoxLayout(this);
    layout->addWidget(proWaterTankWidget);
    layout->addLayout(hlayout);
    this->show();
}

proH2OtankWindow::~proH2OtankWindow()
{
    proH2OtankWindow::num -= 1;
}


void proH2OtankWindow::okSLOT()
{
    
}

