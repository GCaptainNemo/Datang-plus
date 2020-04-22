#include "window_projectnew.h"
#include <iostream>

int newPjWindow::num = 0;

newPjWindow::newPjWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    newPjWindow::num += 1;
    this->nameLabel = new QLabel(tr("项目名称"));
    this->nameLineedit = new QLineEdit;
    this->okButton = new QPushButton("确定");
    this->layout = new QHBoxLayout(this);
    this->layout->addWidget(this->nameLabel);
    this->layout->addWidget(this->nameLineedit);
    this->layout->addWidget(this->okButton);

    connect(okButton, SIGNAL(clicked()), this, SLOT(okAction()));
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->show();
    this->setWindowTitle(tr("新建项目"));

}

newPjWindow::~newPjWindow(){
    newPjWindow::num -= 1;
}


void newPjWindow::okAction()
{
    QString name = this->nameLineedit->text();
}


