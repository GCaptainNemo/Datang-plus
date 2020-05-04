#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_project_save.h"

saveObject::saveObject(QObject *parent) : QObject(parent)
{

    this->sqlVerifyPj = "SELECT * FROM projects WHERE PRID=" + otherPar::prid;
    this->sqlSaveCoal = QString("UPDATE COAL SET xishu = %1, mei=%2, shui=%3, "
                        "hui=%4, liu=%5, qing=%6, tan=%7, dan=%8, "
                                "yang=%9 WHERE prid=%10" ).arg(Coal::Ap).arg(Coal::bj).arg(Coal::W).arg(
                         Coal::A).arg(Coal::S).arg(Coal::H).arg(Coal::C).arg(Coal::N).arg(Coal::O).arg(otherPar::prid);


    qDebug() << "sqlVerifyPj = " << this->sqlVerifyPj;
    qDebug() << "sqlSaveCoal = " << this->sqlSaveCoal;
//    this->start();
}

void saveObject::start()
{
    qDebug() << "SavePj work thread id = " << QThread::currentThreadId();
    if (otherPar::prid.toStdString() == "")
    {
        qDebug() << "没有该项目";
        //        没有该项目

        emit messageboxShowSIGNAL(0);
    }
    else if (utils::ping(otherPar::ip)==0)
    {
        if (QSqlDatabase::contains("SQLserver"))
            this->db = QSqlDatabase::database("SQLserver");
        else{
            this->db = QSqlDatabase::addDatabase("QODBC", "SQLserver");   //数据库驱动类型为SQL Server
            QString dsn = "DRIVER={SQL SERVER};SERVER=" + otherPar::ip + ";DATABASE=p;"
                    "UID=sa;PWD=123456;";
            db.setDatabaseName(dsn);
        }

        if(!db.open())                                      //打开数据库
        {
            qDebug() << "数据库连接失败";
            emit messageboxShowSIGNAL(1);
        }
        else
        {
            qDebug() << "in";
            this->query = new QSqlQuery(this->db);
            this->query->exec(this->sqlVerifyPj);
            if (query->next()){
                std::string prstate = query->value(2).toString().toStdString();
                if (prstate == "提交校审" || prstate == "校核通过" || prstate == "审核通过"){
                    qDebug() << "项目只读";
                    emit messageboxShowSIGNAL(2);
                }
                else
                {
                    this->commandSave();
                }
            }
        }
    }
    else{
         emit messageboxShowSIGNAL(3);
    }
}


