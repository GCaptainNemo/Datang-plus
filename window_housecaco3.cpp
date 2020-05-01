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
    this->initWidget1();
    this->initWidget2();
    this->initWidget3();
    this->initWidget4();

    this->widget5 = new QWidget(this);
    hlayout = new QHBoxLayout(widget5);
    calButton = new QPushButton(tr("计算"), widget5);
    okButton = new QPushButton(tr("确定"), widget5);
    cancelButton = new QPushButton(tr("关闭"), widget5);
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
    layout->addWidget(widget5);
    this->show();
}

void caco3HouseWindow::initWidget1(){
    this->widget1 = new QWidget(this);
    this->layout1 = new QGridLayout(this->widget1);
    sryTankLabel = new QLabel(tr("工艺水箱"), this->widget1);
    singleFurnaceLabel = new QLabel(tr("单台炉耗量(kg/h):"), this->widget1);
    fgdNumLabel = new QLabel(tr("FGD数量:"), this->widget1);
    bufferTimeLabel = new QLabel(tr("要求的缓冲时间(h):"), this->widget1);
    houseNumLabel = new QLabel(tr("仓数量:"), this->widget1);

    singleFurnaceLineedit = new QLineEdit(this->widget1);
    singleFurnaceLineedit->setText(QString("%1").arg(round(slurryPreSystem::Qshc)));
    fgdNumLineedit= new QLineEdit(this->widget1);
    fgdNumLineedit->setText(QString("%1").arg(round(absorberSystem::FGDnum)));
    bufferTimeLineedit = new QLineEdit(this->widget1);
    bufferTimeLineedit->setText(QString("%1").arg(round(slurryPreSystem::Tshc * 1000) / 1000));
    houseNumLineedit = new QLineEdit(this->widget1);
    houseNumLineedit->setText(QString("%1").arg(round(slurryPreSystem::NUMshc)));

    this->layout1->addWidget(this->sryTankLabel, 0, 0, 1, 6);
    this->layout1->addWidget(this->singleFurnaceLabel, 1, 0, 1, 3);
    this->layout1->addWidget(this->singleFurnaceLineedit, 1, 3, 1, 3);
    this->layout1->addWidget(this->fgdNumLabel, 2, 0, 1, 3);
    this->layout1->addWidget(this->fgdNumLineedit, 2, 3, 1, 3);
    this->layout1->addWidget(this->bufferTimeLabel, 3, 0, 1, 3);
    this->layout1->addWidget(this->bufferTimeLineedit, 3, 3, 1, 3);
    this->layout1->addWidget(this->houseNumLabel, 4, 0, 1, 3);
    this->layout1->addWidget(this->houseNumLineedit, 4, 3, 1, 3);

}

void caco3HouseWindow::initWidget2()
{
    widget2 = new QWidget(this);
    layout2 = new QGridLayout(widget2);
    houseStyleLabel = new QLabel(tr("仓体形式:"), this->widget2);
    coreStyleLabel = new QLabel(tr("锥斗形式:"), this->widget2);
    cirHouseRadiobutton = new QRadioButton(tr("圆仓"), this->widget2);
    sqrHouseRadiobutton = new QRadioButton(tr("方仓"), this->widget2);
    cirCoreRadiobutton = new QRadioButton(tr("圆锥"), this->widget2);
    sqrCoreRadiobutton = new QRadioButton(tr("圆锥"), this->widget2);

    layout2->addWidget(houseStyleLabel, 0, 0, 1, 2);
    layout2->addWidget(cirHouseRadiobutton, 0, 2, 1, 2);
    layout2->addWidget(sqrHouseRadiobutton, 0, 4, 1, 2);
    layout2->addWidget(coreStyleLabel, 1, 0, 1, 2);
    layout2->addWidget(cirCoreRadiobutton, 1, 2, 1, 2);
    layout2->addWidget(sqrCoreRadiobutton, 1, 4, 1, 2);
    group1 = new QButtonGroup(this->widget2);
    group1->addButton(cirHouseRadiobutton, 0);
    group1->addButton(sqrHouseRadiobutton, 1);
    group2 = new QButtonGroup(this->widget2);
    group2->addButton(cirCoreRadiobutton, 0);
    group2->addButton(sqrCoreRadiobutton, 1);
    connect(group1, SIGNAL(buttonToggled(int,bool)), this, SLOT(group1SLOT(int)));
    connect(group1, SIGNAL(buttonToggled(int,bool)), this, SLOT(group2SLOT(int)));

}

