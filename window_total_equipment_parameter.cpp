#include "window_total_equipment_parameter.h"

int window_total_equipment_parameter::num = 0;

window_total_equipment_parameter::window_total_equipment_parameter(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    window_total_equipment_parameter::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("设备参数汇总"));


    layout = new QGridLayout(this);
    buttonWidget = new widget_okcancel(this);
    buttonWidget->okButton->setText(tr("导出Excel"));
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(exportSLOT()));
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    tableWidget = new QTableWidget(this);
    layout->addWidget(tableWidget, 0, 0, 10, 10);
    layout->addWidget(buttonWidget, 10, 3, 1, 4);
    this->initTableWidget();

    this->showMaximized();

}

window_total_equipment_parameter::~window_total_equipment_parameter()
{
    window_total_equipment_parameter::num -= 1;
}

void window_total_equipment_parameter::initTableWidget()
{
    this->tableWidget->setColumnCount(5);
    this->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    rowheadStringList << "序号" << "名称" << "规格"  << "数量" << "备注";
    this->tableWidget->setHorizontalHeaderLabels(rowheadStringList);
    columnheadStringList << "一、" << "1" << "2" << "二、" << "1" << "2" << "3" << "4" << "三、" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" <<
                  "四、" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "五、" << "1" << "2" <<"3" << "六、"<< "1" << "2" <<"3" <<
                  "七、" << "1" << "2";

    equipNameStringList << "烟气系统" << "增压风机" << "烟气换热器" << "SO2吸收系统" << "氧化风机" << "浆液循环泵" <<
                 "吸收塔搅拌器" << "石膏排除泵" << "石膏脱水系统" << "石膏旋流器" << "真空皮带脱水机" << "真空泵"
              << "滤布冲洗水箱" << "滤布冲洗水泵" << "滤液箱" << "滤液箱搅拌器" << "滤液泵" << "浆液制备系统" <<
                 "石灰石仓" << "湿式球磨机" << "石灰石浆液循环箱" <<"石灰石浆液循环箱搅拌器" <<"石灰石浆液循环泵" <<
                 "石灰石旋流器" <<"石灰石浆液箱" <<"石灰石浆液箱搅拌器" << "石灰石浆液泵"<<"工艺水系统" <<
                 "工艺水箱" << "工艺水泵" <<"除雾器冲洗水泵" <<"事故浆液系统" <<"事故浆液箱" <<"事故浆液箱搅拌器" <<
                 "事故浆液箱泵" << "废水处理系统" <<"废水旋流器" << "废水旋流器给料泵";

    specificationStringList << "" << QString("实际流量%1m3/h, 压升%2mbar、轴功率%3kW、T.B.点流量%4m3/h、T.B.压升%5mbar、T.B.轴功率%6kW、电机功率%7kW").arg(flueGasSystem::Qfan).arg(flueGasSystem::Pfan).arg(flueGasSystem::Nffan).arg(flueGasSystem::Qfand).arg(flueGasSystem::Pfand).arg(flueGasSystem::Ndfan).arg(flueGasSystem::Nkfan)
                            << QString("原烟气进口温度%1°C、净烟气进口温度%2°C、出口温度80°C、烟气流量%3m3/h").arg(gasResultPar::Gas[0][1][22]).arg(gasResultPar::Gas[0][4][22]).arg(gasResultPar::Gas[0][1][4]) << ""


                            << QString("湿基标态流量%1 m3/h、风机选型流量%2 m3/h、压升%3 mbar、轴功率%4kW、电机功率%5kW").arg(so2AbsorbSystem::Qyang).arg(so2AbsorbSystem::QXyang).arg(so2AbsorbSystem::Pyang).arg(so2AbsorbSystem::Nfyang).arg(so2AbsorbSystem::Nkyang)
                            << QString("轴功率%1kW、电机功率%2kW").arg(so2AbsorbSystem::Nfxsh).arg(so2AbsorbSystem::Nkxsh)
                            << QString("流量%1m3/h、扬程%2m、轴功率%3kW、电机功率%4kW").arg(so2AbsorbSystem::Qshpb).arg(so2AbsorbSystem::Hshpb).arg(so2AbsorbSystem::Nfshpb).arg(so2AbsorbSystem::Nkshpb) << ""

                            << QString("流量%1m3/h").arg(caso4ExtractH2Osystem::Qshgx)
                            << QString("最大出力%1t/h、过滤面积%2m2、主驱动电机功率%3kW").arg(caso4ExtractH2Osystem::Qzhk).arg(caso4ExtractH2Osystem::Szhk).arg(caso4ExtractH2Osystem::Nezhk)
                            << QString("真空泵出力%1m3/h、轴功率%2kW、电机功率%3kW").arg(caso4ExtractH2Osystem::Qzhb).arg(caso4ExtractH2Osystem::Nfzhb).arg(caso4ExtractH2Osystem::Nezhk)
                            << QString("直径%1m、高度%2m、有效容积%3m3").arg(caso4ExtractH2Osystem::Dlb).arg(caso4ExtractH2Osystem::Hlb).arg(caso4ExtractH2Osystem::Vjlb)
                            << QString("流量%1m3/h、扬程%2m、功率%3kW").arg(caso4ExtractH2Osystem::Qlbb).arg(caso4ExtractH2Osystem::Hlbb).arg(caso4ExtractH2Osystem::Nelbb)
                            << QString("要求存储时间%1h、直径%2m、高度%3m、有效容积%4m3、总容积%5m3").arg(caso4ExtractH2Osystem::Tlx).arg(caso4ExtractH2Osystem::Dlx).arg(caso4ExtractH2Osystem::Hlx).arg(caso4ExtractH2Osystem::Vjlx).arg(caso4ExtractH2Osystem::VTjlx)
                            << QString("轴功率%1kW、电机功率%2mkW").arg(caso4ExtractH2Osystem::Nflx).arg(caso4ExtractH2Osystem::Nklx)
                            << QString("流量%1m3/h、扬程%2m、轴功率%3kW、电机功率%4kW").arg(caso4ExtractH2Osystem::Qlyb).arg(caso4ExtractH2Osystem::Hlyb).arg(caso4ExtractH2Osystem::Nflyb).arg(caso4ExtractH2Osystem::Nklyb) << ""

                            << QString("直径%1m、筒段高度%2m、锥段高度%3m、有效容积%4m3、总容积%5m3").arg(slurryPreSystem::Dshc).arg(slurryPreSystem::H1shc).arg(slurryPreSystem::H2shc).arg(slurryPreSystem::Vjshc).arg(slurryPreSystem::VTjshc)
                            << QString("最大出力%1t/h、轴功率%2kW、电机功率%3kW").arg(slurryPreSystem::Qmj).arg(slurryPreSystem::Nfmj).arg(slurryPreSystem::Nemj)
                            << QString("直径%1m、高度%2m、有效容积%3m3、总容积%4m3").arg(slurryPreSystem::Dsjx).arg(slurryPreSystem::Hsjx).arg(slurryPreSystem::Vjsjx).arg(slurryPreSystem::VTjsjx)
                            << QString("轴功率%1kW、电机功率%2kW").arg(slurryPreSystem::Nfsjx).arg(slurryPreSystem::Nksjx)
                            << QString("流量%1m3/h、扬程%2m、轴功率%3kW、电机功率%4kW").arg(slurryPreSystem::Qshjxb).arg(slurryPreSystem::Hshjxb).arg(slurryPreSystem::Nfshjxb).arg(slurryPreSystem::Nkshjxb)
                            << QString("流量%1m3/h").arg(slurryPreSystem::Qshhx)
                            << QString("直径%1m、高度%2m、有效容积%3m3、总容积%4m3").arg(slurryPreSystem::Dsj).arg(slurryPreSystem::Hsj).arg(slurryPreSystem::Vjsj).arg(slurryPreSystem::VTjsj)
                            << QString("轴功率%1kW、电机功率%2kW").arg(slurryPreSystem::Nfsj).arg(slurryPreSystem::Nksj)
                            << QString("流量%1m、扬程%2m、轴功率%3kW、电机功率%4kW").arg(slurryPreSystem::Qshjb).arg(slurryPreSystem::Hshjb).arg(slurryPreSystem::Nfshjb).arg(slurryPreSystem::Nkshjb) << ""

                            << QString("直径%1m、高度%2m、有效容积%3m3、总容积%4m3").arg(processH2Osystem::Dgy).arg(processH2Osystem::Hgy).arg(processH2Osystem::Vjgy).arg(processH2Osystem::VTjgy)
                            << QString("流量%1m、扬程%2m、轴功率%3kW、电机功率%4kW").arg(processH2Osystem::Qgyb).arg(processH2Osystem::Hgyb).arg(processH2Osystem::Nfgyb).arg(processH2Osystem::Nkgyb)
                            << QString("流量%1m、扬程%2m、轴功率%3kW、电机功率%4kW").arg(processH2Osystem::Qccb).arg(processH2Osystem::Hccb).arg(processH2Osystem::Nfccb).arg(processH2Osystem::Nkccb) << ""

                            << QString("直径%1m、高度%2m、有效容积%3m3、总容积%4m3").arg(emergencySlurrySystem::Dshg).arg(emergencySlurrySystem::Hshg).arg(emergencySlurrySystem::Vshg).arg(emergencySlurrySystem::VTshg)
                            << QString("轴功率%1kW、电机功率%2kW").arg(emergencySlurrySystem::Nfshg).arg(emergencySlurrySystem::Nkshg)
                            << QString("流量%1m、扬程%2m、轴功率%3kW、电机功率%4kW").arg(emergencySlurrySystem::Qshgb).arg(emergencySlurrySystem::Hshgb).arg(emergencySlurrySystem::Nfshgb).arg(emergencySlurrySystem::Nkshgb) << ""

                            << QString("流量%1m3/h").arg(wasteH2OproSystem::Qfx)
                            << QString("流量%1m3/h、扬程%2m、轴功率%3kW、电机功率%4kW").arg(wasteH2OproSystem::Qfshb).arg(wasteH2OproSystem::Hfshb).arg(wasteH2OproSystem::Nffshb).arg(wasteH2OproSystem::Nkfshb);

    equipNumStringList << "" << "1" << "1" << "" << "1" << QString("%1").arg(so2AbsorbSystem::xg) << QString("%1").arg(absorberSystem::NUMjb) << "1" << ""
                        << "1" << "1" << "1" << "1" << "1" << "1" << "1" << "1" << ""
                        << "1" << "1" << "1" << "1" << "1" << "1" << "1" << "1" << "1" << ""
                        << "1" << "1" << "1" <<""
                        << "1" << "1" << "1" << ""
                        << "1" << "1";




    QString jyxhb = QString("流量%1").arg(so2AbsorbSystem::Qjxb);
    specificationStringList.insert(5, jyxhb);

    for(int i = so2AbsorbSystem::xg - 1; i>=0 ;--i)
    {
        this->columnheadStringList.insert(6, "");
        this->equipNameStringList.insert(6, "");
        this->specificationStringList.insert(6, QString("第%1个泵的参数: 扬程%2m, 轴功率%3kW, 电机功率%4kW").arg(i + 1).arg(so2AbsorbSystem::Hjxb[i]).arg(so2AbsorbSystem::Nfjxb[i]).arg(so2AbsorbSystem::Nkjxb[i]));
        this->equipNumStringList.insert(6, "");

    }

    this->judgePop();

    QFont font ;//定义一个字体变量
    font.setBold(true);

    tableWidget->verticalHeader()->setHidden(true);
    qDebug() << "size = " << columnheadStringList.size();

    this->tableWidget->setRowCount(columnheadStringList.size());

    for(int i = 0; i < columnheadStringList.size(); i++)
    {
        this->tableWidget->setItem(i, 0, new QTableWidgetItem(columnheadStringList[i]));
        this->tableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        this->tableWidget->item(i, 0)->setFont(font);
        this->tableWidget->setItem(i, 1, new QTableWidgetItem(equipNameStringList[i]));
        this->tableWidget->item(i, 1)->setFont(font);
        this->tableWidget->setItem(i, 2, new QTableWidgetItem(specificationStringList[i]));
        this->tableWidget->item(i, 2)->setFont(font);
        this->tableWidget->setItem(i, 3, new QTableWidgetItem(equipNumStringList[i]));
        this->tableWidget->item(i, 3)->setFont(font);
        this->tableWidget->item(i, 3)->setTextAlignment(Qt::AlignCenter);
    }
    QRegExp rx("浆液循环泵");
    int index = this->equipNameStringList.indexOf(rx);
    tableWidget->setSpan(index, 0, so2AbsorbSystem::xg + 1, 1);
    tableWidget->setSpan(index, 1, so2AbsorbSystem::xg + 1, 1);
    tableWidget->setSpan(index, 3, so2AbsorbSystem::xg + 1, 1);


    this->tableWidget->horizontalHeader()->setFont(font);
    this->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void window_total_equipment_parameter::judgePop()
{
    if (pinf::zengya == 0)
    {
        QRegExp rx("增压风机");
        int index = this->equipNameStringList.indexOf(rx);
        qDebug() << "indexof = " << index;
        this->equipNameStringList.removeAt(index);
        this->specificationStringList.removeAt(index);
        this->equipNumStringList.removeAt(index);
        this->columnheadStringList.removeAt(index);
    }
    if (pinf::huanre == 0)
    {
        QRegExp rx("烟气换热器");
        int index = this->equipNameStringList.indexOf(rx);
        qDebug() << "indexof = " << index;
        this->equipNameStringList.removeAt(index);
        this->specificationStringList.removeAt(index);
        this->equipNumStringList.removeAt(index);
        this->columnheadStringList.removeAt(index);
    }
    if (pinf::zhengong == 0)
    {
        QRegExp rx("真空皮带脱水机");
        int index = this->equipNameStringList.indexOf(rx);
        qDebug() << "indexof = " << index;
        for(int i=0; i<7; ++i)
        {
            this->equipNameStringList.removeAt(index);
            this->specificationStringList.removeAt(index);
            this->equipNumStringList.removeAt(index);
            this->columnheadStringList.removeAt(index);
        }
    }
    if (pinf::shuibeng == 0)
    {
        QRegExp rx("工艺水泵");
        int index = this->equipNameStringList.indexOf(rx);
        qDebug() << "indexof = " << index;
        this->equipNameStringList.removeAt(index);
        this->specificationStringList.removeAt(index);
        this->equipNumStringList.removeAt(index);
        this->columnheadStringList.removeAt(index);
    }


    if(pinf::feishui == 0)
    {
        QRegExp rx("废水旋流器");
        int index = this->equipNameStringList.indexOf(rx);
        qDebug() << "indexof = " << index;
        for(int i = 0; i <2; i++)
        {
            this->equipNameStringList.removeAt(index);
            this->specificationStringList.removeAt(index);
            this->equipNumStringList.removeAt(index);
            this->columnheadStringList.removeAt(index);
        }
    }

    if(pinf::shihui == 1)
    {
        QRegExp rx("湿式球磨机");
        int index = this->equipNameStringList.indexOf(rx);
        this->equipNameStringList[index - 1] = "石灰石粉仓";
        qDebug() << "indexof = " << index;
        for(int i = 0; i <5; i++)
        {
            this->equipNameStringList.removeAt(index);
            this->specificationStringList.removeAt(index);
            this->equipNumStringList.removeAt(index);
            this->columnheadStringList.removeAt(index);
        }
        this->columnheadStringList[index] = "2";
        this->columnheadStringList[index + 1] = "3";
        this->columnheadStringList[index + 2] = "4";
    }
}




void window_total_equipment_parameter::exportSLOT()
{
    myexcel = new QAxObject("Excel.Application");
    //false显示窗体（看具体过程）
    myexcel->dynamicCall("SetVisible(bool)", true);
    //显示警告信息
    myexcel->setProperty("DisplayAlerts", true);

    mywork = myexcel->querySubObject("WorkBooks");
    mywork->dynamicCall("Add");
    workbook = myexcel->querySubObject("ActiveWorkBook");
    mysheet = workbook->querySubObject("Sheets");


    mysheet->dynamicCall("Add");
    QAxObject *sheet = workbook->querySubObject("ActiveSheet");
    sheet->setProperty("Name", "设备参数汇总");

    QAxObject *cell;
    cell = sheet->querySubObject("Range(QVariant, QVariant)", "A1");
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("序号"));
    cell->querySubObject("Font")->setProperty("Bold", true);

    cell = sheet->querySubObject("Range(QVariant, QVariant)", "B1");
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("名称"));
    cell->querySubObject("Font")->setProperty("Bold", true);

    cell = sheet->querySubObject("Range(QVariant, QVariant)", "C1");
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("规格"));
    cell->querySubObject("Font")->setProperty("Bold", true);

    cell = sheet->querySubObject("Range(QVariant, QVariant)", "D1");
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("数量"));
    cell->querySubObject("Font")->setProperty("Bold", true);

    cell = sheet->querySubObject("Range(QVariant, QVariant)", "E1");
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("备注"));
    cell->querySubObject("Font")->setProperty("Bold", true);

    QString pos;
    for(int i = 0; i < this->columnheadStringList.size(); ++i)
    {
        pos = QString("A%1").arg(i + 2);
        cell = sheet->querySubObject("Range(QVariant, QVariant)", pos);
        cell->dynamicCall("SetValue(const QVariant&)", QVariant(this->columnheadStringList[i]));
        cell->querySubObject("Font")->setProperty("Bold", true);


        pos = QString("B%1").arg(i + 2);
        cell = sheet->querySubObject("Range(QVariant, QVariant)", pos);
        cell->dynamicCall("SetValue(const QVariant&)", QVariant(this->equipNameStringList[i]));
        cell->querySubObject("Font")->setProperty("Bold", true);


        pos = QString("C%1").arg(i + 2);
        cell = sheet->querySubObject("Range(QVariant, QVariant)", pos);
        cell->dynamicCall("SetValue(const QVariant&)", QVariant(this->specificationStringList[i]));
        cell->querySubObject("Font")->setProperty("Bold", true);

        pos = QString("D%1").arg(i + 2);
        cell = sheet->querySubObject("Range(QVariant, QVariant)", pos);
        cell->dynamicCall("SetValue(const QVariant&)", QVariant(this->equipNumStringList[i]));
        cell->setProperty("HorizontalAlignment", -4108);
        cell->querySubObject("Font")->setProperty("Bold", true);
    }
    QRegExp rx("浆液循环泵");
    int index = this->equipNameStringList.indexOf(rx);
    QString merge_cell;
    merge_cell = QString("A%1:A%2").arg(index + 2).arg(index + so2AbsorbSystem::xg + 2);
    cell = sheet->querySubObject("Range(const QString&)", merge_cell);
    cell->setProperty("MergeCells", true);
    cell->setProperty("WarpText", true);

    merge_cell = QString("B%1:B%2").arg(index + 2).arg(index + so2AbsorbSystem::xg + 2);
    cell = sheet->querySubObject("Range(const QString&)", merge_cell);
    cell->setProperty("MergeCells", true);
    cell->setProperty("WarpText", true);

    merge_cell = QString("D%1:D%2").arg(index + 2).arg(index + so2AbsorbSystem::xg + 2);
    cell = sheet->querySubObject("Range(const QString&)", merge_cell);
    cell->setProperty("MergeCells", true);
    cell->setProperty("WarpText", true);
    mysheet = workbook->querySubObject("Worksheets(int)",1);
    mysheet->querySubObject("UsedRange")->querySubObject("Columns")->dynamicCall("AutoFit");
    workbook->dynamicCall("Close()");
    myexcel->dynamicCall("Quit(void)");
    delete myexcel;

}