void saveObject::commandSave()
{


    //    Save pinf


    this->query->exec(this->sqlSaveCoal);
    QStringList lst1;
    lst1 << QString("%1").arg(inputParameterWindow::bz1) << QString("%1").arg(inputParameterWindow::bz2);
    for (int i=0;i<=22;i++)
        lst1.append(QString("%1").arg(gasResultPar::Gas[0][0][i]));
    lst1 << QString("%1").arg(pinf::VCaCO3) << QString("%1").arg(pinf::VMgCO3) << QString("%1").arg(pinf::Vother);
    lst1 << QString("%1").arg(gslResultPar::GSL[0][19][14]) << QString("%1").arg(pinf::yS) << QString("%1").arg(gslResultPar::GSL[0][11][14]) <<
                                                                                                QString("%1").arg(gslResultPar::GSL[0][5][16]);
    lst1 << QString("%1").arg(pinf::zysh) << QString("%1").arg(gasResultPar::Gas[0][4][22]) << QString("%1").arg(pinf::Pcaco3);
    lst1 << QString("%1").arg(pinf::PP1) << QString("%1").arg(pinf::PP2)<< QString("%1").arg(pinf::PP3)<< QString("%1").arg(pinf::PP4)<<
           QString("%1").arg(pinf::PP5)<< QString("%1").arg(pinf::PP6);

    lst1 <<QString("%1").arg(pinf::PP7)<< QString("%1").arg(pinf::PP8)<< QString("%1").arg(pinf::PP9)<<
          QString("%1").arg(pinf::PP10)<< QString("%1").arg(pinf::PP11) << QString("%1").arg(pinf::PP12);
    QString res = lst1.join("*");
    qDebug() << "res = " << res;
    this->sqlSavePinf = QString("UPDATE Pinf SET Pinput = %1, Pequip=%2, Eid=%3 "
                                "WHERE prid =").arg(res).arg(QString::fromStdString(pinf::ss)).arg(pinf::Expid).arg(otherPar::prid);
    this->query->exec(this->sqlSavePinf);



    //    Gas表



    lst1.clear();
    for(int i=0;i<=7;i++){
        for(int j=0;j<=22;j++){
            lst1 << QString("%1").arg(gasResultPar::Gas[0][i][j]);
        }
    }
    res = lst1.join("*");
    this->sqlSaveGas = QString("UPDATE GasResult set Gas1 = %1, WHERE prid = %2").arg(res, otherPar::prid);
    this->query->exec(this->sqlSaveGas);


    //    GSL表


    lst1.clear();
    for(int i = 0; i <= 29; i++){
        for(int j = 0; j <= 17; j++){
            lst1 << QString("%1").arg(gslResultPar::GSL[0][i][j]);
        }
    }
    res = lst1.join("*");
    this->sqlSaveGSL = QString("UPDATE GSLResult set GSL1 = %1, WHERE prid = %2").arg(res, otherPar::prid);
    this->query->exec(this->sqlSaveGSL);


    // Equip

    lst1.clear();

    //    1. 吸收塔

    lst1 << QString("%1").arg(absorberSystem::FGDnum);     //吸收塔数量
    lst1 << QString("%1").arg(absorberSystem::vin);        //入口烟气流速 目标
    lst1 << QString("%1").arg(absorberSystem::vout);       //出口烟气流速  目标
    lst1 << QString("%1").arg(absorberSystem::u );        //烟气流速 目标
    lst1 << QString("%1").arg(absorberSystem::bc ); //入口顶到第一层喷淋层
    lst1 << QString("%1").arg(absorberSystem::cd ); //烟气进口底部之浆液面
    lst1 << QString("%1").arg(absorberSystem::D ); //最上层喷淋层到至第一级除雾器高度差
    lst1 << QString("%1").arg(absorberSystem::pc ); //喷淋层数量
    lst1 << QString("%1").arg(absorberSystem::E ); //喷淋层间距
    lst1 << QString("%1").arg(absorberSystem::g ); //除雾器高度
    lst1 << QString("%1").arg(absorberSystem::k ); //除雾器距顶部烟气出口
    lst1 << QString("%1").arg(absorberSystem::hx); //烟道宽度 %
    lst1 << QString("%1").arg(absorberSystem::NUMjb); //个数
    lst1 << QString("%1").arg(absorberSystem::V); //浆池容量

    QString res1 = lst1.join("*");

    //    烟气系统-- 2. 增压风机

    QStringList lst2;

    lst2 << QString("%1").arg(flueGasSystem::Yfan) ; //效率
    lst2 << QString("%1").arg( flueGasSystem::Qfan ); //BMCR流量
    lst2 << QString("%1").arg( flueGasSystem::Qfand); //TB流量
    lst2 << QString("%1").arg( flueGasSystem::Pfan ); //BMCR压升
    lst2 << QString("%1").arg( flueGasSystem::Pfand); //TB压升
    lst2 << QString("%1").arg( flueGasSystem::Nffan); //BMCR轴功率
    lst2 << QString("%1").arg( flueGasSystem::Ndfan); //TB轴功率
    lst2 << QString("%1").arg( flueGasSystem::Nefan); //电机功率
    lst2 << QString("%1").arg( flueGasSystem::Nkfan) ; //电机功率靠档
    QString res2 = lst2.join("*");


    //    烟气系统-- 3. 换热器



    QStringList lst3;
    lst3 << QString("%1").arg(gasResultPar::Gas[0][1][22]) ;
    lst3 << QString("%1").arg(gasResultPar::Gas[0][3][22]);
    lst3 << "80";
    lst3 << QString("%1").arg(gasResultPar::Gas[0][1][4]);
    QString res3 = lst3.join("*");


    // SO2吸收系统 - 4. 氧化风机

    QStringList lst4;
    lst4 << QString("%1").arg( so2AbsorbSystem::Yyang); //效率
    lst4 << QString("%1").arg(  so2AbsorbSystem::Qyang); //湿基标态流量
    lst4 << QString("%1").arg(  so2AbsorbSystem::QXyang ); //风机选型流量
    lst4 << QString("%1").arg(  so2AbsorbSystem::Pyang ); //压升
    lst4 << QString("%1").arg(  so2AbsorbSystem::Nfyang ); //轴功率
    lst4 << QString("%1").arg(  so2AbsorbSystem::Neyang); //电机功率
    lst4 << QString("%1").arg(  so2AbsorbSystem::Nkyang); //电机功率靠档
    QString res4 = lst4.join("*");




    // SO2吸收系统 - 5. 浆液循环泵


    QStringList lst5;

    lst5 << QString("%1").arg(so2AbsorbSystem::Yjxb); //效率
    lst5 << QString("%1").arg(so2AbsorbSystem::Qjxb); //流量
    lst5 << QString("%1").arg(so2AbsorbSystem::xg); //循环泵数量

    lst5 << QString("%1").arg(so2AbsorbSystem::Hjxb[0]);
    lst5 << QString("%1").arg(so2AbsorbSystem::Nfjxb[0]); //轴功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nejxb[0]); //电机功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nkjxb[0]); //电机功率靠档
    lst5 << QString("%1").arg(so2AbsorbSystem::Hjxb[1]);
    lst5 << QString("%1").arg(so2AbsorbSystem::Nfjxb[1]); //轴功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nejxb[1]); //电机功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nkjxb[1]); //电机功率靠档
    lst5 << QString("%1").arg(so2AbsorbSystem::Hjxb[2]);
    lst5 << QString("%1").arg(so2AbsorbSystem::Nfjxb[2]); //轴功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nejxb[2]); //电机功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nkjxb[2]); //电机功率靠档
    lst5 << QString("%1").arg(so2AbsorbSystem::Hjxb[3]);
    lst5 << QString("%1").arg(so2AbsorbSystem::Nfjxb[3]); //轴功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nejxb[3]); //电机功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nkjxb[3]); //电机功率靠档
    lst5 << QString("%1").arg(so2AbsorbSystem::Hjxb[4]);
    lst5 << QString("%1").arg(so2AbsorbSystem::Nfjxb[4]); //轴功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nejxb[4]); //电机功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nkjxb[4]); //电机功率靠档
    lst5 << QString("%1").arg(so2AbsorbSystem::Hjxb[5]); //扬程
    lst5 << QString("%1").arg(so2AbsorbSystem::Nfjxb[5]); //轴功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nejxb[5]); //电机功率
    lst5 << QString("%1").arg(so2AbsorbSystem::Nkjxb[5]); //电机功率靠档

    QString res5 = lst5.join("*");

    //    6. 吸收塔搅拌器功率


    QStringList lst6;

    lst6 << QString("%1").arg(so2AbsorbSystem::Nbxsh);
    lst6 << QString("%1").arg(so2AbsorbSystem::Nfxsh);
    lst6 << QString("%1").arg(so2AbsorbSystem::Nexsh);
    lst6 << QString("%1").arg(so2AbsorbSystem::Nkxsh);

    QString res6 = lst6.join("*");


    // 7. 石膏排出泵


    QStringList lst7;


    lst7 << QString("%1").arg(so2AbsorbSystem::Yshpb);
    lst7 << QString("%1").arg(so2AbsorbSystem::Qshpb);
    lst7 << QString("%1").arg(so2AbsorbSystem::Hshpb);
    lst7 << QString("%1").arg(so2AbsorbSystem::Nfshpb);
    lst7 << QString("%1").arg(so2AbsorbSystem::Neshpb);
    lst7 << QString("%1").arg(so2AbsorbSystem::Nkshpb);

    QString res7 = lst7.join("*");


    // 8. 石膏旋流器


    QStringList lst8;

    lst8  << QString("%1").arg(caso4ExtractH2Osystem::Qshgx);
    lst8 << QString("%1").arg(caso4ExtractH2Osystem::XZshgx);

    QString res8 = lst8.join("*");

    // 9. 真空皮带脱水机


    QStringList lst9;

    lst9  << QString("%1").arg(caso4ExtractH2Osystem::Qzhk);
    lst9 << QString("%1").arg(caso4ExtractH2Osystem::Szhk);
    lst9 << QString("%1").arg(caso4ExtractH2Osystem::Nezhk);

    QString res9 = lst9.join("*");


    // 10. 真空泵


    QStringList lst10;

    lst10 << QString("%1").arg(caso4ExtractH2Osystem::Qzhb);
    lst10 << QString("%1").arg(caso4ExtractH2Osystem::Nfzhb);
    lst10 << QString("%1").arg(caso4ExtractH2Osystem::Nezhb);

    QString res10 = lst10.join("*");


    // 11. 滤布冲洗水箱


    QStringList lst11;

    lst11 << QString("%1").arg(caso4ExtractH2Osystem::Dlb);
    lst11 << QString("%1").arg(caso4ExtractH2Osystem::Hlb);
    lst11 << QString("%1").arg(caso4ExtractH2Osystem::Vjlb);

    QString res11 = lst11.join("*");


    // 12. 滤布冲洗水泵

    QStringList lst12;

    lst12 << QString("%1").arg(caso4ExtractH2Osystem::Qlbb);
    lst12 << QString("%1").arg(caso4ExtractH2Osystem::Hlbb);
    lst12 << QString("%1").arg(caso4ExtractH2Osystem::Nelbb);

    QString res12 = lst12.join("*");



    // 13. 滤液箱

    QStringList lst13;

    lst13 << QString("%1").arg(caso4ExtractH2Osystem::Qlx);
    lst13 << QString("%1").arg(caso4ExtractH2Osystem::Tlx);
    lst13 << QString("%1").arg(caso4ExtractH2Osystem::Dlx);
    lst13 << QString("%1").arg(caso4ExtractH2Osystem::Hlx);
    lst13 << QString("%1").arg(caso4ExtractH2Osystem::HDlx);
    lst13 << QString("%1").arg(caso4ExtractH2Osystem::VTjlx);
    lst13 << QString("%1").arg(caso4ExtractH2Osystem::Vjlx);
    lst13 << QString("%1").arg(caso4ExtractH2Osystem::Ylx);

    QString res13 = lst13.join("*");


    // 14. 滤液箱搅拌器

    QStringList lst14;

    lst14 << QString("%1").arg(caso4ExtractH2Osystem::Nblx);
    lst14 << QString("%1").arg(caso4ExtractH2Osystem::Nflx);
    lst14 << QString("%1").arg(caso4ExtractH2Osystem::Nelx);
    lst14 << QString("%1").arg(caso4ExtractH2Osystem::Nklx);

    QString res14 = lst14.join("*");


    // 15. 滤液泵

    QStringList lst15;

    lst15 << QString("%1").arg(caso4ExtractH2Osystem::Ylyb);
    lst15 << QString("%1").arg(caso4ExtractH2Osystem::Qlyb);
    lst15 << QString("%1").arg(caso4ExtractH2Osystem::Hlyb);
    lst15 << QString("%1").arg(caso4ExtractH2Osystem::Nflyb);
    lst15 << QString("%1").arg(caso4ExtractH2Osystem::Nelyb);
    lst15 << QString("%1").arg(caso4ExtractH2Osystem::Nklyb);

    QString res15 = lst15.join("*");


    // 16. 石灰石仓

    QStringList lst16;

    lst16 << QString("%1").arg(slurryPreSystem::Qshc);
    lst16 << QString("%1").arg(slurryPreSystem::Tshc);
    lst16 << QString("%1").arg(slurryPreSystem::NUMshc);
    lst16 << QString::fromStdString(slurryPreSystem::CXshc);
    lst16 << QString::fromStdString(slurryPreSystem::ZXshc);
    lst16 << QString("%1").arg(slurryPreSystem::Dshc);
    lst16 << QString("%1").arg(slurryPreSystem::Ashc);
    lst16 << QString("%1").arg(slurryPreSystem::H1shc);
    lst16 << QString("%1").arg(slurryPreSystem::H2shc);
    lst16 << QString("%1").arg(slurryPreSystem::VTjshc);
    lst16 << QString("%1").arg(slurryPreSystem::Vjshc);
    lst16 << QString("%1").arg(slurryPreSystem::Yshc);

    QString res16 = lst16.join("*");


    // 17. 磨机

    QStringList lst17;

    lst17 << QString("%1").arg(slurryPreSystem::Qmj);
    lst17 << QString("%1").arg(slurryPreSystem::Nfmj);
    lst17 << QString("%1").arg(slurryPreSystem::Nemj);

    QString res17 = lst17.join("*");


    // 18. 石灰石浆液循环器

    QStringList lst18;

    lst18 << QString("%1").arg(slurryPreSystem::Qsjx);
    lst18 << QString("%1").arg(slurryPreSystem::Tsjx);
    lst18 << QString("%1").arg(slurryPreSystem::Dsjx);

    lst18 << QString("%1").arg(slurryPreSystem::Hsjx);
    lst18 << QString("%1").arg(slurryPreSystem::HDsjx);
    lst18 << QString("%1").arg(slurryPreSystem::VTjsjx);

    lst18 << QString("%1").arg(slurryPreSystem::Vjsjx);
    lst18 << QString("%1").arg(slurryPreSystem::VTsjx);
    lst18 << QString("%1").arg(slurryPreSystem::Ysjx);

    QString res18 = lst18.join("*");



    // 19. 石灰石浆液循环箱搅拌器

    QStringList lst19;

    lst19 << QString("%1").arg(slurryPreSystem::Nbsjx);
    lst19 << QString("%1").arg(slurryPreSystem::Nfsjx);
    lst19 << QString("%1").arg(slurryPreSystem::Nesjx);
    lst19 << QString("%1").arg(slurryPreSystem::Nksjx);


    QString res19 = lst19.join("*");


    // 20. 石灰石浆液循环泵

    QStringList lst20;

    lst20 << QString("%1").arg(slurryPreSystem::Yshjxb);
    lst20 << QString("%1").arg(slurryPreSystem::Qshjxb);
    lst20 << QString("%1").arg(slurryPreSystem::Hshjxb);
    lst20 << QString("%1").arg(slurryPreSystem::Nfshjxb);
    lst20 << QString("%1").arg(slurryPreSystem::Nkshjxb);


    QString res20 = lst20.join("*");


    // 21. 石灰石旋流器

    QStringList lst21;

    lst21 << QString("%1").arg(slurryPreSystem::Qshhx);
    lst21 << QString("%1").arg(slurryPreSystem::XZshhx);

    QString res21 = lst21.join("*");

    // 22. 石灰石浆液箱

    QStringList lst22;

    lst22 << QString("%1").arg(slurryPreSystem::Qsj);
    lst22 << QString("%1").arg(slurryPreSystem::Tsj);
    lst22 << QString("%1").arg(slurryPreSystem::Dsj);
    lst22 << QString("%1").arg(slurryPreSystem::Hsj);
    lst22 << QString("%1").arg(slurryPreSystem::HDsj);
    lst22 << QString("%1").arg(slurryPreSystem::VTjsj);
    lst22 << QString("%1").arg(slurryPreSystem::Vjsj);
    lst22 << QString("%1").arg(slurryPreSystem::Ysj);

    QString res22 = lst22.join("*");


    // 23. 石灰石浆液循环器

    QStringList lst23;

    lst23 << QString("%1").arg(slurryPreSystem::Nbsj);
    lst23 << QString("%1").arg(slurryPreSystem::Nesj);
    lst23 << QString("%1").arg(slurryPreSystem::Nfsj);
    lst23 << QString("%1").arg(slurryPreSystem::Nksj);

    QString res23 = lst23.join("*");


    // 24. 石灰石浆液循环器

    QStringList lst24;

    lst24 << QString("%1").arg(slurryPreSystem::Yshjb);
    lst24 << QString("%1").arg(slurryPreSystem::Qshjb);
    lst24 << QString("%1").arg(slurryPreSystem::Hshjb);
    lst24 << QString("%1").arg(slurryPreSystem::Nfshjb);
    lst24 << QString("%1").arg(slurryPreSystem::Neshjb);
    lst24 << QString("%1").arg(slurryPreSystem::Nkshjb);

    QString res24 = lst24.join("*");


    // 25. 工艺水箱

    QStringList lst25;

    lst25 << QString("%1").arg(processH2Osystem::Qgy);
    lst25 << QString("%1").arg(processH2Osystem::Tgy);
    lst25 << QString("%1").arg(processH2Osystem::Dgy);
    lst25 << QString("%1").arg(processH2Osystem::Hgy);
    lst25 << QString("%1").arg(processH2Osystem::HDgy);
    lst25 << QString("%1").arg(processH2Osystem::VTjgy);
    lst25 << QString("%1").arg(processH2Osystem::Vjgy);
    lst25 << QString("%1").arg(processH2Osystem::VTgy);
    lst25 << QString("%1").arg(processH2Osystem::Ygy);

    QString res25 = lst25.join("*");


    // 26. 工艺水泵


    QStringList lst26;

    lst26 << QString("%1").arg(processH2Osystem::Ygyb);
    lst26 << QString("%1").arg(processH2Osystem::Qgyb);
    lst26 << QString("%1").arg(processH2Osystem::Hgyb);
    lst26 << QString("%1").arg(processH2Osystem::Nfgyb);
    lst26 << QString("%1").arg(processH2Osystem::Negyb);
    lst26 << QString("%1").arg(processH2Osystem::Nkgyb);

    QString res26 = lst26.join("*");


    // 27. 除雾器冲洗水泵


    QStringList lst27;

    lst27 << QString("%1").arg(processH2Osystem::Yccb);
    lst27 << QString("%1").arg(processH2Osystem::Qccb);
    lst27 << QString("%1").arg(processH2Osystem::Hccb);
    lst27 << QString("%1").arg(processH2Osystem::Nfccb);
    lst27 << QString("%1").arg(processH2Osystem::Neccb);
    lst27 << QString("%1").arg(processH2Osystem::Nkccb);

    QString res27 = lst27.join("*");


    // 28. 事故浆液箱


    QStringList lst28;

    lst28 << QString("%1").arg(emergencySlurrySystem::Dshg);
    lst28 << QString("%1").arg(emergencySlurrySystem::Hshg);
    lst28 << QString("%1").arg(emergencySlurrySystem::HDshg);
    lst28 << QString("%1").arg(emergencySlurrySystem::VTshg);
    lst28 << QString("%1").arg(emergencySlurrySystem::Vshg);
    lst28 << QString("%1").arg(emergencySlurrySystem::Yshg);

    QString res28 = lst28.join("*");


    // 29. 事故浆液箱搅拌器


    QStringList lst29;

    lst29 << QString("%1").arg(emergencySlurrySystem::Nbshg);
    lst29 << QString("%1").arg(emergencySlurrySystem::Nfshg);
    lst29 << QString("%1").arg(emergencySlurrySystem::Neshg);
    lst29 << QString("%1").arg(emergencySlurrySystem::Nkshg);

    QString res29 = lst29.join("*");


    // 30. 事故浆液箱泵


    QStringList lst30;

    lst30 << QString("%1").arg(emergencySlurrySystem::Yshgb);
    lst30 << QString("%1").arg(emergencySlurrySystem::Qshgb);
    lst30 << QString("%1").arg(emergencySlurrySystem::Hshgb);
    lst30 << QString("%1").arg(emergencySlurrySystem::Nfshgb);
    lst30 << QString("%1").arg(emergencySlurrySystem::Neshgb);
    lst30 << QString("%1").arg(emergencySlurrySystem::Nkshgb);

    QString res30 = lst30.join("*");


    // 31. 废水泵


    QStringList lst31;

    lst31 << QString("%1").arg(wasteH2OproSystem::Yfshb);
    lst31 << QString("%1").arg(wasteH2OproSystem::Qfshb);
    lst31 << QString("%1").arg(wasteH2OproSystem::Hfshb);
    lst31 << QString("%1").arg(wasteH2OproSystem::Nffshb);
    lst31 << QString("%1").arg(wasteH2OproSystem::Nefshb);
    lst31 << QString("%1").arg(wasteH2OproSystem::Nkfshb);

    QString res31 = lst31.join("*");


    // 32. 废水旋流器


    QStringList lst32;

    lst32 << QString("%1").arg(wasteH2OproSystem::Qfx);
    lst32 << QString("%1").arg(wasteH2OproSystem::XZfx);

    QString res32 = lst32.join("*");

    sqlSaveEquip = QString("UPDATE Equip SET eq1 = %1, eq2 = %2,eq3 = %3, eq4 = %4,eq5 = %5, eq6 = %6,"
                           "eq7 = %7, eq8 = %8,eq9 = %9, eq10 = %10,eq11 = %11, eq12 = %12,eq13 = %13, "
                           "eq14 = %14,eq15 = %15, eq16 = %16,eq17 = %17, eq18 = %18,eq19 = %19, "
                           "eq20 = %20,eq21 = %21, eq22 = %22,eq23 = %23, eq24 = %24,eq25 = %25, eq26 = %26,"
                           "eq27 = %27, eq28 = %28,eq29 = %29, eq30 = %30,eq31 = %31, eq32 = %32").arg(res1).
            arg(res2).arg(res3).arg(res4).arg(res5).arg(res6).arg(res7).arg(res8).arg(res9).arg(res10).arg(res11).
            arg(res12).arg(res13).arg(res14).arg(res15).arg(res16).arg(res17).arg(res18).arg(res19).arg(res20).
            arg(res21).arg(res22).arg(res23).arg(res24).arg(res25).arg(res26).arg(res27).arg(res28).
            arg(res29).arg(res30).arg(res31).arg(res32);
    query->exec(sqlSaveEquip);


    //    打开记录表

    QString ipv4 = utils::getIPV4address();
    QDateTime curDateTime = QDateTime::currentDateTime();
    QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QString sqlMax = "SELECT MAX(recid) FROM records";
    query->exec(sqlMax);
    query->next();
    int recid = query->value(0).toInt() + 1;
    sqlInsertRecord = QString ("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '保存项目%5')").arg(recid).
            arg(otherPar::userid).arg(ipv4).arg(date).arg(otherPar::prid);
    query->exec(sqlInsertRecord);

    emit messageboxShowSIGNAL(4);

    delete query;
}




