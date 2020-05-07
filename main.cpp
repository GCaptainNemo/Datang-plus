#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//#include <vld.h>
#include <QApplication>
#include <QFile>
#include <QDialog>
#include "window_project_login.h"
#include "main_window.h"
#include "main_window.h"

//class CommonHelper
//{
//public:
//    static void setStyle(const QString &style) {
//        QFile qss(style);
//        qss.open(QFile::ReadOnly);
//        qApp->setStyleSheet(qss.readAll());
//        qss.close();
//    }
//};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mainWindow = new MainWindow();

//    CommonHelper::setStyle("stylesheet.qss");
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    Login_window * loginWindow = new Login_window;
    loginWindow->connect(loginWindow, SIGNAL(setLimitSIGNAL(QString)), mainWindow, SLOT(setLimitSLOT(QString)));
    if (loginWindow->exec() == QDialog::Accepted)
    {
        delete loginWindow;
        mainWindow->showMaximized();
        return a.exec();
    }
    else
    {
        delete mainWindow;
        delete loginWindow;
        return 0;
    }
}
