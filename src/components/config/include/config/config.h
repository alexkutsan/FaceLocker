#ifndef CONFIG_H
#define CONFIG_H
#include <string>
namespace config {

class Config {
public:
   virtual const int GetIntValue(const std::string& section, std::string& key) = 0;
   virtual const std::string GetStringValue(const std::string& section, std::string& key) = 0;

    virtual void SetIntValue(const std::string& section, std::string& key, const int value) = 0;
    virtual void SetStringValue(const std::string& section, std::string& key, const std::string& value) = 0;
    virtual void Save() = 0;
};

}  // namespace config
#endif // CONFIG_H

