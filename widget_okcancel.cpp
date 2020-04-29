#include "widget_okcancel.h"

widget_okcancel::widget_okcancel(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    okButton = new QPushButton(tr("确定"), this);
    cancelButton = new QPushButton(tr("关闭"), this);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);
}
