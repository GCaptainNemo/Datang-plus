#include "widget_central.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    this->vlayout = new QVBoxLayout(this);
//    this->setLayout(this->vlayout);
    this->hsplitter = new QSplitter(Qt::Horizontal, 0);
    this->vlayout->addWidget(this->hsplitter);
    this->tree_widget = new QTreeWidget;
    this->table_widget = new QTableWidget;
    hsplitter->addWidget(this->tree_widget);
    hsplitter->addWidget(this->table_widget);
};
