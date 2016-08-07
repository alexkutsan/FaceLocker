#include "tray_icon_impl.h"
#include <memory>

#include <QDialog>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QtGui>

namespace user_interface {

user_interface::TrayIconImpl::TrayIconImpl()
    : tray_icon_(new QSystemTrayIcon()) {
  ShowIcon();
}

void TrayIconImpl::ShowIcon() {
  if (QSystemTrayIcon::isSystemTrayAvailable()) {
    QIcon icon(
        "/home/alex/pro/FaceRecognizer/src/components/user_interface/icon.png");
    tray_icon_->setIcon(icon);
    tray_icon_->show();
  } else {
    QMessageBox::critical(0,
                          QObject::tr("Systray"),
                          QObject::tr("Couldn't detect any system tray "
                                      "on this system."));
  }
}
}
