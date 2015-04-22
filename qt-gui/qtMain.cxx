#include <QApplication>
#include "qcard.hxx"

#include "mainwindow.hxx"

 int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;

    mainWindow.show();

    return app.exec();
}
