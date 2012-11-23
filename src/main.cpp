#include <QApplication>
#include <QDesktopWidget>
#include "TranslateIt.h"
#include <QtPlugin>

Q_IMPORT_PLUGIN(qico);

int main(int argc, char* argv[])
{

    Q_INIT_RESOURCE(resources);

    QApplication app(argc, argv);
    QPoint screenSize = app.desktop()->screenGeometry().bottomRight();
    TranslateIt window(screenSize);
    window.show();

    return app.exec();
}

