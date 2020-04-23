#include "window_inputparameter.h"

int inputParameterWindow::num = 0;


int inputParameterWindow::bz1= 0;
int inputParameterWindow::bz2 = 0;
int inputParameterWindow::shr = 0;
float inputParameterWindow::shd = 0;
float inputParameterWindow::f1 = 0;
float inputParameterWindow::f6 = 0;
float inputParameterWindow::f7 = 0;
float inputParameterWindow::f8 = 0;
float inputParameterWindow::f9 = 0;
float inputParameterWindow::f10 = 0;




inputParameterWindow::inputParameterWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    inputParameterWindow::num += 1;


    this->initWidget1();
    this->initWidget2();
    this->initWidget3();
    this->tabwidget = new QTabWidget;
    this->tabwidget->clear();
    this->tabwidget->addTab(tabInWidget1, tr("烟气参数"));
    this->tabwidget->addTab(tabInWidget2, tr("其它参数"));
    this->tabwidget->addTab(tabInWidget3, tr("烟道阻力降"));
    zongLayout = new QGridLayout(this);
    zongLayout->addWidget(this->tabwidget, 0, 0, 6, 6);
    okButton = new QPushButton(tr("确定"));
    cancelButton = new QPushButton(tr("关闭"));
    zongLayout->addWidget(okButton, 6, 0, 1, 3);
    zongLayout->addWidget(cancelButton, 6, 3, 1, 3);

    this->initParWidget1();
    this->initParWidget2();
    this->initParWidget3();

    this->show();
    this->setWindowTitle(tr("输入参数"));
}




void inputParameterWindow::initParWidget1()
{
//    if (wetRadiobutton->isChecked())
    wetRadiobutton->setChecked(true);
    gasNumLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][3]));
    gasTempLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][22]));
    pressureLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][21]));

    o2Lineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][8]));
    co2Lineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][9]));
    if (gasResultPar::Gas[0][0][3] == 0){
        h2oLineedit->setText(tr("0"));
    }
    else
        h2oLineedit->setText(QString("%1").arg(round(gasResultPar::Gas[0][0][1] / gasResultPar::Gas[0][0][3] * 100.2)));

    switch(inputParameterWindow::bz2){
        case 2:{
            dryCheckbox->setChecked(true);
            so2Lineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][15]));
            so3Lineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][17]));
            hclLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][18]));
            hfLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][19]));
            dustLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][20]));
            break;
        }
        case 1:{
            dryCheckbox->setChecked(true);
            so2Lineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][10]));
            so3Lineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][11]));
            hclLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][12]));
            hfLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][13]));
            dustLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][0][14]));
            break;
        }
        default:
            break;
    }
}



void inputParameterWindow::initParWidget2()
{
    this->caco3Combobox1->addItem(tr("CaCO3(%)"));
    this->caco3Combobox1->addItem(tr("CaO(%)"));
    this->caco3Combobox1->setCurrentIndex(0);
    this->caco3Combobox2->addItem(tr("MgCO3(%)"));
    this->caco3Combobox2->addItem(tr("MgO(%)"));
    this->caco3Combobox2->setCurrentIndex(0);
    this->otherCombobox->addItem(tr("其它(%)"));
    this->otherCombobox->setCurrentIndex(0);
    this->otherCombobox->setEnabled(false);


    caco3Lineedit1->setText(QString("%1").arg(round(pinf::VCaCO3 * 100) / 100.0));
    caco3Lineedit2->setText(QString("%1").arg(round(pinf::VMgCO3 * 100) / 100.0));
    otherLineedit->setText(QString("%1").arg(100 - pinf::VMgCO3 - pinf::VCaCO3));
    clLineedit->setText(QString("%1").arg(gslResultPar::GSL[0][19][14]));

    lineedit21->setText(QString("%1").arg(pinf::Pcaco3));
    lineedit22->setText(QString("%1").arg(pinf::yS * 100));
    lineedit23->setText(QString("%1").arg(gslResultPar::GSL[0][11][14]));
    lineedit24->setText(QString("%1").arg(gslResultPar::GSL[0][5][16] * 100));
    lineedit25->setText(QString("%1").arg(pinf::zysh * 100));
    qDebug() << "pinf::huanre = " << QString("%1").arg(pinf::huanre);
    if(pinf::huanre == 1)
    {

        lineedit26->setText(tr("80"));
        lineedit26->setEnabled(true);
    }
    else{
        lineedit26->setText(tr("0"));
        lineedit26->setEnabled(false);
    }
}


