#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "widget_okcancel.h"

widget_okcancel::widget_okcancel(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    okButton = new QPushButton(tr("确定"), this);
    cancelButton = new QPushButton(tr("关闭"), this);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);
}
