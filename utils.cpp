# include "utils.h"




int myCalender::calenderNum = 0;

myCalender::myCalender(QWidget *parent):QCalendarWidget(parent){
    myCalender::calenderNum += 1;
    this->setWindowTitle(tr("日历"));
    this->showNormal();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

myCalender::~myCalender()
{
    myCalender::calenderNum -= 1;
}

ExcelExport::ExcelExport()
{
}

void ExcelExport::newExcel(const QString &fileName)
{
    pApplication = new QAxObject();
    //连接Excel控件
    pApplication->setControl("Excel.Application");
    //false不显示窗体（看具体过程）
    pApplication->dynamicCall("SetVisible(bool)", false);
    //不显示任何警告信息
    pApplication->setProperty("DisplayAlerts", false);

    pWorkBooks = pApplication->querySubObject("Workbooks");

    QFile file(fileName);
    if (file.exists())
    {
        pWorkBook = pWorkBooks->querySubObject(
            "Open(const QString &", fileName);
    }else {
        pWorkBooks->dynamicCall("Add");
        pWorkBook =
            pApplication->querySubObject("ActiveWorkBook");
    }
    //默认有一个worksheet
    pSheets = pWorkBook->querySubObject("Sheets");
    pSheet = pSheets->querySubObject("Item(int)",1);
}

void ExcelExport::setCellValue(int row, int column
    , const QString &value)
{
    QAxObject *pRange = pSheet->querySubObject("Cells(int,int)"
        , row, column);
    pRange->dynamicCall("Value", value);
    //内容居中
    pRange->setProperty("HorizontalAlignment", -4108);
    pRange->setProperty("VerticalAlignment", -4108);
}

void ExcelExport::setCellValue(int row, int column
    , const int &value)
{
    QAxObject *pRange = pSheet->querySubObject("Cells(int,int)"
        , row, column);
    pRange->setProperty("Value", value);
    //内容居中
    pRange->setProperty("HorizontalAlignment", -4108);
    pRange->setProperty("VerticalAlignment", -4108);
}
void ExcelExport::saveExcel(const QString &fileName)
{
    pWorkBook->dynamicCall("SaveAs(const QString &)",
        QDir::toNativeSeparators(fileName));

    pApplication->dynamicCall("Quit(void)");  //退出
    delete pApplication;
}

ExcelExport::~ExcelExport()
{
}










int utils::ping(QString ip)
{
    QString strArg = "ping " + ip + " -n 1 -w 1000";
    return QProcess::execute(strArg);
}

std::vector<std::string> utils::Split(const std::string& in, const std::string& delim) {
        std::regex re{ delim };
        // 调用 std::vector::vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
        // 构造函数,完成字符串分割
        return std::vector<std::string> {
            std::sregex_token_iterator(in.begin(), in.end(), re, -1),
            std::sregex_token_iterator()
        };
    }


float utils::KD(float & power)
{
    float dangwei[67] = {0.55, 0.75, 1.1, 1.5, 2.2, 3, 4, 5.5, 7.5, 11, 15, 18.5, 22, 30, 37, 45,
                         55, 75, 90, 110, 132, 160, 185,
                         200,220,250,280,315,355, 400,450,500,560,630,710,800,900,1000,1120,1250,1400,1600,1800,2000,2240,2500,2800, 3000,3150,3550,4000,4500,5000,5600,6300,7100,
                         8000,9000,10000,11200,12500,13000, 14000,15000,16000,17000,18000};

    for(int i=0; i <= 66; i++)
    {
        if(dangwei[i] >= power){
            qDebug() << QString("靠档 = %1").arg(dangwei[i]);

            return dangwei[i];
        }
    }
    return -1;
}



void utils::setKdComboBox(QComboBox * kdComboBox, const float &nkshpb)
{
    float dangwei[67] = {0.55, 0.75, 1.1, 1.5, 2.2, 3, 4, 5.5, 7.5, 11, 15, 18.5, 22, 30, 37, 45,
                         55, 75, 90, 110, 132, 160, 185,
                         200,220,250,280,315,355, 400,450,500,560,630,710,800,900,1000,1120,1250,1400,1600,1800,2000,2240,2500,2800, 3000,3150,3550,4000,4500,5000,5600,6300,7100,
                         8000,9000,10000,11200,12500,13000, 14000,15000,16000,17000,18000};

    int index;
    int num = 0;
    kdComboBox->clear();
    if (nkshpb >= 0 && nkshpb<=45)
    {
        for(int i=0;i<=15;i++){
            kdComboBox->addItem(QString("%1").arg(dangwei[i]));
            if (num == 0 && dangwei[i] >= nkshpb)
            {
                index = i;
                num += 1;
            }
        }
    }
    else if (nkshpb >= 55 && nkshpb <= 185)
    {
        qDebug() << "in xunhuan";
        for(int i=16; i<=22; i++){
            kdComboBox->addItem(QString("%1").arg(dangwei[i]));
            if (num == 0 && dangwei[i] >= nkshpb)
            {
                index = i - 16;
                num += 1;
                qDebug() << "index = " << index;
            }
        }
    }
    else if (nkshpb >= 200 && nkshpb <= 7100)
    {
        for(int i=23; i<=55; i++){
            kdComboBox->addItem(QString("%1").arg(dangwei[i]));
            if (num == 0 && dangwei[i] >= nkshpb)
            {
                index = i - 23;
                num += 1;
            }
        }
    }
    else if (nkshpb >= 8000 && nkshpb <= 18000)
    {
        for(int i=56; i<=66; i++){
            kdComboBox->addItem(QString("%1").arg(dangwei[i]));
            if (num == 0 && dangwei[i] >= nkshpb)
            {
                index = i - 56;
                num += 1;
            }
        }
    }
    kdComboBox->setCurrentIndex(index);
}



QString utils::getIPV4address()
{
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    QString ipv4 = "";
    foreach(QHostAddress address, info.addresses())
        {
            if(address.protocol()==QAbstractSocket::IPv4Protocol)
            {
                ipv4 = address.toString();
                qDebug() <<"My localhost IPv4 address: "<< address.toString();
                return ipv4;
            }
        }
    return ipv4;
}




float utils::YL(const float &dj)
{
    if (dj <= 5.5)
        return 0.5;
    else if(dj > 5.5 && dj <= 19)
        return 0.25;
    else if(dj > 19 && dj <= 55)
        return 0.15;
    else if(dj > 55 && dj <= 1000)
        return 0.1;
    else if (dj> 1000)
        return 0.05;
    return -1;
}





