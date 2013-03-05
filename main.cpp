#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QPluginLoader loader;
    loader.setFileName("qsqloci4.dll");
    loader.load();

    qApp->addLibraryPath( qApp->applicationDirPath() + "/plugins");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