void inputParameterWindow::initParWidget3()
{
    lineedit1->setText(QString("%1").arg(pinf::PP1));
    lineedit2->setText(QString("%1").arg(pinf::PP2));
    lineedit3->setText(QString("%1").arg(pinf::PP3));
    lineedit4->setText(QString("%1").arg(pinf::PP4));
    lineedit5->setText(QString("%1").arg(pinf::PP5));
    lineedit6->setText(QString("%1").arg(pinf::PP6));
    lineedit7->setText(QString("%1").arg(pinf::PP7));
    lineedit8->setText(QString("%1").arg(pinf::PP8));
    lineedit9->setText(QString("%1").arg(pinf::PP9));
    lineedit10->setText(QString("%1").arg(pinf::PP10));
    lineedit11->setText(QString("%1").arg(pinf::PP11));
    lineedit12->setText(QString("%1").arg(pinf::PP12));

}




void inputParameterWindow::initWidget1()
{
    // widget11

    widget11 = new QWidget;
    gridLayout11 = new QGridLayout(widget11);
    wetRadiobutton = new QRadioButton(tr("湿基标态"));
    dryRadiobutton = new QRadioButton(tr("干基标态"));
    group1 = new QButtonGroup(this);
    group1->addButton(wetRadiobutton, 0);
    group1->addButton(dryRadiobutton, 1);
    gasNumLabel = new QLabel(tr("烟气量(Nm3/h):"));
    gasTempLabel = new QLabel(tr("烟气温度(°C):"));
    pressureLabel = new QLabel(tr("当地平均大气压(mbar):"));
    gasNumLineedit = new QLineEdit;
    gasTempLineedit = new QLineEdit;
    pressureLineedit = new QLineEdit;
    gridLayout11->addWidget(wetRadiobutton, 0, 0, 1, 3);
    gridLayout11->addWidget(dryRadiobutton, 0, 3, 1, 3);
    gridLayout11->addWidget(gasNumLabel, 1, 0, 1, 3);
    gridLayout11->addWidget(gasNumLineedit, 1, 3, 1, 3);
    gridLayout11->addWidget(gasTempLabel, 2, 0, 1, 3);
    gridLayout11->addWidget(gasTempLineedit, 2, 3, 1, 3);
    gridLayout11->addWidget(pressureLabel, 3, 0, 1, 3);
    gridLayout11->addWidget(pressureLineedit, 3, 3, 1, 3);

    // widget12

    widget12 = new QWidget;
    gridLayout12 = new QGridLayout(widget12);
    gasComponentLabel = new QLabel(tr("烟气成分"));
    o2Label = new QLabel(tr("干基O2(vol%):"));
    co2Label = new QLabel(tr("干基CO2(vol%):"));
    h2oLabel = new QLabel(tr("烟气湿度(vol%):"));
    o2Lineedit = new QLineEdit;
    co2Lineedit = new QLineEdit;
    h2oLineedit = new QLineEdit;
    gridLayout12->addWidget(gasComponentLabel, 0, 0, 1, 6);
    gridLayout12->addWidget(o2Label, 1, 0, 1, 3);
    gridLayout12->addWidget(o2Lineedit, 1, 3, 1, 3);
    gridLayout12->addWidget(co2Label, 2, 0, 1, 3);
    gridLayout12->addWidget(co2Lineedit, 2, 3, 1, 3);
    gridLayout12->addWidget(h2oLabel, 3, 0, 1, 3);
    gridLayout12->addWidget(h2oLineedit, 3, 3, 1, 3);

    // widget13

    widget13 = new QWidget;
    gridLayout13 = new QGridLayout(widget13);
    dryCheckbox = new QCheckBox(tr("干基标态6%O2"));
    so2Label = new QLabel(tr("SO2(mg/Nm3):"));
    so3Label = new QLabel(tr("SO3(mg/Nm3):"));
    hclLabel = new QLabel(tr("HCL(mg/Nm3):"));
    hfLabel = new QLabel(tr("HF(mg/Nm3):"));
    dustLabel = new QLabel(tr("灰(mg/Nm3)"));
    so2Lineedit = new QLineEdit;
    so3Lineedit = new QLineEdit;
    hclLineedit = new QLineEdit;
    hfLineedit = new QLineEdit;
    dustLineedit = new QLineEdit;
    gridLayout13->addWidget(dryCheckbox, 0, 0, 1, 6);
    gridLayout13->addWidget(so2Label, 1, 0, 1, 3);
    gridLayout13->addWidget(so2Lineedit, 1, 3, 1, 3);
    gridLayout13->addWidget(so3Label, 2, 0, 1, 3);
    gridLayout13->addWidget(so3Lineedit, 2, 3, 1, 3);
    gridLayout13->addWidget(hclLabel, 3, 0, 1, 3);
    gridLayout13->addWidget(hclLineedit, 3, 3, 1, 3);
    gridLayout13->addWidget(hfLabel, 4, 0, 1, 3);
    gridLayout13->addWidget(hfLineedit, 4, 3, 1, 3);
    gridLayout13->addWidget(dustLabel, 5, 0, 1, 3);
    gridLayout13->addWidget(dustLineedit, 5, 3, 1, 3);

    // tabInwidget1

    tabInWidget1 = new QWidget;
    layout1 = new QVBoxLayout(tabInWidget1);
    layout1->addWidget(widget11);
    layout1->addWidget(widget12);
    layout1->addWidget(widget13);
}

