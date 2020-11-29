#ifndef WINDOW_PARAMETER_ABSORB_TOWER_H
#define WINDOW_PARAMETER_ABSORB_TOWER_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QComboBox>
#include <QFrame>

class window_parameter_absorb_tower : public QDialog
{
    Q_OBJECT
public:
    explicit window_parameter_absorb_tower(QWidget *parent = nullptr);
    static int num;
    ~window_parameter_absorb_tower();
signals:

public slots:


protected:
    QWidget *widgetrow;
    QHBoxLayout * hlayout;
    QVBoxLayout * layout;


    QWidget *widget1, *widget3, *widget4;

    QGridLayout * gridlayout1;
    QLabel * label111, *label112, *label113, *label12, *label13,
    *label14, *label15, *label16, *label17, *label18, *label19, *label1_10, *label1_11, *label1_12;
    QDoubleSpinBox * spinBox2,* spinBox3,* spinBox5, * spinBox6, * spinBox7,* spinBox8,* spinBox9,*
    spinBox10, * spinBox11;
    QLineEdit * lineedit12, *lineedit13, *lineedit141, *lineedit142, *lineedit1_12;
    QPushButton * okButton, *exportExcelButton;


    QLabel *label20, * label21, * label22, * label23, * label24, * label25, * label26, * label27, * label28, * label29, * label210;
    QLineEdit * lineedit21, *lineedit22, *lineedit231, *lineedit232, *lineedit241, *lineedit242,
    *lineedit25, *lineedit26, *lineedit27, *lineedit281, *lineedit282, *lineedit29, *lineedit2_10;


    QGridLayout * gridlayout3;
    QLabel *label311, *label312, *label321, *label322, *label323, *label331, *label332, *label333,
    *label341, *label342, *label343;
    QRadioButton * radioButton31, *radioButton32, *radioButton33, *radioButton34;
    QLineEdit * lineedit321, *lineedit322, *lineedit323, *lineedit331, *lineedit332, *lineedit333,
    *lineedit341, *lineedit342;
    QComboBox * comboBox343;


    void initWidget1();
    void initWidget2();
    void initWidget3();
    void initWidget4();




};

#endif // WINDOW_PARAMETER_ABSORB_TOWER_H
