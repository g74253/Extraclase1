#include <QApplication>
#include "mainwindow.h"

using namespace std;

/// main: corre la interfaz
/// \param argc:(int)
/// \param argv:(char*)
/// \return (QApplication) interfaz
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return QApplication::exec();
}
