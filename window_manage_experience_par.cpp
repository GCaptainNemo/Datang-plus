#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_manage_experience_par.h"

int window_manage_experience_par::num = 0;


window_manage_experience_par::window_manage_experience_par(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint ;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("经验参数"));
    window_manage_experience_par::num += 1;



    layout = new QGridLayout(this);
    leakLabel = new QLabel(tr("回转式GGH泄露率(以原烟气为基准)% :"), this);
    leakLineedit = new QLineEdit(this);

    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));

    layout->addWidget(leakLabel, 0, 0, 1, 3);
    layout->addWidget(leakLineedit, 0, 3, 1, 3);
    this->initWidget1();
    this->initWidget2();
    this->initWidget3();
    layout->addWidget(widget1, 1, 0, 4, 6);
    layout->addWidget(widget2, 5, 0, 5, 6);
    layout->addWidget(widget3, 10, 0, 6, 6);
    layout->addWidget(buttonWidget, 16, 0, 1, 6);
    this->initParameter();
    this->showNormal();
}


void window_manage_experience_par::okSLOT()
{
    experiencePar::GGHx = this->leakLineedit->text().toFloat() / 100;
    experiencePar::so3x=  this->gghSO3Lineedit->text().toFloat() / 100 ;
    experiencePar::hfx = this->gghHFLineedit->text().toFloat() / 100;
    experiencePar::ashx = this->gghDustLineedit->text().toFloat() / 100;
    experiencePar::so3y = this->absorberSO3Lineedit->text().toFloat() / 100;
    experiencePar::hcly = this->absorberHCLlineedit->text().toFloat() / 100;
    experiencePar::hfy = this->absorberHFlineedit->text().toFloat() / 100;
    experiencePar::ashy = this->absorberDustLineedit->text().toFloat() / 100;
    experiencePar::VCas = this->casLineedit->text().toFloat();
    experiencePar::CaSO3CaSO42H20 = this->caso4Lineedit->text().toFloat() / 100;
    experiencePar::YMgCO3 = this->mgco3Lineedit->text().toFloat() / 100;
    experiencePar::Yh2o = this->proH2Olineedit->text().toFloat();
    experiencePar::LSF = this->circulantSryLineedit->text().toFloat();
    experiencePar::YSx = this->stressLineedit->text().toFloat();

    query->exec(QString("UPDATE Experience SET ex1='%1', ex2='%2', ex3='%3', ex4='%4', ex5='%5', "
                        "ex6='%6', ex7='%7', ex8='%8', ex9='%9', ex10='%10', ex11='%11', "
                        "ex12='%12', ex13='%13', ex14='%14'").arg(experiencePar::GGHx).
                arg(experiencePar::so3x).arg(experiencePar::hfx).arg(experiencePar::ashx).arg(experiencePar::so3y).
                arg(experiencePar::hcly).arg(experiencePar::hfy).arg(experiencePar::ashy).arg(experiencePar::VCas).
                arg(experiencePar::CaSO3CaSO42H20).arg(experiencePar::YMgCO3).arg(experiencePar::Yh2o).
                arg(experiencePar::LSF).arg(experiencePar::YSx));

    QMessageBox::information(this, tr("更改结果"), tr("经验参数更改成功！"));

    this->close();


}

void window_manage_experience_par::initParameter()
{
    qDebug() << "in initParameter()";

    if (utils::ping(otherPar::ip)==0)
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
            QMessageBox::warning(this, tr("连接结果"), tr("数据库连接失败"));
        }
        else
        {
//            QString oldpw = this->initPasswordLineedit->text();

            this->query = new QSqlQuery(this->db);
            this->query->exec("SELECT TOP 1 * FROM Experience ORDER BY Eid DESC");
            if (query->next()){
                experiencePar * par = new experiencePar(query);
                qDebug() << "epar = " << experiencePar::GGHx;
                delete par;
                leakLineedit->setText(QString("%1").arg(experiencePar::GGHx * 100));
                gghSO3Lineedit->setText(QString("%1").arg(experiencePar::so3x * 100));
                gghHFLineedit->setText(QString("%1").arg(experiencePar::hfx * 100));
                gghDustLineedit->setText(QString("%1").arg(experiencePar::ashx * 100));

                absorberSO3Lineedit->setText(QString("%1").arg(experiencePar::so3y * 100));
                absorberHCLlineedit->setText(QString("%1").arg(experiencePar::hcly * 100));
                absorberHFlineedit->setText(QString("%1").arg(experiencePar::hfy * 100));
                absorberDustLineedit->setText(QString("%1").arg(experiencePar::ashy * 100));


                casLineedit->setText(QString("%1").arg(experiencePar::VCas));
                caso4Lineedit->setText(QString("%1").arg(experiencePar::CaSO3CaSO42H20 * 100));
                mgco3Lineedit->setText(QString("%1").arg(experiencePar::YMgCO3 * 100));
                proH2Olineedit->setText(QString("%1").arg(experiencePar::Yh2o));
                circulantSryLineedit->setText(QString("%1").arg(experiencePar::LSF));
                stressLineedit->setText(QString("%1").arg(experiencePar::YSx));
            }
        }
    }
    else
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
}

