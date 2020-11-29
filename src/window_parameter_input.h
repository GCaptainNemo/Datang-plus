#ifndef WINDOW_PARAMETER_INPUT_H
#define WINDOW_PARAMETER_INPUT_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QDialog>
#include <QTabWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include <QLineEdit>
#include <QFrame>
#include "par_gasresult.h"
#include "par_pinf.h"
#include <math.h>
#include "widget_okcancel.h"
#include "par_const.h"

class inputParameterWindow : public QDialog
{
    Q_OBJECT
public:
    explicit inputParameterWindow(QWidget *parent = nullptr);
    static int num, bz1, bz2, shr;
    static float shd, f1, f6, f7, f8, f9, f10;
    ~inputParameterWindow();


signals:

public slots:
    void okSLOT();

protected:
    QGridLayout * zongLayout;
    QTabWidget *tabwidget;
    widget_okcancel * buttonWidget;
    QWidget *tabInWidget1, *tabInWidget2, *tabInWidget3;
    QVBoxLayout * layout1, *layout2;
    QGridLayout *gridLayout3;

    // tabInwidget1

    QWidget * widget11, *widget12, *widget13;

    QGridLayout *gridLayout11, *gridLayout12, *gridLayout13;

    QRadioButton * wetRadiobutton, *dryRadiobutton;
    QButtonGroup * group1;
    QLabel * gasNumLabel, *gasTempLabel, *pressureLabel;
    QLineEdit *gasNumLineedit, *gasTempLineedit, *pressureLineedit;

    QLabel *gasComponentLabel, * o2Label, *co2Label, *h2oLabel;
    QLineEdit *o2Lineedit, *co2Lineedit, *h2oLineedit;

    QCheckBox *dryCheckbox;
    QLabel * so2Label, *so3Label, *hclLabel, *hfLabel, *dustLabel;
    QLineEdit *so2Lineedit, *so3Lineedit, *hclLineedit, *hfLineedit, *dustLineedit;

    // tabInwidget2

    QWidget * widget21, *widget22, *widget23;
    QGridLayout *gridLayout21, *gridLayout22, *gridLayout23;
    QLabel * caco3ComponentLabel;
    QComboBox *caco3Combobox1, *caco3Combobox2, *otherCombobox;
    QLineEdit * caco3Lineedit1, * caco3Lineedit2, *otherLineedit;

    QLabel * h2oQualityLabel, *clLabel;
    QLineEdit * clLineedit;

    QLabel * label20, *label21, *label22, *label23, *label24, *label25, *label26;
    QLineEdit  *lineedit21, *lineedit22, *lineedit23, *lineedit24, *lineedit25, *lineedit26;



    // tabInwidget3

    QLabel * label0, *label1, *label2, * label3, *label4, *label5, * label6, *label7, *label8, * label9, *label10,
    *label11, * label12;
    QLineEdit * lineedit1, *lineedit2, *lineedit3, * lineedit4, *lineedit5, *lineedit6, * lineedit7, *lineedit8,
    *lineedit9, * lineedit10, *lineedit11, *lineedit12;








private:
    void initWidget1();
    void initWidget2();
    void initWidget3();
    void initParWidget1();
    void initParWidget2();
    void initParWidget3();

};

#endif // WINDOW_PARAMETER_INPUT_H
