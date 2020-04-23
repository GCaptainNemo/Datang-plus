#include "window_rotationalflowwasteh2o_base.h"

int wasteH2OrotationalFlow_window::num = 0;

wasteH2OrotationalFlow_window::wasteH2OrotationalFlow_window(float & qfx, float & xzfx, QWidget *parent): QDialog(parent), qfx(qfx), xzfx(xzfx)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    wasteH2OrotationalFlow_window::num += 1;
    this->qfxLabel = new QLabel("处理量(m3/h):");
    this->qfxLineedit = new QLineEdit;
    this->qfxLineedit->setText(QString("%1").arg(qfx));

    this->hlayout1 = new QHBoxLayout;
    this->hlayout1->addWidget(this->qfxLabel);
    this->hlayout1->addWidget(this->qfxLineedit);
    
    
    this->xzfxLabel = new QLabel("旋流子个数");
    this->xzfxLineedit = new QLineEdit;
    this->xzfxLineedit->setText(QString("%1").arg(xzfx));

    this->hlayout2 = new QHBoxLayout;
    this->hlayout2->addWidget(this->xzfxLabel);
    this->hlayout2->addWidget(this->xzfxLineedit);
    
    this->okButton = new QPushButton("确定");
    this->cancelButton = new QPushButton("关闭");
    this->hlayout3 = new QHBoxLayout;
    this->hlayout3->addWidget(this->okButton);
    this->hlayout3->addWidget(this->cancelButton);
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));

    this->layout = new QVBoxLayout(this);
    this->layout->addLayout(this->hlayout1);
    this->layout->addLayout(this->hlayout2);
    this->layout->addLayout(this->hlayout3);

    this->setWindowTitle(tr("废水旋流器"));
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();
}


wasteH2OrotationalFlow_window::~wasteH2OrotationalFlow_window()
{
    wasteH2OrotationalFlow_window::num -= 1;
}

void wasteH2OrotationalFlow_window::okSLOT()
{
    bool ok1, ok2;
    float a1 = this->qfxLineedit->text().toFloat(&ok1);
    float a2 = this->xzfxLineedit->text().toFloat(&ok2);
    if (ok1 && ok2){
        this->qfx = a1;
        this->xzfx = a2;
        QMessageBox::information(this, tr("提示"), tr("参数修改成功"));
        this->close();
    }
    else{
        QMessageBox::warning(this, tr("错误"), tr("请填入合法数据"));
    }

}
