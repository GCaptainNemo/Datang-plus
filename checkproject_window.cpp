#include "checkproject_window.h"

int checkPjWindow::num = 0;

checkPjWindow::checkPjWindow(QWidget *parent) : QWidget(parent)
{

    checkPjWindow::num += 1;

    this->setWindowTitle(tr("校核项目"));
    this->resize(1000, 800);


    this->checkOpinionTextedit = new QTextEdit;


    this->bg = new QButtonGroup(this);
    this->passRadioButton = new QRadioButton(tr("校核通过"));
    this->recalculateRadioButton= new QRadioButton(tr("重新计算"));
    this->bg->addButton(this->passRadioButton, 1);
    this->bg->addButton(this->recalculateRadioButton, 0);


    this->hlayout1 = new QHBoxLayout;
    this->hlayout1->addWidget(this->passRadioButton);
    this->hlayout1->addWidget(this->recalculateRadioButton);


    this->okButton = new QPushButton("确定");
    this->cancelButton = new QPushButton("取消");


    this->hlayout2 = new QHBoxLayout;
    this->hlayout2->addWidget(this->okButton);
    this->hlayout2->addWidget(this->cancelButton);


    this->layout = new QVBoxLayout(this);
    this->layout->addWidget(this->checkOpinionTextedit);
    this->layout->addLayout(this->hlayout1);
    this->layout->addLayout(this->hlayout2);


    connect(bg, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeSLOT()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    this->setAttribute(Qt::WA_DeleteOnClose);


    this->show();
}

checkPjWindow::~checkPjWindow(){
    checkPjWindow::num -= 1;
}



void checkPjWindow::operatingModeSLOT()
{
    switch(bg->checkedId())
    {
    case 0:
        std::cout << 0 << std::endl;
        break;
    case 1:
        std::cout << 1 ;
    default:
        break;
    }
}
