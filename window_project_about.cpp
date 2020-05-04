#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_project_about.h"

int about_window::num = 0;

about_window::about_window(QWidget * parent):QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    about_window::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("关于");

    this->softwareLabel = new QLabel("烟气脱硫物料平衡计算软件", this);
    this->versionLabel = new QLabel("版本号", this);
    this->companyLabel = new QLabel("中国大唐集团科技工程有限公司", this);
    this->resLabel = new QLabel(otherPar::version, this);
    this->okButton = new QPushButton("确定", this);
    this->layout = new QGridLayout(this);
    this->layout->addWidget(softwareLabel, 0, 0, 1, 3);
    this->layout->addWidget(versionLabel, 1, 0, 1, 1);
    this->layout->addWidget(resLabel, 1, 1, 1, 2);
    this->layout->addWidget(companyLabel, 2, 0, 1, 3);
    this->layout->addWidget(okButton, 3, 1, 1, 1);
    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    this->show();

}


about_window::~about_window()
{
    about_window::num -= 1;
}
