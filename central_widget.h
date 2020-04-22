#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QTableWidget>
#include <QSplitter>
class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);
    QTableWidget *table_widget;
    QTreeWidget *tree_widget;


private:
    QVBoxLayout *vlayout;
    QSplitter *hsplitter;

signals:

public slots:
};

#endif // CENTRALWIDGET_H
