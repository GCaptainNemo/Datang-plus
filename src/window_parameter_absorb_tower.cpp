#include "window_parameter_absorb_tower.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

int window_parameter_absorb_tower::num = 0;

window_parameter_absorb_tower::window_parameter_absorb_tower(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    this->setAttribute(Qt::WA_DeleteOnClose);
    window_parameter_absorb_tower::num += 1;
    this->setWindowTitle(tr("吸收塔"));

    this->initWidget1();
    this->initWidget2();
    this->initWidget3();
    this->initWidget4();

    widgetrow = new QWidget(this);
    hlayout = new QHBoxLayout(widgetrow);
    hlayout->addWidget(widget1);
    hlayout->addWidget(widget4);

    layout = new QVBoxLayout(this);
    layout->addWidget(widgetrow);
    layout->addWidget(widget3);

    this->showNormal();
}


window_parameter_absorb_tower::~window_parameter_absorb_tower()
{
    window_parameter_absorb_tower::num -= 1;

}

void window_parameter_absorb_tower::initWidget1()
{
    widget1 = new QWidget(this);
    widget1->setObjectName(tr("widgetFrame"));
    gridlayout1 = new QGridLayout(widget1);
    label111 = new QLabel(tr("吸收塔尺寸参数"), widget1);
    label112 = new QLabel(tr("目标值"), widget1);
    label113 = new QLabel(tr("实际值"), widget1);
    label12 = new QLabel(tr("吸收塔入口烟气流速(m/s):"), widget1);
    label13 = new QLabel(tr("吸收塔出口烟气流速(m/s):"), widget1);
    label14 = new QLabel(tr("烟气流速(m/s):"), widget1);
    label15 = new QLabel(tr("正常液位到吸收塔入口底部距离(m):"), widget1);
    label16 = new QLabel(tr("入口顶部至第一层喷淋层距离(m):"), widget1);
    label17 = new QLabel(tr("喷淋层数(及循环泵个数)"), widget1);
    label18 = new QLabel(tr("喷淋层间距(m):"), widget1);
    label19 = new QLabel(tr("喷淋层至除雾器高度(m):"), widget1);
    label1_10 = new QLabel(tr("除雾器高度(m):"), widget1);
    label1_11 = new QLabel(tr("除雾器至出口底部距离(m):"), widget1);
    label1_12 = new QLabel(tr("烟道宽度(%):"), widget1);

    spinBox2 = new QDoubleSpinBox(widget1);
    spinBox3 = new QDoubleSpinBox(widget1);
    spinBox5 = new QDoubleSpinBox(widget1);
    spinBox6 = new QDoubleSpinBox(widget1);
    spinBox7 = new QDoubleSpinBox(widget1);
    spinBox8 = new QDoubleSpinBox(widget1);
    spinBox9 = new QDoubleSpinBox(widget1);
    spinBox10 = new QDoubleSpinBox(widget1);
    spinBox11 = new QDoubleSpinBox(widget1);


    lineedit12 = new QLineEdit(widget1);
    lineedit13 = new QLineEdit(widget1);
    lineedit141 = new QLineEdit(widget1);
    lineedit142 = new QLineEdit(widget1);
    lineedit1_12 = new QLineEdit(widget1);

    okButton = new QPushButton(tr("确定"), widget1);
    exportExcelButton = new QPushButton(tr("导出Excel文件"), widget1);

    gridlayout1->addWidget(label111, 0, 0, 1, 3);
    gridlayout1->addWidget(label112, 0, 3, 1, 3);
    gridlayout1->addWidget(label113, 0, 6, 1, 3);
    gridlayout1->addWidget(label12, 1, 0, 1, 3);
    gridlayout1->addWidget(spinBox2, 1, 3, 1, 3);
    gridlayout1->addWidget(lineedit12, 1, 6, 1, 3);
    gridlayout1->addWidget(label13, 2, 0, 1, 3);
    gridlayout1->addWidget(spinBox3, 2, 3, 1, 3);
    gridlayout1->addWidget(lineedit13, 2, 6, 1, 3);

    gridlayout1->addWidget(label14, 3, 0, 1, 3);
    gridlayout1->addWidget(lineedit141, 3, 3, 1, 3);
    gridlayout1->addWidget(lineedit142, 3, 6, 1, 3);

    gridlayout1->addWidget(label15, 4, 0, 1, 3);
    gridlayout1->addWidget(spinBox5, 4, 3, 1, 3);
    gridlayout1->addWidget(label16, 5, 0, 1, 3);
    gridlayout1->addWidget(spinBox6, 5, 3, 1, 3);
    gridlayout1->addWidget(okButton, 5, 6, 3, 3);

    gridlayout1->addWidget(label17, 6, 0, 1, 3);
    gridlayout1->addWidget(spinBox7, 6, 3, 1, 3);
    gridlayout1->addWidget(label18, 7, 0, 1, 3);
    gridlayout1->addWidget(spinBox8, 7, 3, 1, 3);
    gridlayout1->addWidget(label19, 8, 0, 1, 3);
    gridlayout1->addWidget(spinBox9, 8, 3, 1, 3);
    gridlayout1->addWidget(exportExcelButton, 8, 6, 3, 3);

    gridlayout1->addWidget(label1_10, 9, 0, 1, 3);
    gridlayout1->addWidget(spinBox10, 9, 3, 1, 3);
    gridlayout1->addWidget(label1_11, 10, 0, 1, 3);
    gridlayout1->addWidget(spinBox11, 10, 3, 1, 3);
    gridlayout1->addWidget(label1_12, 11, 0, 1, 3);
    gridlayout1->addWidget(lineedit1_12, 11, 3, 1, 3);

}

