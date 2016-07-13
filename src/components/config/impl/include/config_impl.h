#ifndef CONFIG_IMPL_H
#define CONFIG_IMPL_H
#include "config/config.h"

namespace config {
class ConfigImpl : public Config {


    const int GetIntValue(const std::string& section, std::string& key) override;
    const std::string GetStringValue(const std::string& section, std::string& key) override;

     void SetIntValue(const std::string& section, std::string& key, const int value) override;
     void SetStringValue(const std::string& section, std::string& key, const std::string& value) override;
     void Save() override;
};
}
#endif // CONFIG_IMPL_H

