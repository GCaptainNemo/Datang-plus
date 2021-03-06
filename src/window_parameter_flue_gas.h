﻿#ifndef WINDOW_PARAMETER_FLUE_GAS_H
#define WINDOW_PARAMETER_FLUE_GAS_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QDialog>
#include <QStringList>
#include <QHeaderView>
#include <QDebug>
#include <QTableWidgetItem>
#include "par_gasresult.h"

class window_parameter_flue_gas : public QDialog
{
    Q_OBJECT
public:
    explicit window_parameter_flue_gas(QWidget *parent = nullptr);

signals:

public slots:


protected:
    QTableWidget * tableWidget;
    QVBoxLayout * layout;
    void initTableWidget();
};

#endif // WINDOW_PARAMETER_FLUE_GAS_H
