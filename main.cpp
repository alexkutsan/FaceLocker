
#include <QtGui>
#include <QApplication>

#include "logger/logger.h"
#include "tray_icon_impl.h"

CREATE_LOGGER("Main")

int main(int argc, char* argv[]) {
    log4cplus::initialize();
    log4cplus::PropertyConfigurator::doConfigure("log4cplus.properties");
    QApplication app(argc, argv);
    user_interface::TrayIconImpl icon;
    return app.exec();
}
