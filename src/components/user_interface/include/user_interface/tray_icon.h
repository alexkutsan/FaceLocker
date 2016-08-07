#ifndef TRAY_ICON_H
#define TRAY_ICON_H
#include <functional>
namespace user_interface {

typedef std::function<void()> OnTrigeredCallBack;

class TrayIcon {
  void SetOnCLickedCallbcak(OnTrigeredCallBack call_back);
};

}  // namespace user_interface
#endif  // TRAY_ICON_H