void inputParameterWindow::initWidget2()
{
    tabInWidget2 = new QWidget;
    layout2 = new QVBoxLayout(tabInWidget2);

    // widget21

    widget21 = new QWidget;
    caco3Combobox1 = new QComboBox;
    caco3Combobox2 = new QComboBox;
    otherCombobox = new QComboBox;
    caco3Lineedit1 = new QLineEdit;
    caco3Lineedit2 = new QLineEdit;
    otherLineedit = new QLineEdit;

    caco3ComponentLabel = new QLabel(tr("石灰石成分"));
    gridLayout21 = new QGridLayout(widget21);
    gridLayout21->addWidget(this->caco3ComponentLabel, 0, 0, 1, 6);
    gridLayout21->addWidget(this->caco3Combobox1, 1, 0, 1, 3);
    gridLayout21->addWidget(this->caco3Lineedit1, 1, 3, 1, 3);
    gridLayout21->addWidget(this->caco3Combobox2, 2, 0, 1, 3);
    gridLayout21->addWidget(this->caco3Lineedit2, 2, 3, 1, 3);
    gridLayout21->addWidget(this->otherCombobox, 3, 0, 1, 3);
    gridLayout21->addWidget(this->otherLineedit, 3, 3, 1, 3);

    // widget22

    widget22 = new QWidget;
    gridLayout22 = new QGridLayout(widget22);
    h2oQualityLabel = new QLabel(tr("工艺水质"));
    clLabel = new QLabel(tr("CL-(ppm):"));
    clLineedit = new QLineEdit;
    gridLayout22->addWidget(this->h2oQualityLabel, 0, 0, 1, 6);
    gridLayout22->addWidget(this->clLabel, 1, 0, 1, 3);
    gridLayout22->addWidget(this->clLineedit, 1, 3, 1, 3);

    // widget23

    widget23 = new QWidget;
    gridLayout23 = new QGridLayout(widget23);
    label20 = new QLabel(tr("其它参数"));
    label21 = new QLabel(tr("CaCO3(%)"));
    label22 = new QLabel(tr("脱硫效率(%)"));
    label23 = new QLabel(tr("氯化物含量(ppm)"));
    label24 = new QLabel(tr("石膏旋流器顶流含固量(%)"));
    label25 = new QLabel(tr("增压风机温升计算百分比(%)"));
    label26 = new QLabel(tr("GGH出口温度(°C)"));
    lineedit21 = new QLineEdit;
    lineedit22 = new QLineEdit;
    lineedit23 = new QLineEdit;
    lineedit24 = new QLineEdit;
    lineedit25 = new QLineEdit;
    lineedit26 = new QLineEdit;

    gridLayout23->addWidget(label20, 0, 0, 1, 6);
    gridLayout23->addWidget(label21, 1, 0, 1, 3);
    gridLayout23->addWidget(lineedit21, 1, 3, 1, 3);
    gridLayout23->addWidget(label22, 2, 0, 1, 3);
    gridLayout23->addWidget(lineedit22, 2, 3, 1, 3);
    gridLayout23->addWidget(label23, 3, 0, 1, 3);
    gridLayout23->addWidget(lineedit23, 3, 3, 1, 3);
    gridLayout23->addWidget(label24, 4, 0, 1, 3);
    gridLayout23->addWidget(lineedit24, 4, 3, 1, 3);
    gridLayout23->addWidget(label25, 5, 0, 1, 3);
    gridLayout23->addWidget(lineedit25, 5, 3, 1, 3);
    gridLayout23->addWidget(label26, 6, 0, 1, 3);
    gridLayout23->addWidget(lineedit26, 6, 3, 1, 3);

    layout2->addWidget(widget21);
    layout2->addWidget(widget22);
    layout2->addWidget(widget23);

}


