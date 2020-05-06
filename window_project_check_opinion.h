#ifndef WINDOW_PROJECT_CHECK_OPINION_H
#define WINDOW_PROJECT_CHECK_OPINION_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "utils.h"
#include "par_users.h"
#include "par_projects.h"

class window_project_check_opinion : public QDialog
{
    Q_OBJECT
public:
    explicit window_project_check_opinion(QWidget *parent = nullptr);
    ~window_project_check_opinion();
    static int num;



signals:

public slots:

protected:
    QLabel *checkStateLabel, *checkOpinionLabel, *verifyOpinionLabel;

    QLineEdit *checkStateLineedit;
    QTextEdit *checkOpinionTextedit, *verifyOpinionTextEdit;
    QGridLayout * layout;
    QSqlDatabase db;
    QSqlQuery * query;
    void initTextEdit();
};

#endif // WINDOW_PROJECT_CHECK_OPINION_H
