#ifndef WIDGET_OKCANCEL_H
#define WIDGET_OKCANCEL_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class widget_okcancel : public QWidget
{
    Q_OBJECT
public:
    explicit widget_okcancel(QWidget *parent = nullptr);
    QHBoxLayout * layout;
    QPushButton * okButton, *cancelButton;

signals:

public slots:

};

#endif // WIDGET_OKCANCEL_H
