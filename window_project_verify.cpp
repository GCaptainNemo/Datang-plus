#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_project_verify.h"


void window_project_check_verify::okSLOT()
{
    if(checkOpinionTextedit->toPlainText() == "")
    {
        QMessageBox::warning(this, tr("输入错误"), tr("意见输入不能为空"));
    }
    else if(!passRadioButton->isChecked() && !recalculateRadioButton->isChecked())
    {
        QMessageBox::warning(this, tr("输入错误"), tr("请选择“审核通过”或“重新计算”"));
    }
    else
    {
        this->checking();
    }

}

void window_project_check_verify::checking()
{
    if (utils::ping(otherPar::ip)==0)
    {
        if(!db.open())                                      //打开数据库
        {
            QMessageBox::warning(this, tr("连接结果"), tr("数据库连接失败"));
        }
        else
        {
            QString sqlStatement;
            if (passRadioButton->isChecked())
            {
                sqlStatement =  QString("UPDATE projects SET prstate = '审核通过', "
                                        "prverify='%1', prverifyinf='%2' WHERE prid='%3'"
                                        ).arg(otherPar::userid).arg(checkOpinionTextedit->toPlainText()).arg(otherPar::prid);
            }
            else
            {
                sqlStatement =  QString("UPDATE projects SET prstate = '审核未通过返回重新计算', "
                                     "prverify='%1', prverifyinf='%2' WHERE prid='%3'"
                                     ).arg(otherPar::userid).arg(checkOpinionTextedit->toPlainText()).arg(otherPar::prid);
            }
            this->query->exec(sqlStatement);
            QString ipv4 = utils::getIPV4address();
            QDateTime curDateTime = QDateTime::currentDateTime();
            QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
            QString sqlMax = "SELECT MAX(recid) FROM records";
            query->exec(sqlMax);
            query->next();
            int recid = query->value(0).toInt() + 1;
            QString sqlInsertRecords = QString ("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '审核项目%5')").arg(recid).
            arg(otherPar::userid).arg(ipv4).arg(date).arg(otherPar::prid);

            query->exec(sqlInsertRecords);
            delete query;
            QMessageBox::information(this, tr("提交结果"), tr("审核提交成功！"));
            this->close();
        }
    }
    else
    {
        QMessageBox::warning(this, tr("连接结果"), tr("服务器连接失败, 请进行网络测试"));
    }
}


