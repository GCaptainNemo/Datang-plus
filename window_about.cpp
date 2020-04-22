#include "window_about.h"

int about_window::num = 0;

about_window::about_window(QWidget * parent):QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    about_window::num += 1;
    this->softwareLabel = new QLabel("烟气脱硫物料平衡计算软件");
    this->versionLabel = new QLabel("版本号");
    this->companyLabel = new QLabel("中国大唐集团科技工程有限公司");
    this->resLabel = new QLabel(Login_window::version);
    this->okButton = new QPushButton("确定");

    this->layout = new QGridLayout(this);
    this->layout->addWidget(softwareLabel, 0, 0, 1, 3);
    this->layout->addWidget(versionLabel, 1, 0, 1, 1);
    this->layout->addWidget(resLabel, 1, 1, 1, 2);

    this->layout->addWidget(companyLabel, 2, 0, 1, 3);
    this->layout->addWidget(okButton, 3, 1, 1, 1);

    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle("关于");
    this->show();

}


about_window::~about_window()
{
    about_window::num -= 1;
}
