#include "window_systemconfiguration.h"

int systemConfigurationWindow::num = 0;
int systemConfigurationWindow::pzh = 0;

systemConfigurationWindow::systemConfigurationWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);


    systemConfigurationWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("系统配置"));

    qDebug() << "state1";

    // widget1

    widget1 = new QWidget;
    group1 = new QButtonGroup(this);
    gghSystemCheckbox = new QCheckBox(tr("GGH系统"));
    pAirBlowerCheckbox = new QCheckBox(tr("增压风机"));
    vacuumCheckbox = new QCheckBox(tr("真空皮带脱水机"));
    wasteH2Ocheckbox = new QCheckBox(tr("废水旋流机"));
    waterPumpCheckbox = new QCheckBox(tr("单独设置除雾器冲洗水泵"));
    group1->addButton(gghSystemCheckbox, 0);
    group1->addButton(pAirBlowerCheckbox, 1);
    group1->addButton(vacuumCheckbox, 2);
    group1->addButton(wasteH2Ocheckbox, 3);
    group1->addButton(waterPumpCheckbox, 4);
    group1->setExclusive(false);
    connect(group1, SIGNAL(buttonClicked(int)), this, SLOT(group1SLOT(int)));
    vlayout1 = new QVBoxLayout(widget1);
    vlayout1->addWidget(gghSystemCheckbox);
    vlayout1->addWidget(pAirBlowerCheckbox);
    vlayout1->addWidget(vacuumCheckbox);
    vlayout1->addWidget(wasteH2Ocheckbox);
    vlayout1->addWidget(waterPumpCheckbox);

    // widget2

    widget2 = new QWidget;
    styleLabel = new QLabel(tr("吸收剂制备方式 :"));
    group2 = new QButtonGroup(this);
    wetCaco3Radiobutton = new QRadioButton(tr("石灰石湿磨制浆"));
    caco3Radiobutton = new QRadioButton(tr("石灰石粉制浆"));
    group2->addButton(wetCaco3Radiobutton, 0);
    group2->addButton(caco3Radiobutton, 1);
    connect(group2, SIGNAL(buttonClicked(int)), this, SLOT(group2SLOT(int)));
    gridLayout2 = new QGridLayout(widget2);
    gridLayout2->addWidget(styleLabel, 0, 0, 1, 6);
    gridLayout2->addWidget(caco3Radiobutton, 1, 0, 1, 3);
    gridLayout2->addWidget(wetCaco3Radiobutton, 1, 3, 1, 3);

    // widget3

    widget3 = new QWidget;
    this->proH2Ocheckbox = new QCheckBox(tr("采用工艺水制浆"));
    this->addLabel = new QLabel(tr("滤液制浆时，若55路滤液不足，添加"));
    this->addCombobox = new QComboBox;
    gridLayout3 = new QGridLayout(widget3);
    gridLayout3->addWidget(this->proH2Ocheckbox, 0, 0, 1, 6);
    gridLayout3->addWidget(this->addLabel, 1, 0, 1, 3);
    gridLayout3->addWidget(this->addCombobox, 1, 3, 1, 3);
    connect(proH2Ocheckbox, SIGNAL(stateChanged(int)), this, SLOT(hideAddSLOT(int)));

    // widget4

    widget4 = new QWidget;
    this->okButton = new QPushButton("确定");
    this->cancelButton = new QPushButton("关闭");
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    gridLayout4 = new QGridLayout(widget4);
    gridLayout4->addWidget(this->okButton, 0, 0, 1, 3);
    gridLayout4->addWidget(this->cancelButton, 0, 3, 1, 3);


    layout = new QVBoxLayout(this);
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    layout->addWidget(widget3);
    layout->addWidget(widget4);
    this->initButtonState();
    this->show();
}


void systemConfigurationWindow::hideAddSLOT(const int &state)
{
    if(state == Qt::Checked)
//    if this->proH2Ocheckbox->checkState()
    {
        this->addLabel->hide();
        this->addCombobox->hide();
    }
    else{
        this->addLabel->show();
        this->addCombobox->show();
    }


}

void systemConfigurationWindow::initButtonState()
{
    this->addCombobox->addItem(tr("46 路旋流器顶流"));
    this->addCombobox->addItem(tr("63 路工艺水"));


    if(pinf::shihui == 0)
        caco3Radiobutton->setChecked(true);
    else
        wetCaco3Radiobutton->setChecked(true);
    if (systemConfigurationWindow::pzh == 1){

        if (pinf::zhengong)
            vacuumCheckbox->setChecked(true);
        else
            vacuumCheckbox->setChecked(false);

        if (pinf::feishui)
            wasteH2Ocheckbox->setChecked(true);
        else
            wasteH2Ocheckbox->setChecked(false);

        if (pinf::huanre)
            gghSystemCheckbox->setChecked(true);
        else
            gghSystemCheckbox->setChecked(false);

        if (pinf::zengya)
            pAirBlowerCheckbox->setChecked(true);
        else
            pAirBlowerCheckbox->setChecked(false);

        if (pinf::shuibeng)
            waterPumpCheckbox->setChecked(true);
        else
            waterPumpCheckbox->setChecked(false);

        if (pinf::gongyi)
            proH2Ocheckbox->setChecked(true);
        else
            proH2Ocheckbox->setChecked(false);


        if (pinf::tianjia == 0)
            addCombobox->setCurrentIndex(0);
        else
            addCombobox->setCurrentIndex(1);
    }
    else{
        vacuumCheckbox->setChecked(true);
        wasteH2Ocheckbox->setChecked(false);
        gghSystemCheckbox->setChecked(false);
        pAirBlowerCheckbox->setChecked(true);
        waterPumpCheckbox->setChecked(true);
        proH2Ocheckbox->setChecked(false);
    }

}

systemConfigurationWindow::~systemConfigurationWindow()
{
    systemConfigurationWindow::num -= 1;

}


void systemConfigurationWindow::okSLOT()
{

}


void systemConfigurationWindow::group1SLOT(int p)
{
    qDebug() << QString("button %1 is selected ").arg(p);

}


void systemConfigurationWindow::group2SLOT(int p)
{
    qDebug() << QString("button %1 is selected ").arg(p);

}
