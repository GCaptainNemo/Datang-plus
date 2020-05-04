#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "window_parameter_flue_gas.h"

window_parameter_flue_gas::window_parameter_flue_gas(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("烟气参数"));


    layout = new QVBoxLayout(this);
    tableWidget = new QTableWidget(this);
    layout->addWidget(tableWidget);
    this->initTableWidget();
    this->resize(800, 1000);
    this->showNormal();
}

void window_parameter_flue_gas::initTableWidget()
{
    QStringList verticalHeader;
    verticalHeader << "总流量(干态)" << "H2O(蒸汽)" << "H2O(液态)" << "总流量(湿)" << "总质量流量"<< "实际流量"
                   << "SO2"<< "SO3" << "O2"<< "CO2"<< "SO2"<< "SO3" << "HCl" << "HF" << "灰"<< "SO2 at 6% O2"
                   << "SOx as SO2 at 6% O2" << "SO3 at 6% O2" << "HCl at 6% O2" << "HF at 6% O2" << "Ash at 6% O2"
                   << "压力" << "温度";

    QStringList unitColumn;
    unitColumn << "Nm3/h" << "Nm3/h"<< "kg/h" << "Nm3/h"<< "kg/h"<< "Am3/h" << "kg/h" << "kg/h"
                << "Vol %" << "Vol %"  << "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"
                << "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3" << "mbar" << "°C";
    QStringList otherColumn;
    otherColumn << "" << ""<< "" << ""<< ""<< "" << "" << ""
                << "标态、干基、实际O2" << ""  << ""<< ""<< ""<< ""<< ""
                << ""<< ""<< ""<< ""<< ""<< "" << "" << "";
    QFont font ;//定义一个字体变量
    font.setBold(true);

    tableWidget->verticalHeader()->setHidden(true);
    tableWidget->horizontalHeader()->setHidden(true);
    qDebug() << "size = " << verticalHeader.size();

    this->tableWidget->setRowCount(verticalHeader.size());
    this->tableWidget->setColumnCount(4);
    int guanxian = 1;
    for(int i = 0; i <verticalHeader.size(); i++)
    {
        if (i < 8 || i > 14){
            tableWidget->setSpan(i, 0, 1, 2);

        }

        this->tableWidget->setItem(i, 0, new QTableWidgetItem(verticalHeader[i]));
        this->tableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        this->tableWidget->item(i, 0)->setFont(font);
        this->tableWidget->setItem(i, 1, new QTableWidgetItem(otherColumn[i]));
        this->tableWidget->item(i, 1)->setFont(font);
        this->tableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(gasResultPar::Gas[0][guanxian][i])));
        this->tableWidget->item(i, 2)->setTextAlignment(Qt::AlignCenter);
        this->tableWidget->item(i, 2)->setFont(font);
        this->tableWidget->setItem(i, 3, new QTableWidgetItem(unitColumn[i]));
        this->tableWidget->item(i, 3)->setFont(font);
        this->tableWidget->item(i, 3)->setTextAlignment(Qt::AlignCenter);
    }
    tableWidget->setSpan(8, 1, 7, 1);
}
