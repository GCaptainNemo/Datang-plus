#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include "par_others.h"

class about_window : public QDialog
{
    Q_OBJECT
public:
    static int num;
    about_window(QWidget * parent = nullptr);
    ~about_window();


private:
    QLabel * softwareLabel, * versionLabel, * companyLabel, *resLabel;
    QPushButton *okButton;
    QGridLayout *layout;

};

#endif // ABOUT_WINDOW_H