void inputParameterWindow::initWidget3()
{
    tabInWidget3 = new QWidget;
    gridLayout3 = new QGridLayout(tabInWidget3);
    label0 = new QLabel(tr("烟气流程上各设施的大致压降(mbar)"));
    label1 = new QLabel(tr("入口合流三通:"));
    label2 = new QLabel(tr("原烟气入口挡板阻力:"));
    label3 = new QLabel(tr("原烟气入口挡板阻力至增压风机烟道阻力:"));
    label4 = new QLabel(tr("增压风机至GGH原烟气烟道阻力:"));
    label5 = new QLabel(tr("GGH原烟气侧阻力:"));
    label6 = new QLabel(tr("GGH至吸收塔原烟气烟道阻力:"));
    label7 = new QLabel(tr("吸收塔至GGH净烟气烟道阻力:"));
    label8 = new QLabel(tr("GGH净烟气阻力:"));
    label9 = new QLabel(tr("GGH至净烟气出口挡板烟道阻力:"));
    label10 = new QLabel(tr("净烟气出口挡板阻力:"));
    label11 = new QLabel(tr("出口阻力:"));
    label12 = new QLabel(tr("烟囱阻力:"));

    lineedit1 = new QLineEdit;
    lineedit2 = new QLineEdit;
    lineedit3 = new QLineEdit;
    lineedit4 = new QLineEdit;
    lineedit5 = new QLineEdit;
    lineedit6 = new QLineEdit;
    lineedit7 = new QLineEdit;
    lineedit8 = new QLineEdit;
    lineedit9 = new QLineEdit;
    lineedit10 = new QLineEdit;
    lineedit11 = new QLineEdit;
    lineedit12 = new QLineEdit;


    gridLayout3->addWidget(label0, 0, 0, 1, 6);
    gridLayout3->addWidget(label1, 1, 0, 1, 3);
    gridLayout3->addWidget(lineedit1, 1, 3, 1, 3);
    gridLayout3->addWidget(label2, 2, 0, 1, 3);
    gridLayout3->addWidget(lineedit2, 2, 3, 1, 3);
    gridLayout3->addWidget(label3, 3, 0, 1, 3);
    gridLayout3->addWidget(lineedit3, 3, 3, 1, 3);
    gridLayout3->addWidget(label4, 4, 0, 1, 3);
    gridLayout3->addWidget(lineedit4, 4, 3, 1, 3);
    gridLayout3->addWidget(label5, 5, 0, 1, 3);
    gridLayout3->addWidget(lineedit5, 5, 3, 1, 3);
    gridLayout3->addWidget(label6, 6, 0, 1, 3);
    gridLayout3->addWidget(lineedit6, 6, 3, 1, 3);
    gridLayout3->addWidget(label7, 7, 0, 1, 3);
    gridLayout3->addWidget(lineedit7, 7, 3, 1, 3);
    gridLayout3->addWidget(label8, 8, 0, 1, 3);
    gridLayout3->addWidget(lineedit8, 8, 3, 1, 3);
    gridLayout3->addWidget(label9, 9, 0, 1, 3);
    gridLayout3->addWidget(lineedit9, 9, 3, 1, 3);
    gridLayout3->addWidget(label10, 10, 0, 1, 3);
    gridLayout3->addWidget(lineedit10, 10, 3, 1, 3);
    gridLayout3->addWidget(label11, 11, 0, 1, 3);
    gridLayout3->addWidget(lineedit11, 11, 3, 1, 3);
    gridLayout3->addWidget(label12, 12, 0, 1, 3);
    gridLayout3->addWidget(lineedit12, 12, 3, 1, 3);



}

void inputParameterWindow::okSLOT()
{

}


inputParameterWindow::~inputParameterWindow()
{
    inputParameterWindow::num -= 1;
}

