#ifndef TRAY_ICON_IMPL_H
#define TRAY_ICON_IMPL_H
#include <QSystemTrayIcon>
#include <memory>
#include "user_interface/tray_icon.h"

namespace user_interface {
class TrayIconImpl : public TrayIcon {
 public:
  TrayIconImpl();

 private:
  std::unique_ptr<QSystemTrayIcon> tray_icon_;
  void ShowIcon();
};

}  // namespace user_interface

#endif  // TRAY_ICON_IMPL_H
