#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_pump_absorberslurrycirculant.h"

int absorberSryCirPumpWindow::num = 0;

absorberSryCirPumpWindow::absorberSryCirPumpWindow(float & Yjxb, float & Qjxb, float * Hjxb, float * Nfjxb, float * Nejxb, float * Nkjxb, int & xg_, QWidget *parent) :
    QDialog(parent), yjxb(Yjxb), qjxb(Qjxb),hjxb(Hjxb), nfjxb(Nfjxb), nejxb(Nejxb), nkjxb(Nkjxb), xg(xg_)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    absorberSryCirPumpWindow::num += 1;
    layout = new QGridLayout(this);
    this->efficiencyLabel = new QLabel(tr("效率(%):"), this);
    this->efficiencyLineedit = new QLineEdit(this);
    this->efficiencyLineedit->setText(QString("%1").arg(yjxb * 100));

    this->numLabel = new QLabel(tr("数量:"), this);
    this->numLineedit = new QLineEdit(this);
    this->numLineedit->setReadOnly(true);
    this->numLineedit->setText(QString("%1").arg(xg));

    this->flowLabel = new QLabel(tr("流量(m3/h):"), this);
    this->flowLineedit = new QLineEdit(this);
    this->flowLineedit->setText(QString("%1").arg(qjxb));
    this->flowLineedit->setReadOnly(true);
    layout->addWidget(this->efficiencyLabel, 0, 0, 1, 3);
    layout->addWidget(this->efficiencyLineedit, 0, 3, 1, 3);
    layout->addWidget(this->numLabel, 0, 6, 1, 3);
    layout->addWidget(this->numLineedit, 0, 9, 1, 3);
    layout->addWidget(this->flowLabel, 0, 12, 1, 3);
    layout->addWidget(this->flowLineedit, 0, 15, 1, 3);


    this->tableWidget = new QTableWidget(this);
    this->initTableWidget();


    layout->addWidget(this->tableWidget, 1, 0, 6, 18);

    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    layout->addWidget(this->buttonWidget, 7, 0, 1, 18);

    this->setWindowTitle(tr("吸收塔浆液循环泵"));
    this->show();
}

absorberSryCirPumpWindow::~absorberSryCirPumpWindow()
{
    absorberSryCirPumpWindow::num -= 1;
}

void absorberSryCirPumpWindow::initTableWidget()
{
    this->tableWidget->setColumnCount(4);
    this->tableWidget->setRowCount(xg);
    this->headers <<"扬程(m)" << "轴功率(kW)" <<
              "电机功率(kW)" << "电机功率靠档(kW)";
    this->tableWidget->setHorizontalHeaderLabels(this->headers);
    QTableWidgetItem * item;
    for(int i = 0;i < xg; i++ )
    {
        item = new QTableWidgetItem(QString("%1").arg(hjxb[i]));
        this->tableWidget->setItem(i, 0, item);
        this->tableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        item = new QTableWidgetItem(QString("%1").arg(nfjxb[i]));
        this->tableWidget->setItem(i, 1, item);
        this->tableWidget->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        item = new QTableWidgetItem(QString("%1").arg(nejxb[i]));
        this->tableWidget->setItem(i, 2, item);
        this->tableWidget->item(i, 2)->setTextAlignment(Qt::AlignCenter);

        QComboBox * kaodang = new QComboBox();
        utils::setKdComboBox(kaodang, nkjxb[i]);
        this->tableWidget->setCellWidget(i, 3, kaodang);
    }
}


