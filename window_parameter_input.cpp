#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_parameter_input.h"

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
    this->setAttribute(Qt::WA_DeleteOnClose, true);

    this->initWidget1();
    this->initWidget2();
    this->initWidget3();
    this->tabwidget = new QTabWidget(this);
    this->tabwidget->clear();
    this->tabwidget->addTab(tabInWidget1, tr("烟气参数"));
    this->tabwidget->addTab(tabInWidget2, tr("其它参数"));
    this->tabwidget->addTab(tabInWidget3, tr("烟道阻力降"));
    zongLayout = new QGridLayout(this);
    zongLayout->addWidget(this->tabwidget, 0, 0, 6, 6);


    buttonWidget = new widget_okcancel(this);
    zongLayout->addWidget(buttonWidget, 6, 0, 1, 6);
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));

    this->initParWidget1();
    this->initParWidget2();
    this->initParWidget3();

    this->show();
    this->setWindowTitle(tr("输入参数"));
}




void inputParameterWindow::initParWidget1()
{
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


    caco3Lineedit1->setText(QString("%1").arg(round(pinfPar::VCaCO3 * 100) / 100.0));
    caco3Lineedit2->setText(QString("%1").arg(round(pinfPar::VMgCO3 * 100) / 100.0));
    otherLineedit->setText(QString("%1").arg(100 - pinfPar::VMgCO3 - pinfPar::VCaCO3));
    clLineedit->setText(QString("%1").arg(gslResultPar::GSL[0][19][14]));

    lineedit21->setText(QString("%1").arg(pinfPar::Pcaco3));
    lineedit22->setText(QString("%1").arg(pinfPar::yS * 100));
    lineedit23->setText(QString("%1").arg(gslResultPar::GSL[0][11][14]));
    lineedit24->setText(QString("%1").arg(gslResultPar::GSL[0][5][16] * 100));
    lineedit25->setText(QString("%1").arg(pinfPar::zysh * 100));
    qDebug() << "pinf::huanre = " << QString("%1").arg(pinfPar::huanre);
    if(pinfPar::huanre == 1)
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
    lineedit1->setText(QString("%1").arg(pinfPar::PP1));
    lineedit2->setText(QString("%1").arg(pinfPar::PP2));
    lineedit3->setText(QString("%1").arg(pinfPar::PP3));
    lineedit4->setText(QString("%1").arg(pinfPar::PP4));
    lineedit5->setText(QString("%1").arg(pinfPar::PP5));
    lineedit6->setText(QString("%1").arg(pinfPar::PP6));
    lineedit7->setText(QString("%1").arg(pinfPar::PP7));
    lineedit8->setText(QString("%1").arg(pinfPar::PP8));
    lineedit9->setText(QString("%1").arg(pinfPar::PP9));
    lineedit10->setText(QString("%1").arg(pinfPar::PP10));
    lineedit11->setText(QString("%1").arg(pinfPar::PP11));
    lineedit12->setText(QString("%1").arg(pinfPar::PP12));

}




