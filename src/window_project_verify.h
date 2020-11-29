#ifndef WINDOW_PROJECT_CHECK_VERIFY_H
#define WINDOW_PROJECT_CHECK_VERIFY_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include "window_project_check.h"


class window_project_check_verify : public checkProjectWindow
{
    Q_OBJECT
public:
    explicit window_project_check_verify(QWidget *parent = nullptr):checkProjectWindow(parent)
    {
        this->setWindowTitle(tr("审核项目"));
        this->passRadioButton->setText(tr("审核通过"));
    }
    virtual void checking();

signals:

public slots:
    virtual void okSLOT();

};

#endif // WINDOW_PROJECT_CHECK_VERIFY_H
