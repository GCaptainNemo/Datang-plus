#include "main_window.h"
#include <QApplication>
#include "window_project_login.h"
#include "main_window.h"

#include <QDialog>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mainWindow = new MainWindow();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    Login_window * loginWindow = new Login_window;
    if (loginWindow->exec() == QDialog::Accepted)
    {
        delete loginWindow;
        mainWindow->showMaximized();
        return a.exec();
    }
    else
    {
        return 0;
    }


}
