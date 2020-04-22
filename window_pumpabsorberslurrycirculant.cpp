#include "window_pumpabsorberslurrycirculant.h"

int absorberSryCirPumpWindow::num = 0;

absorberSryCirPumpWindow::absorberSryCirPumpWindow(float & Yjxb, float & Qjxb, float * Hjxb, float * Nfjxb, float * Nejxb, float * Nkjxb, int & xg_, QWidget *parent) :
    QDialog(parent), yjxb(Yjxb), qjxb(Qjxb),hjxb(Hjxb), nfjxb(Nfjxb), nejxb(Nejxb), nkjxb(Nkjxb), xg(xg_)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    absorberSryCirPumpWindow::num += 1;
    this->hlayout1 = new QHBoxLayout;
    this->efficiencyLabel = new QLabel(tr("效率(%):"));
    this->efficiencyLineedit = new QLineEdit;
    this->efficiencyLineedit->setText(QString("%1").arg(yjxb * 100));
    this->hlayout1->addWidget(this->efficiencyLabel);
    this->hlayout1->addWidget(this->efficiencyLineedit);

    this->numLabel = new QLabel(tr("数量:"));
    this->numLineedit = new QLineEdit;
    this->numLineedit->setReadOnly(true);
    this->numLineedit->setText(QString("%1").arg(xg));
    this->hlayout1->addWidget(this->numLabel);
    this->hlayout1->addWidget(this->numLineedit);

    this->flowLabel = new QLabel(tr("流量(m3/h):"));
    this->flowLineedit = new QLineEdit;
    this->flowLineedit->setText(QString("%1").arg(qjxb));
    this->flowLineedit->setReadOnly(true);
    this->hlayout1->addWidget(this->flowLabel);
    this->hlayout1->addWidget(this->flowLineedit);
    this->tableWidget = new QTableWidget;
    this->initTableWidget();


    this->hlayout2 = new QHBoxLayout;
    this->okButton = new QPushButton(tr("确定"));
    this->cancelButton = new QPushButton(tr("关闭"));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    hlayout2->addWidget(this->okButton);
    hlayout2->addWidget(this->cancelButton);


    this->layout = new QVBoxLayout(this);
    this->layout->addLayout(this->hlayout1);
    this->layout->addWidget(this->tableWidget);
    this->layout->addLayout(this->hlayout2);


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