void window_parameter_absorb_tower::initWidget2()
{

    label20 = new QLabel(tr(""), widget1);
    label21 = new QLabel(tr("吸收塔进口烟道高度(m):"), widget1);
    label22 = new QLabel(tr("吸收塔出口烟道高度(m):"), widget1);
    label23 = new QLabel(tr("吸收塔直径(m):"), widget1);
    label24 = new QLabel(tr("浆液池直径(m):"), widget1);
    label25 = new QLabel(tr("液位高度(m):"), widget1);
    label26 = new QLabel(tr("液气比(标态、湿基)(L/m3):"), widget1);
    label27 = new QLabel(tr("浆液池容积(m3):"), widget1);
    label28 = new QLabel(tr("浆液循环泵流量(m3/h):"), widget1);
    label29 = new QLabel(tr("吸收区高度(m):"), widget1);
    label210 = new QLabel(tr("吸收塔总压损(mbar):"), widget1);

    lineedit21 = new QLineEdit(widget1);
    lineedit22 = new QLineEdit(widget1);
    lineedit231 = new QLineEdit(widget1);
    lineedit232 = new QLineEdit(widget1);
    lineedit241 = new QLineEdit(widget1);
    lineedit242 = new QLineEdit(widget1);
    lineedit25 = new QLineEdit(widget1);
    lineedit26 = new QLineEdit(widget1);
    lineedit27 = new QLineEdit(widget1);
    lineedit281 = new QLineEdit(widget1);
    lineedit282 = new QLineEdit(widget1);
    lineedit29 = new QLineEdit(widget1);
    lineedit2_10 = new QLineEdit(widget1);



    gridlayout1->addWidget(label20, 12, 0, 1, 9);
    gridlayout1->addWidget(label21, 13, 0, 1, 3);
    gridlayout1->addWidget(lineedit21, 13, 6, 1, 3);
    gridlayout1->addWidget(label22, 14, 0, 1, 3);
    gridlayout1->addWidget(lineedit22, 14, 6, 1, 3);
    gridlayout1->addWidget(label23, 15, 0, 1, 3);
    gridlayout1->addWidget(lineedit231, 15, 3, 1, 3);
    gridlayout1->addWidget(lineedit232, 15, 6, 1, 3);
    gridlayout1->addWidget(label24, 16, 0, 1, 3);
    gridlayout1->addWidget(lineedit241, 16, 3, 1, 3);
    gridlayout1->addWidget(lineedit242, 16, 6, 1, 3);

    gridlayout1->addWidget(label25, 17, 0, 1, 3);
    gridlayout1->addWidget(lineedit25, 17, 6, 1, 3);
    gridlayout1->addWidget(label26, 18, 0, 1, 3);
    gridlayout1->addWidget(lineedit26, 18, 6, 1, 3);
    gridlayout1->addWidget(label27, 19, 0, 1, 3);
    gridlayout1->addWidget(lineedit27, 19, 6, 1, 3);
    gridlayout1->addWidget(label28, 20, 0, 1, 3);
    gridlayout1->addWidget(lineedit281, 20, 3, 1, 3);
    gridlayout1->addWidget(lineedit282, 20, 6, 1, 3);
    gridlayout1->addWidget(label29, 21, 0, 1, 3);
    gridlayout1->addWidget(lineedit29, 21, 6, 1, 3);
    gridlayout1->addWidget(label210, 22, 0, 1, 3);
    gridlayout1->addWidget(lineedit2_10, 22, 6, 1, 3);

}