void inputParameterWindow::initWidget1()
{
    tabInWidget1 = new QWidget(this);
    layout1 = new QVBoxLayout(tabInWidget1);


    // widget11

    widget11 = new QWidget(tabInWidget1);
    gridLayout11 = new QGridLayout(widget11);
    wetRadiobutton = new QRadioButton(tr("湿基标态"), widget11);
    dryRadiobutton = new QRadioButton(tr("干基标态"), widget11);
    group1 = new QButtonGroup(widget11);
    group1->addButton(wetRadiobutton, 0);
    group1->addButton(dryRadiobutton, 1);
    gasNumLabel = new QLabel(tr("烟气量(Nm3/h):"), widget11);
    gasTempLabel = new QLabel(tr("烟气温度(°C):"), widget11);
    pressureLabel = new QLabel(tr("当地平均大气压(mbar):"), widget11);
    gasNumLineedit = new QLineEdit(widget11);
    gasTempLineedit = new QLineEdit(widget11);
    pressureLineedit = new QLineEdit(widget11);
    gridLayout11->addWidget(wetRadiobutton, 0, 0, 1, 3);
    gridLayout11->addWidget(dryRadiobutton, 0, 3, 1, 3);
    gridLayout11->addWidget(gasNumLabel, 1, 0, 1, 3);
    gridLayout11->addWidget(gasNumLineedit, 1, 3, 1, 3);
    gridLayout11->addWidget(gasTempLabel, 2, 0, 1, 3);
    gridLayout11->addWidget(gasTempLineedit, 2, 3, 1, 3);
    gridLayout11->addWidget(pressureLabel, 3, 0, 1, 3);
    gridLayout11->addWidget(pressureLineedit, 3, 3, 1, 3);

    // widget12

    widget12 = new QWidget(tabInWidget1);
    gridLayout12 = new QGridLayout(widget12);
    gasComponentLabel = new QLabel(tr("烟气成分"), widget12);
    o2Label = new QLabel(tr("干基O2(vol%):"), widget12);
    co2Label = new QLabel(tr("干基CO2(vol%):"), widget12);
    h2oLabel = new QLabel(tr("烟气湿度(vol%):"), widget12);
    o2Lineedit = new QLineEdit(widget12);
    co2Lineedit = new QLineEdit(widget12);
    h2oLineedit = new QLineEdit(widget12);
    gridLayout12->addWidget(gasComponentLabel, 0, 0, 1, 6);
    gridLayout12->addWidget(o2Label, 1, 0, 1, 3);
    gridLayout12->addWidget(o2Lineedit, 1, 3, 1, 3);
    gridLayout12->addWidget(co2Label, 2, 0, 1, 3);
    gridLayout12->addWidget(co2Lineedit, 2, 3, 1, 3);
    gridLayout12->addWidget(h2oLabel, 3, 0, 1, 3);
    gridLayout12->addWidget(h2oLineedit, 3, 3, 1, 3);

    // widget13

    widget13 = new QWidget(tabInWidget1);
    gridLayout13 = new QGridLayout(widget13);
    dryCheckbox = new QCheckBox(tr("干基标态6%O2"), widget13);
    so2Label = new QLabel(tr("SO2(mg/Nm3):"), widget13);
    so3Label = new QLabel(tr("SO3(mg/Nm3):"), widget13);
    hclLabel = new QLabel(tr("HCL(mg/Nm3):"), widget13);
    hfLabel = new QLabel(tr("HF(mg/Nm3):"), widget13);
    dustLabel = new QLabel(tr("灰(mg/Nm3)"), widget13);
    so2Lineedit = new QLineEdit(widget13);
    so3Lineedit = new QLineEdit(widget13);
    hclLineedit = new QLineEdit(widget13);
    hfLineedit = new QLineEdit(widget13);
    dustLineedit = new QLineEdit(widget13);
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

    layout1->addWidget(widget11);
    layout1->addWidget(widget12);
    layout1->addWidget(widget13);
}

