#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_rotationalflowwasteh2o_base.h"

int wasteH2OrotationalFlow_window::num = 0;

wasteH2OrotationalFlow_window::wasteH2OrotationalFlow_window(float & qfx, float & xzfx, QWidget *parent): QDialog(parent), qfx(qfx), xzfx(xzfx)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    wasteH2OrotationalFlow_window::num += 1;
    layout = new QGridLayout(this);
    this->qfxLabel = new QLabel("处理量(m3/h):", this);
    this->qfxLineedit = new QLineEdit(this);
    this->qfxLineedit->setText(QString("%1").arg(qfx));

    this->layout->addWidget(this->qfxLabel, 0, 0, 1, 3);
    this->layout->addWidget(this->qfxLineedit, 0, 3, 1, 3);

    this->xzfxLabel = new QLabel("旋流子个数", this);
    this->xzfxLineedit = new QLineEdit(this);
    this->xzfxLineedit->setText(QString("%1").arg(xzfx));

    this->layout->addWidget(this->xzfxLabel, 1, 0, 1, 3);
    this->layout->addWidget(this->xzfxLineedit, 1, 3, 1, 3);

    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));

    this->layout->addWidget(buttonWidget, 2, 0, 1, 6);
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