void caco3HouseWindow::initWidget3()
{
    widget3 = new QWidget(this);
    layout3 = new QGridLayout(this->widget3);
    dLabel = new QLabel(tr("直径(m):"), this->widget3);
    coreAngleLabel = new QLabel(tr("锥体角度(度):"), this->widget3);
    hBarrelLabel = new QLabel(tr("筒段高度(m):"), this->widget3);
    hCoreLabel = new QLabel(tr("锥段高度(m):"), this->widget3);

    dLineedit= new QLineEdit(this->widget3);
    coreAngleLineedit = new QLineEdit(this->widget3);
    hBarrelLineedit= new QLineEdit(this->widget3);
    hCoreLineedit = new QLineEdit(this->widget3);
    this->dLineedit->setText(QString("%1").arg(round(slurryPreSystem::Dshc * 10) / 10));
    this->coreAngleLineedit->setText(QString("%1").arg(round(slurryPreSystem::Ashc * 10) / 10));
    this->hBarrelLineedit->setText(QString("%1").arg(round(slurryPreSystem::H1shc * 10) / 10));
    this->hCoreLineedit->setText(QString("%1").arg(round(slurryPreSystem::H2shc * 10) / 10));

    this->layout3->addWidget(this->dLabel, 0, 0, 1, 3);
    this->layout3->addWidget(this->dLineedit, 0, 3, 1, 3);
    this->layout3->addWidget(this->coreAngleLabel, 1, 0, 1, 3);
    this->layout3->addWidget(this->coreAngleLineedit, 1, 3, 1, 3);
    this->layout3->addWidget(this->hBarrelLabel, 2, 0, 1, 3);
    this->layout3->addWidget(this->hBarrelLineedit, 2, 3, 1, 3);
    this->layout3->addWidget(this->hCoreLabel, 3, 0, 1, 3);
    this->layout3->addWidget(this->hCoreLineedit, 3, 3, 1, 3);

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
}

void caco3HouseWindow::initWidget4()
{

    widget4 = new QWidget(this);
    layout4 = new QGridLayout(widget4);
    veLabel = new QLabel(tr("有效容积(m3):"), widget4);
    vLabel = new QLabel(tr("总容积(m3)"), widget4);
    vevLabel = new QLabel(tr("有效/总容积(%)"), widget4);

    veLineedit = new QLineEdit(widget4);
    veLineedit->setReadOnly(true);
    vLineedit = new QLineEdit(widget4);
    vLineedit->setReadOnly(true);
    vevLineedit = new QLineEdit(widget4);
    this->veLineedit->setText(QString("%1").arg(round(slurryPreSystem::Vjshc)));
    this->vLineedit->setText(QString("%1").arg(round(slurryPreSystem::VTjshc)));
    this->vevLineedit->setText(QString("%1").arg(round(slurryPreSystem::Yshc * 100)));
    this->layout4->addWidget(this->veLabel, 0, 0, 1, 3);
    this->layout4->addWidget(this->veLineedit, 0, 3, 1, 3);
    this->layout4->addWidget(this->vLabel, 1, 0, 1, 3);
    this->layout4->addWidget(this->vLineedit, 1, 3, 1, 3);
    this->layout4->addWidget(this->vevLabel, 2, 0, 1, 3);
    this->layout4->addWidget(this->vevLineedit, 2, 3, 1, 3);

}


caco3HouseWindow::~caco3HouseWindow()
{
    caco3HouseWindow::num -= 1;

}


void caco3HouseWindow::okSLOT()
{

}

void caco3HouseWindow::group1SLOT(int p)
{
    qDebug() << QString("you choose %1 buton").arg(p);
}
void caco3HouseWindow::group2SLOT(int p)
{
    qDebug() << QString("you choose %1 buton").arg(p);

}
