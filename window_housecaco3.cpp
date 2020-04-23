#include "window_housecaco3.h"

int caco3HouseWindow::num = 0;

caco3HouseWindow::caco3HouseWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    qDebug() << "state1";
    if (pinf::shihui == 0)
        this->setWindowTitle(tr("石灰石仓"));
    else
        this->setWindowTitle(tr("石灰石粉仓"));

    caco3HouseWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 石灰石(粉)仓

    qDebug() << "state2";

    this->widget1 = new QWidget;
    this->layout1 = new QGridLayout(this->widget1);
    sryTankLabel = new QLabel(tr("工艺水箱"));


    singleFurnaceLabel = new QLabel(tr("单台炉耗量(kg/h):"));
    fgdNumLabel = new QLabel(tr("FGD数量:"));
    bufferTimeLabel = new QLabel(tr("要求的缓冲时间(h):"));
    houseNumLabel = new QLabel(tr("仓数量:"));
    singleFurnaceLineedit = new QLineEdit;
    singleFurnaceLineedit->setText(QString("%1").arg(round(slurryPreSystem::Qshc)));
    fgdNumLineedit= new QLineEdit;
    fgdNumLineedit->setText(QString("%1").arg(round(absorberSystem::FGDnum)));


    bufferTimeLineedit = new QLineEdit;
    bufferTimeLineedit->setText(QString("%1").arg(round(slurryPreSystem::Tshc * 1000) / 1000));

    houseNumLineedit = new QLineEdit;
    houseNumLineedit->setText(QString("%1").arg(round(slurryPreSystem::NUMshc)));

    qDebug() << "state3";


    this->layout1->addWidget(this->sryTankLabel, 0, 0, 1, 6);
    this->layout1->addWidget(this->singleFurnaceLabel, 1, 0, 1, 3);
    this->layout1->addWidget(this->singleFurnaceLineedit, 1, 3, 1, 3);
    this->layout1->addWidget(this->fgdNumLabel, 2, 0, 1, 3);
    this->layout1->addWidget(this->fgdNumLineedit, 2, 3, 1, 3);
    this->layout1->addWidget(this->bufferTimeLabel, 3, 0, 1, 3);
    this->layout1->addWidget(this->bufferTimeLineedit, 3, 3, 1, 3);
    this->layout1->addWidget(this->houseNumLabel, 4, 0, 1, 3);
    this->layout1->addWidget(this->houseNumLineedit, 4, 3, 1, 3);

    qDebug() << "state4";


    widget2 = new QWidget;
    layout2 = new QGridLayout(widget2);
    houseStyleLabel = new QLabel(tr("仓体形式:"));
    coreStyleLabel = new QLabel(tr("锥斗形式:"));
    cirHouseRadiobutton = new QRadioButton(tr("圆仓"));
    sqrHouseRadiobutton = new QRadioButton(tr("方仓"));
    cirCoreRadiobutton = new QRadioButton(tr("圆锥"));
    sqrCoreRadiobutton = new QRadioButton(tr("圆锥"));
    layout2->addWidget(houseStyleLabel, 0, 0, 1, 2);
    layout2->addWidget(cirHouseRadiobutton, 0, 2, 1, 2);
    layout2->addWidget(sqrHouseRadiobutton, 0, 4, 1, 2);
    layout2->addWidget(coreStyleLabel, 1, 0, 1, 2);
    layout2->addWidget(cirCoreRadiobutton, 1, 2, 1, 2);
    layout2->addWidget(sqrCoreRadiobutton, 1, 4, 1, 2);
    group1 = new QButtonGroup(this);
    group1->addButton(cirHouseRadiobutton, 0);
    group1->addButton(sqrHouseRadiobutton, 1);
    group2 = new QButtonGroup(this);
    group2->addButton(cirCoreRadiobutton, 0);
    group2->addButton(sqrCoreRadiobutton, 1);
    connect(group1, SIGNAL(buttonToggled(int,bool)), this, SLOT(group1SLOT(int, bool)));
    connect(group1, SIGNAL(buttonToggled(int,bool)), this, SLOT(group2SLOT(int, bool)));


    qDebug() << "state5";



    widget3 = new QWidget;
    layout3 = new QGridLayout(widget3);
    dLabel = new QLabel(tr("直径(m):"));
    coreAngleLabel = new QLabel(tr("锥体角度(度):"));
    hBarrelLabel = new QLabel(tr("筒段高度(m):"));
    hCoreLabel = new QLabel(tr("锥段高度(m):"));
    qDebug() << "state5/12";

    dLineedit= new QLineEdit;
    coreAngleLineedit = new QLineEdit;
    hBarrelLineedit= new QLineEdit;
    hCoreLineedit = new QLineEdit;
    this->dLineedit->setText(QString("%1").arg(round(slurryPreSystem::Dshc * 10) / 10));
    this->coreAngleLineedit->setText(QString("%1").arg(round(slurryPreSystem::Ashc * 10) / 10));
    this->hBarrelLineedit->setText(QString("%1").arg(round(slurryPreSystem::H1shc * 10) / 10));
    this->hCoreLineedit->setText(QString("%1").arg(round(slurryPreSystem::H2shc * 10) / 10));
    qDebug() << "state5/25";

    this->layout3->addWidget(this->dLabel, 0, 0, 1, 3);
    this->layout3->addWidget(this->dLineedit, 0, 3, 1, 3);
    this->layout3->addWidget(this->coreAngleLabel, 1, 0, 1, 3);
    this->layout3->addWidget(this->coreAngleLineedit, 1, 3, 1, 3);
    this->layout3->addWidget(this->hBarrelLabel, 2, 0, 1, 3);
    this->layout3->addWidget(this->hBarrelLineedit, 2, 3, 1, 3);
    this->layout3->addWidget(this->hCoreLabel, 3, 0, 1, 3);
    this->layout3->addWidget(this->hCoreLineedit, 3, 3, 1, 3);
    qDebug() << "state5/5";
    if(slurryPreSystem::CXshc == "圆仓"){
        this->dLabel->setText(tr("直径(m):"));
        this->cirCoreRadiobutton->setChecked(true);
        this->cirHouseRadiobutton->setChecked(true);
    }
    else{
        this->dLabel->setText(tr("宽度(m):"));
        this->sqrCoreRadiobutton->setChecked(true);
        this->sqrHouseRadiobutton->setChecked(true);
    }

    qDebug() << "state6";


    widget4 = new QWidget;
    layout4 = new QGridLayout(widget4);
    veLabel = new QLabel(tr("有效容积(m3):"));
    vLabel = new QLabel(tr("总容积(m3)"));
    vevLabel = new QLabel(tr("有效/总容积(%)"));

    veLineedit = new QLineEdit;
    veLineedit->setReadOnly(true);
    vLineedit = new QLineEdit;
    vLineedit->setReadOnly(true);
    vevLineedit = new QLineEdit;
    this->veLineedit->setText(QString("%1").arg(round(slurryPreSystem::Vjshc)));
    this->vLineedit->setText(QString("%1").arg(round(slurryPreSystem::VTjshc)));
    this->vevLineedit->setText(QString("%1").arg(round(slurryPreSystem::Yshc * 100)));
    this->layout4->addWidget(this->veLabel, 0, 0, 1, 3);
    this->layout4->addWidget(this->veLineedit, 0, 3, 1, 3);
    this->layout4->addWidget(this->vLabel, 1, 0, 1, 3);
    this->layout4->addWidget(this->vLineedit, 1, 3, 1, 3);
    this->layout4->addWidget(this->vevLabel, 2, 0, 1, 3);
    this->layout4->addWidget(this->vevLineedit, 2, 3, 1, 3);

    qDebug() << "state7";


    hlayout = new QHBoxLayout;
    calButton = new QPushButton("计算");
    okButton = new QPushButton("确定");
    cancelButton = new QPushButton("关闭");
    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    hlayout->addWidget(calButton);
    hlayout->addWidget(okButton);
    hlayout->addWidget(cancelButton);
    layout = new QVBoxLayout(this);
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    layout->addWidget(widget3);
    layout->addWidget(widget4);
    layout->addLayout(hlayout);
    this->show();
}

caco3HouseWindow::~caco3HouseWindow()
{
    caco3HouseWindow::num -= 1;

}


void caco3HouseWindow::okSLOT()
{

}

void caco3HouseWindow::group1SLOT(int p, bool status)
{
    qDebug() << QString("you choose %1 buton").arg(p);
}
void caco3HouseWindow::group2SLOT(int p, bool status)
{
    qDebug() << QString("you choose %1 buton").arg(p);

}
