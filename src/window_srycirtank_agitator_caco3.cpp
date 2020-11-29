#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_srycirtank_agitatorcaco3.h"

void caco3SryCirTankAndAgitatorWindow::okSLOT()
{
    bool ok1, ok2, ok3;
    bool ok4, ok5, ok6;
    float fgd = this->fgdNumLabel->text().toFloat(&ok4);
    float tsj = this->bufferTimeLineedit->text().toFloat(&ok5);
    float ysj = this->vevLineedit->text().toFloat(&ok6);

    float a = this->vevLineedit->text().toFloat(&ok1);
    float d = this->dLineedit->text().toFloat(&ok2);
    float h = this->hLineedit->text().toFloat(&ok3);
    if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6
            && a>=0 && a<=100 && d > 0 && h >0 && fgd > 0 && tsj > 0 && ysj > 0)
    {
        Qsj = gslResultPar::GSL[0][27][1];
        FGDnum = fgd;
        Tsj = tsj;
        Ysj = ysj / 100;
        slurryPreSystem::Vsj = Qsj * FGDnum * Tsj;
        slurryPreSystem::VTsj = slurryPreSystem::Vsj / Ysj;
        Dsj = d;
        Hsj = h;
        HDsj = Hsj / Dsj;


        VTjsj = ceil(3.1415 * (pow(Dsj / 2, 2)) * Hsj);
        Vjsj = Ysj * VTjsj;


        this->fgdNumLineedit->setText(QString("%1").arg(round(FGDnum)));
        this->bufferTimeLineedit->setText(QString("%1").arg(round(FGDnum * 1000) / 1000));
        this->singleFurnaceLineedit->setText(QString("%1").arg(round(FGDnum * 1000) / 1000));


        this->dLineedit->setText(QString("%1").arg(round(Dsj * 10) / 10));
        this->hLineedit->setText(QString("%1").arg(round(Hsj * 10) / 10));
        this->hdLineedit->setText(QString("%1").arg(round(HDsj * 10) / 10));
        this->veLineedit->setText(QString("%1").arg(round(Vjsj)));
        this->vLineedit->setText(QString("%1").arg(round(VTjsj)));
        this->vevLineedit->setText(QString("%1").arg(round(Ysj * 100)));


        Nbsj = emergencySlurrySystem::BGL(gslResultPar::GSL[0][27][16]) / 1000.0; // 比功率
        Nfsj = ceil(slurryPreSystem::Vjsj * Nbsj *10) / 10;    //轴功率
        Nesj = Nfsj * (1 + utils::YL(Nfsj)) / 0.98;                       //电机功率
        Nksj = utils::KD(Nesj);                                            //电机功率靠档


        this->rPowerLineedit->setText(QString("%1").arg(round(this->Nbsj * 1000) / 1000));
        this->shaftPowerLineedit->setText(QString("%1").arg(round(this->Nfsj * 10) / 10));
        this->motorPowerLineedit->setText(QString("%1").arg(round(this->Nesj * 10) / 10));
        utils::setKdComboBox(this->kdComBox, Nksj);
        QMessageBox::information(this, tr("信息"), tr("数据修改成功"));

    }
    else
        QMessageBox::warning(this, tr("错误"), tr("数据输入错误"));
}



