#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "widget_central.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    this->vlayout = new QVBoxLayout(this);

//    this->hsplitter = new QSplitter(Qt::Horizontal, 0);
//    this->vlayout->addWidget(this->hsplitter);
//    this->tree_widget = new QTreeWidget(this);
//    this->table_widget = new QTableWidget(this);
//    this->openGLwindow = new QOpenGLWidget(this);

//    hsplitter->addWidget(this->tree_widget);
    //    hsplitter->addWidget(this->table_widget);
//    hsplitter->addWidget(this->openGLwindow);
    widgetMain = new QWidget(this);
    widgetFlowChart = new QWidget(this);

    pushButton = new QPushButton(widgetFlowChart);
    pushButton->setIcon(QPixmap("..//FML//icon//pic//1.jpg"));
    pushButton->setObjectName(QStringLiteral("pushButton"));
    pushButton->setGeometry(QRect(150, 160, 112, 34));
    pushButton_2 = new QPushButton(widgetFlowChart);
    pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
    pushButton_2->setGeometry(QRect(300, 510, 112, 34));
    pushButton_3 = new QPushButton(widgetFlowChart);
    pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
    pushButton_3->setGeometry(QRect(480, 510, 112, 34));
    label = new QLabel(widgetFlowChart);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(160, 400, 81, 18));
    label_2 = new QLabel(widgetFlowChart);
    label_2->setObjectName(QStringLiteral("label_2"));
    label_2->setGeometry(QRect(50, 520, 131, 21));
    pushButton->setText(QApplication::translate("Form", "\347\203\237\345\233\261", Q_NULLPTR));
    pushButton_2->setText(QApplication::translate("Form", "\345\216\237\347\203\237\346\260\224\346\214\241\346\235\277", Q_NULLPTR));
    pushButton_3->setText(QApplication::translate("Form", "\345\242\236\345\216\213\351\243\216\346\234\272", Q_NULLPTR));
    label->setText(QApplication::translate("Form", "\346\227\201\347\225\245\346\214\241\346\235\277", Q_NULLPTR));
    label_2->setText(QApplication::translate("Form", "\346\235\245\350\207\252\345\274\225\351\243\216\346\234\272\347\203\237\346\260\224", Q_NULLPTR));
    widgetFlowChart->hide();

    this->vlayout->addWidget(this->widgetMain);
    this->vlayout->addWidget(this->widgetFlowChart);

    widgetMain->setAutoFillBackground(true);
    QPixmap pixmap("D:\coding_cpp\FML_system\icon\pic\1.jpg");
    QPalette palette;

    palette.setBrush(QPalette::Background, QBrush(pixmap));
    widgetMain->setPalette(palette);
//    widgetMain->setStyleSheet("background-image:url(..//FML//icon//pic//1.jpg)");

};

//void CentralWidget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    painter.drawLine(QPointF(0, 0), QPointF(100, 100));
//}

