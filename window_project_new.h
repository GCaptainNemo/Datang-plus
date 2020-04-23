#ifndef NEWPROJECTWINDOW_H
#define NEWPROJECTWINDOW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class newPjWindow : public QDialog
{
    Q_OBJECT
public:
    static int num;
    explicit newPjWindow(QWidget *parent = nullptr);
    ~newPjWindow();
    void okAction();


signals:

public slots:

private:
    QLabel * nameLabel;
    QLineEdit * nameLineedit;
    QPushButton * okButton;
    QHBoxLayout * layout;
};

#endif // NEWPROJECTWINDOW_H
