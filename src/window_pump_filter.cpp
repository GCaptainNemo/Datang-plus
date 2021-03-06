﻿#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_pump_filter.h"


void filterPumpWindow::okSLOT()
{
    bool ok;
    float a = this->efficiencyLineedt->text().toFloat(&ok);
    if (ok && a>=0 && a<=100)
    {

        yshpb = a / 100;
        qshpb = gslResultPar::GSL[0][15][1] * 1.1;
        hshpb = 35;
        nfshpb = qshpb * hshpb * gslResultPar::GSL[0][15][15] * 9.81 / 1000 / 3600 / yshpb;
        nfshpb = ceil(nfshpb * 10) / 10; // 向上取整
        neshpb = nfshpb * (1 + utils::YL(nfshpb)); // 余量计算
        nkshpb = utils::KD(neshpb);    // 靠档

        this->flowLineedt->setText(QString("%1").arg(round(qshpb * 10) / 10.0));
        this->liftLineedt->setText(QString("%1").arg(round(hshpb)));
        this-> shaftPowerLineedt->setText(QString("%1").arg(round(nfshpb * 10) / 10.0));
        this->motorPowerLineedt->setText(QString("%1").arg(round(neshpb * 10) / 10.0));
        utils::setKdComboBox(this->kdComboBox, nkshpb);
        QMessageBox::information(this, tr("信息"), tr("数据修改成功"));

    }
    else
        QMessageBox::warning(this, tr("错误"), tr("数据输入错误"));

}