void window_manage_experience_par::initWidget1()
{
    widget1 = new QWidget(this);
    layout1 = new QGridLayout(widget1);
    gghLabel = new QLabel(tr("GGH中脱硫率"), this);
    gghSO3Label = new QLabel(tr("SO3(%)"), this);
    gghHFLabel = new QLabel(tr("HF(%)"), this);
    gghDustLabel = new QLabel(tr("灰(%)"), this);
    gghSO3Lineedit = new QLineEdit(this);
    gghHFLineedit = new QLineEdit(this);
    gghDustLineedit = new QLineEdit(this);
    layout1->addWidget(gghLabel, 0, 0, 1, 6);
    layout1->addWidget(gghSO3Label, 1, 0, 1, 3);
    layout1->addWidget(gghSO3Lineedit, 1, 3, 1, 3);

    layout1->addWidget(gghHFLabel, 2, 0, 1, 3);
    layout1->addWidget(gghHFLineedit, 2, 3, 1, 3);

    layout1->addWidget(gghDustLabel, 3, 0, 1, 3);
    layout1->addWidget(gghDustLineedit, 3, 3, 1, 3);

}

void window_manage_experience_par::initWidget2()
{
    widget2 = new QWidget(this);
    layout2 = new QGridLayout(widget2);
    absorberLabel = new QLabel(tr("吸收塔内各组分按下列吸收率吸收"), this);
    absorberSO3Label = new QLabel(tr("SO3(%):"), this);
    absorberHCLlabel = new QLabel(tr("HCl(%):"), this);
    absorberHFlabel = new QLabel(tr("HF(%):"), this);
    absorberDustLabel = new QLabel(tr("灰(%):"), this);

    absorberSO3Lineedit = new QLineEdit(this);
    absorberHCLlineedit = new QLineEdit(this);
    absorberHFlineedit = new QLineEdit(this);
    absorberDustLineedit = new QLineEdit(this);
    layout2->addWidget(this->absorberLabel, 0, 0, 1, 6);
    layout2->addWidget(absorberSO3Label, 1, 0, 1, 3);
    layout2->addWidget(absorberSO3Lineedit, 1, 3, 1, 3);
    layout2->addWidget(absorberHCLlabel, 2, 0, 1, 3);
    layout2->addWidget(absorberHCLlineedit, 2, 3, 1, 3);
    layout2->addWidget(absorberHFlabel, 3, 0, 1, 3);
    layout2->addWidget(absorberHFlineedit, 3, 3, 1, 3);
    layout2->addWidget(absorberDustLabel, 4, 0, 1, 3);
    layout2->addWidget(absorberDustLineedit, 4, 3, 1, 3);



}

void window_manage_experience_par::initWidget3()
{
    widget3 = new QWidget(this);
    layout3 = new QGridLayout(widget3);
    casLabel = new QLabel(tr("Ca/S"), this);
    caso4Label = new QLabel(tr("为防止石膏结垢，采用mol(CaSO3/CaSO4.2H2O):"), this);
    mgco3Label = new QLabel(tr("石灰石中可以反应的MgCO3设置为:"), this);
    proH2Olabel = new QLabel(tr("工艺水中溶解物的含量(kg/kgH2O):"), this);
    circulantSryLabel = new QLabel(tr("循环浆液安全系数:"), this);
    stressLabel = new QLabel(tr("压损修正系数:"), this);

    casLineedit = new QLineEdit(this);
    caso4Lineedit = new QLineEdit(this);
    mgco3Lineedit = new QLineEdit(this);
    proH2Olineedit = new QLineEdit(this);
    circulantSryLineedit = new QLineEdit(this);
    stressLineedit = new QLineEdit(this);


    layout3->addWidget(casLabel, 0, 0, 1, 3);
    layout3->addWidget(casLineedit, 0, 3, 1, 3);
    layout3->addWidget(caso4Label, 1, 0, 1, 3);
    layout3->addWidget(caso4Lineedit, 1, 3, 1, 3);
    layout3->addWidget(mgco3Label, 2, 0, 1, 3);
    layout3->addWidget(mgco3Lineedit, 2, 3, 1, 3);

    layout3->addWidget(proH2Olabel, 3, 0, 1, 3);
    layout3->addWidget(proH2Olineedit, 3, 3, 1, 3);

    layout3->addWidget(circulantSryLabel, 4, 0, 1, 3);
    layout3->addWidget(circulantSryLineedit, 4, 3, 1, 3);
    layout3->addWidget(stressLabel, 5, 0, 1, 3);
    layout3->addWidget(stressLineedit, 5, 3, 1, 3);


}


window_manage_experience_par::~window_manage_experience_par()
{
    window_manage_experience_par::num -= 1;
    delete query;

}