void window_parameter_absorb_tower::initWidget3()
{

    widget3 = new QWidget(this);
    widget3->setObjectName(tr("widgetFrame"));
    gridlayout3 = new QGridLayout(widget3);
    label311 = new QLabel(tr("氧化风机布置方式:"), widget3);
    radioButton31 = new QRadioButton(tr("管网"), widget3);
    radioButton32 = new QRadioButton(tr("喷枪式"), widget3);
    label312 = new QLabel(tr("吸收塔外形选择:"), widget3);
    radioButton33 = new QRadioButton(tr("图1"), widget3);
    radioButton34 = new QRadioButton(tr("图2"), widget3);

    label321 = new QLabel(tr("氧化空气管距正常页面高度差(m):"));
    lineedit321 = new QLineEdit(widget3);
    label322 = new QLabel(tr("最小氧化高度(m):"));
    lineedit322 = new QLineEdit(widget3);
    label323 = new QLabel(tr("吸收塔搅拌器数量:"));
    lineedit323 = new QLineEdit(widget3);

    label331 = new QLabel(tr("每层喷嘴数量"), widget3);
    lineedit331 = new QLineEdit(widget3);
    label332 = new QLabel(tr("比功率(kW):"), widget3);
    lineedit332 = new QLineEdit(widget3);
    label333 = new QLabel(tr("电机功率(kW):"), widget3);
    lineedit333 = new QLineEdit(widget3);

    label341 = new QLabel(tr("喷嘴流量(l/min):"), widget3);
    lineedit341 = new QLineEdit(widget3);
    label342 = new QLabel(tr("轴功率(kW):"), widget3);
    lineedit342 = new QLineEdit(widget3);
    label343 = new QLabel(tr("电机功率靠档:"), widget3);
    comboBox343 = new QComboBox(widget3);


    gridlayout3->addWidget(label311, 0, 0, 1, 3);
    gridlayout3->addWidget(radioButton31, 0, 3, 1, 3);
    gridlayout3->addWidget(radioButton32, 0, 6, 1, 3);
    gridlayout3->addWidget(label312, 0, 9, 1, 3);
    gridlayout3->addWidget(radioButton33, 0, 12, 1, 3);
    gridlayout3->addWidget(radioButton34, 0, 15, 1, 3);

    gridlayout3->addWidget(label321, 1, 0, 1, 3);
    gridlayout3->addWidget(lineedit321, 1, 3, 1, 3);
    gridlayout3->addWidget(label322, 1, 6, 1, 3);
    gridlayout3->addWidget(lineedit322, 1, 9, 1, 3);
    gridlayout3->addWidget(label323, 1, 12, 1, 3);
    gridlayout3->addWidget(lineedit323, 1, 15, 1, 3);

    gridlayout3->addWidget(label331, 2, 0, 1, 3);
    gridlayout3->addWidget(lineedit331, 2, 3, 1, 3);
    gridlayout3->addWidget(label332, 2, 6, 1, 3);
    gridlayout3->addWidget(lineedit332, 2, 9, 1, 3);
    gridlayout3->addWidget(label333, 2, 12, 1, 3);
    gridlayout3->addWidget(lineedit333, 2, 15, 1, 3);


    gridlayout3->addWidget(label341, 3, 0, 1, 3);
    gridlayout3->addWidget(lineedit341, 3, 3, 1, 3);
    gridlayout3->addWidget(label342, 3, 6, 1, 3);
    gridlayout3->addWidget(lineedit342, 3, 9, 1, 3);
    gridlayout3->addWidget(label343, 3, 12, 1, 3);
    gridlayout3->addWidget(comboBox343, 3, 15, 1, 3);

}

void window_parameter_absorb_tower::initWidget4()
{
    widget4 = new QWidget(this);
}


