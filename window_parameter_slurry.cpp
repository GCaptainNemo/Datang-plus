#include "window_parameter_slurry.h"


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


window_parameter_slurry::window_parameter_slurry(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("浆液参数"));


    layout = new QVBoxLayout(this);
    tableWidget = new QTableWidget(this);
    layout->addWidget(tableWidget);
    this->initTableWidget();
    this->resize(800, 1000);
    this->showNormal();
}

void window_parameter_slurry::initTableWidget()
{
    QStringList verticalHeader;
    verticalHeader << "总质量流量" << "总体积流量" << "含可溶性盐分的H2O" << "总含固量" << "石膏"<< "亚硫酸钙"
                   << "CaCO3"<< "MgCO3" << "CaF2"<< "MgF2"<< "灰尘"<< "灰" << "惰性物质" << "溶解物质" << "氯化物含量"<< "密度"
                   << "总含固量" << "温度" ;

    QStringList unitColumn;
    unitColumn << "kg/h" << "m3/h"<< "kg/h" << "kg/h"<< "kg/h"<< "kg/h" << "kg/h" << "kg/h"
                << "kg/h" << "kg/h"  << "kg/h"<< "kg/h"<< "kg/h"<< "kg/h"<< "ppm"
                << "kg/m3"<< "%"<< "°C";

    QFont font ;//定义一个字体变量
    font.setBold(true);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableWidget->verticalHeader()->setHidden(true);
    tableWidget->horizontalHeader()->setHidden(true);
    qDebug() << "size = " << verticalHeader.size();

    this->tableWidget->setRowCount(verticalHeader.size());
    this->tableWidget->setColumnCount(3);
    for(int i = 0; i <verticalHeader.size(); i++)
    {
        this->tableWidget->setItem(i, 0, new QTableWidgetItem(verticalHeader[i]));
        this->tableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        this->tableWidget->item(i, 0)->setFont(font);
        this->tableWidget->setItem(i, 1, new QTableWidgetItem(QString("%1").arg(gasResultPar::Gas[0][0][i])));
        this->tableWidget->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        this->tableWidget->item(i, 1)->setFont(font);
        this->tableWidget->setItem(i, 2, new QTableWidgetItem(unitColumn[i]));
        this->tableWidget->item(i, 2)->setFont(font);
        this->tableWidget->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }
}