void inputParameterWindow::initWidget2()
{
    tabInWidget2 = new QWidget(this);
    layout2 = new QVBoxLayout(tabInWidget2);

    // widget21

    widget21 = new QWidget(tabInWidget2);
    caco3Combobox1 = new QComboBox(widget21);
    caco3Combobox2 = new QComboBox(widget21);
    otherCombobox = new QComboBox(widget21);
    caco3Lineedit1 = new QLineEdit(widget21);
    caco3Lineedit2 = new QLineEdit(widget21);
    otherLineedit = new QLineEdit(widget21);

    caco3ComponentLabel = new QLabel(tr("石灰石成分"), widget21);
    gridLayout21 = new QGridLayout(widget21);
    gridLayout21->addWidget(this->caco3ComponentLabel, 0, 0, 1, 6);
    gridLayout21->addWidget(this->caco3Combobox1, 1, 0, 1, 3);
    gridLayout21->addWidget(this->caco3Lineedit1, 1, 3, 1, 3);
    gridLayout21->addWidget(this->caco3Combobox2, 2, 0, 1, 3);
    gridLayout21->addWidget(this->caco3Lineedit2, 2, 3, 1, 3);
    gridLayout21->addWidget(this->otherCombobox, 3, 0, 1, 3);
    gridLayout21->addWidget(this->otherLineedit, 3, 3, 1, 3);

    // widget22

    widget22 = new QWidget(tabInWidget2);
    gridLayout22 = new QGridLayout(widget22);
    h2oQualityLabel = new QLabel(tr("工艺水质"), widget22);
    clLabel = new QLabel(tr("CL-(ppm):"), widget22);
    clLineedit = new QLineEdit(widget22);
    gridLayout22->addWidget(this->h2oQualityLabel, 0, 0, 1, 6);
    gridLayout22->addWidget(this->clLabel, 1, 0, 1, 3);
    gridLayout22->addWidget(this->clLineedit, 1, 3, 1, 3);

    // widget23

    widget23 = new QWidget(tabInWidget2);
    gridLayout23 = new QGridLayout(widget23);
    label20 = new QLabel(tr("其它参数"), widget23);
    label21 = new QLabel(tr("CaCO3(%)"), widget23);
    label22 = new QLabel(tr("脱硫效率(%)"), widget23);
    label23 = new QLabel(tr("氯化物含量(ppm)"), widget23);
    label24 = new QLabel(tr("石膏旋流器顶流含固量(%)"), widget23);
    label25 = new QLabel(tr("增压风机温升计算百分比(%)"), widget23);
    label26 = new QLabel(tr("GGH出口温度(°C)"), widget23);
    lineedit21 = new QLineEdit(widget23);
    lineedit22 = new QLineEdit(widget23);
    lineedit23 = new QLineEdit(widget23);
    lineedit24 = new QLineEdit(widget23);
    lineedit25 = new QLineEdit(widget23);
    lineedit26 = new QLineEdit(widget23);

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
    tabInWidget3 = new QWidget(this);
    gridLayout3 = new QGridLayout(tabInWidget3);
    label0 = new QLabel(tr("烟气流程上各设施的大致压降(mbar)"), tabInWidget3);
    label1 = new QLabel(tr("入口合流三通:"), tabInWidget3);
    label2 = new QLabel(tr("原烟气入口挡板阻力:"), tabInWidget3);
    label3 = new QLabel(tr("原烟气入口挡板阻力至增压风机烟道阻力:"), tabInWidget3);
    label4 = new QLabel(tr("增压风机至GGH原烟气烟道阻力:"), tabInWidget3);
    label5 = new QLabel(tr("GGH原烟气侧阻力:"), tabInWidget3);
    label6 = new QLabel(tr("GGH至吸收塔原烟气烟道阻力:"), tabInWidget3);
    label7 = new QLabel(tr("吸收塔至GGH净烟气烟道阻力:"), tabInWidget3);
    label8 = new QLabel(tr("GGH净烟气阻力:"), tabInWidget3);
    label9 = new QLabel(tr("GGH至净烟气出口挡板烟道阻力:"), tabInWidget3);
    label10 = new QLabel(tr("净烟气出口挡板阻力:"), tabInWidget3);
    label11 = new QLabel(tr("出口阻力:"), tabInWidget3);
    label12 = new QLabel(tr("烟囱阻力:"), tabInWidget3);

    lineedit1 = new QLineEdit(tabInWidget3);
    lineedit2 = new QLineEdit(tabInWidget3);
    lineedit3 = new QLineEdit(tabInWidget3);
    lineedit4 = new QLineEdit(tabInWidget3);
    lineedit5 = new QLineEdit(tabInWidget3);
    lineedit6 = new QLineEdit(tabInWidget3);
    lineedit7 = new QLineEdit(tabInWidget3);
    lineedit8 = new QLineEdit(tabInWidget3);
    lineedit9 = new QLineEdit(tabInWidget3);
    lineedit10 = new QLineEdit(tabInWidget3);
    lineedit11 = new QLineEdit(tabInWidget3);
    lineedit12 = new QLineEdit(tabInWidget3);


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
    inputParameterWindow::f1 = gasNumLineedit->text().toFloat();
    inputParameterWindow::shd = h2oLineedit->text().toFloat();
    inputParameterWindow::f6 = so2Lineedit->text().toFloat();
    inputParameterWindow::f7 = so3Lineedit->text().toFloat();
    inputParameterWindow::f8 = hclLineedit->text().toFloat();
    inputParameterWindow::f9 = hfLineedit->text().toFloat();
    inputParameterWindow::f10 = dustLineedit->text().toFloat();

    if (wetRadiobutton->isChecked())
    {
        gasResultPar::Gas[0][0][3] =gasNumLineedit->text().toFloat();
        gasResultPar::Gas[0][0][1] =gasResultPar::Gas[0][0][3] * inputParameterWindow::shd;
        gasResultPar::Gas[0][0][0] =gasResultPar::Gas[0][0][3] - gasResultPar::Gas[0][0][1];
        inputParameterWindow::bz1 = 1;
    }
    else if (dryRadiobutton->isChecked())
    {
        gasResultPar::Gas[0][0][0] = gasNumLineedit->text().toFloat();
        gasResultPar::Gas[0][0][1] =gasResultPar::Gas[0][0][0] / (1.0 / inputParameterWindow::shd - 1);
        gasResultPar::Gas[0][0][3] = gasResultPar::Gas[0][0][0] + gasResultPar::Gas[0][0][1];
        inputParameterWindow::bz1 = 2;
    }

    int gongkuang = 0;
    gasResultPar::Gas[gongkuang][0][8] = o2Lineedit->text().toFloat();
    gasResultPar::Gas[gongkuang][0][9] = co2Lineedit->text().toFloat();
    gasResultPar::Gas[gongkuang][0][21] = pressureLineedit->text().toFloat();
    gasResultPar::Gas[gongkuang][6][21] = pressureLineedit->text().toFloat();
    gasResultPar::Gas[gongkuang][0][22] = gasTempLineedit->text().toFloat();
    if(dryCheckbox->isChecked())
    {
        gasResultPar::Gas[gongkuang][0][15] = so2Lineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][17] = so3Lineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][18] = hclLineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][19] = hfLineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][20] = dustLineedit->text().toFloat();


        gasResultPar::Gas[gongkuang][0][10] = gasResultPar::Gas[gongkuang][0][15] * (21 - gasResultPar::Gas[gongkuang][0][8]) / (21 - 6);
        gasResultPar::Gas[gongkuang][0][11] = gasResultPar::Gas[gongkuang][0][17] * (21 - gasResultPar::Gas[gongkuang][0][8]) / (21 - 6);
        gasResultPar::Gas[gongkuang][0][12] = gasResultPar::Gas[gongkuang][0][18] * (21 - gasResultPar::Gas[gongkuang][0][8]) / (21 - 6);
        gasResultPar::Gas[gongkuang][0][13] = gasResultPar::Gas[gongkuang][0][19] * (21 - gasResultPar::Gas[gongkuang][0][8]) / (21 - 6);
        gasResultPar::Gas[gongkuang][0][14] = gasResultPar::Gas[gongkuang][0][20] * (21 - gasResultPar::Gas[gongkuang][0][8]) / (21 - 6);
        gasResultPar::Gas[gongkuang][0][16] = (gasResultPar::Gas[gongkuang][0][10] + gasResultPar::Gas[gongkuang][0][11] / constPar::mSO3 * constPar::mSO2) * (21 - 6) / (21 - gasResultPar::Gas[gongkuang][0][8]);

        inputParameterWindow::bz2 = 2;

    }
    else
    {
        gasResultPar::Gas[gongkuang][0][10] = so2Lineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][11] = so3Lineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][12] = hclLineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][13] = hfLineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][14] = dustLineedit->text().toFloat();
        gasResultPar::Gas[gongkuang][0][15] = gasResultPar::Gas[gongkuang][0][10] * (21 - 6) / (21 - gasResultPar::Gas[gongkuang][0][8]);
        gasResultPar::Gas[gongkuang][0][16] = (gasResultPar::Gas[gongkuang][0][10] + gasResultPar::Gas[gongkuang][0][11] / constPar::mSO3 * constPar::mSO2) * (21 - 6) / (21 - gasResultPar::Gas[gongkuang][0][8]);
        gasResultPar::Gas[gongkuang][0][17] = gasResultPar::Gas[gongkuang][0][11] * (21 - 6) / (21 - gasResultPar::Gas[gongkuang][0][8]);
        gasResultPar::Gas[gongkuang][0][18] = gasResultPar::Gas[gongkuang][0][12] * (21 - 6) / (21 - gasResultPar::Gas[gongkuang][0][8]);
        gasResultPar::Gas[gongkuang][0][19] = gasResultPar::Gas[gongkuang][0][13] * (21 - 6) / (21 - gasResultPar::Gas[gongkuang][0][8]);
        gasResultPar::Gas[gongkuang][0][20] = gasResultPar::Gas[gongkuang][0][14] * (21 - 6) / (21 - gasResultPar::Gas[gongkuang][0][8]);
    }

    if (caco3Combobox1->currentText() == "CaCO3")
    {
        pinfPar::VCaCO3 = caco3Lineedit1->text().toFloat();
    }
    else if (caco3Combobox1->currentText() == "CaO")
    {
        pinfPar::VCaCO3 = caco3Lineedit1->text().toFloat() / constPar::mCaO * constPar::mCaCO3;
    }

    if (caco3Combobox2->currentText() == "MgCO3")
    {
        pinfPar::VMgCO3 = caco3Lineedit2->text().toFloat();
    }
    else if (caco3Combobox2->currentText() == "MgO")
    {
        pinfPar::VMgCO3 = caco3Lineedit2->text().toFloat() / constPar::mMgO * constPar::mMgCO3;
    }
    pinfPar::Vother = otherLineedit->text().toFloat();


    //  工艺水

    gslResultPar::GSL[gongkuang][19][14] = clLineedit->text().toFloat();

    pinfPar::Pcaco3 = caco3ComponentLabel->text().toFloat();
    pinfPar::yS = lineedit22->text().toFloat();   // 脱硫效率
    gslResultPar::GSL[gongkuang][11][14] = lineedit23->text().toFloat();  // 废水中氯离子含量
    gslResultPar::GSL[gongkuang][5][16] = lineedit24->text().toFloat() / 100; // 石膏旋流器
    pinfPar::zysh = lineedit25->text().toFloat() / 100;
    gasResultPar::Gas[gongkuang][4][22] = lineedit26->text().toFloat();


    //

    pinfPar::PP1 = lineedit1->text().toFloat();
    pinfPar::PP2 = lineedit2->text().toFloat();
    pinfPar::PP3 = lineedit3->text().toFloat();
    pinfPar::PP4 = lineedit4->text().toFloat();
    pinfPar::PP5 = lineedit5->text().toFloat();
    pinfPar::PP6 = lineedit6->text().toFloat();
    pinfPar::PP7 = lineedit7->text().toFloat();
    pinfPar::PP8 = lineedit8->text().toFloat();
    pinfPar::PP9 = lineedit9->text().toFloat();
    pinfPar::PP10 = lineedit10->text().toFloat();
    pinfPar::PP11 = lineedit11->text().toFloat();
    pinfPar::PP12 = lineedit12->text().toFloat();
    pinfPar::PP13 = pinfPar::PP1 + pinfPar::PP2 +pinfPar::PP3 + pinfPar::PP4 + pinfPar::PP5+ pinfPar::PP6 +
            pinfPar::PP7+ pinfPar::PP8+ pinfPar::PP9 + pinfPar::PP10+ pinfPar::PP11+ pinfPar::PP12;
    inputParameterWindow::shr = 1;

}
inputParameterWindow::~inputParameterWindow()
{
    inputParameterWindow::num -= 1;
}

