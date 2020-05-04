#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include <QWidget>
#include <QVBoxLayout>
#include <QOpenGLWidget>
#include <QTreeWidget>
#include <QTableWidget>
#include <QSplitter>
#include <QPainter>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPalette>

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);
//    QTableWidget *table_widget;
//    QOpenGLWidget * openGLwindow;
//    QTreeWidget *tree_widget;
    QWidget * widgetMain, *widgetFlowChart;
    QPushButton *pushButton;

    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout * vlayout;

private:
//    QVBoxLayout *vlayout;
//    QSplitter *hsplitter;

signals:

public slots:


protected:
//    virtual void paintEvent(QPaintEvent *);


};

#endif // CENTRALWIDGET_H
