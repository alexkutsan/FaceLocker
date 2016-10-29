#ifndef CONFIG_IMPL_H
#define CONFIG_IMPL_H
#include <map>
#include <string>
#include "config/config.h"

namespace config {
/**
 * @brief The ConfigImpl class with override methods of Config Class
 */
class ConfigImpl : public Config {
 public:
  ConfigImpl(const std::string& file_name) : file_name_(file_name) {}

  const std::tuple<int, error::ErrorCode> GetIntValue(
      const std::string& section, const std::string& key) const override;

  const std::tuple<std::string, error::ErrorCode> GetStringValue(
      const std::string& section, const std::string& key) const override;

  void SetIntValue(const std::string& section,
                   const std::string& key,
                   const int value) override;
  void SetStringValue(const std::string& section,
                      const std::string& key,
                      const std::string& value) override;
  void Save() override;
  bool Load() override;

 private:
  std::map<std::string, std::string> value_storage_;
  std::string const file_name_;
};
}
#endif  // CONFIG_IMPL_H
