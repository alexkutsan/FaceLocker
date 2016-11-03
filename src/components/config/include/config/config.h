#ifndef CONFIG_H
#define CONFIG_H
#include <exception>
#include <string>
#include <tuple>

namespace config {
namespace error {
enum class ErrorCode {
  kSuccess = 0,
  kFileNotFound,
  kWrongValue,
  kEmptyString,
  kValueNotFound,
};
}
/**
 * @brief The Config class is used for configurations of data
 */
class Config {
 public:
  /**
  * @brief GetIntValue get value to mapa key
   * @param section is a string, used to make mapa key
   * @param key is a sting, used to make mapa key
   * @return mapa key and error code
  */
  virtual const std::tuple<int, error::ErrorCode> GetIntValue(
      const std::string& section, const std::string& key) const = 0;
  /**
   * @brief GetStringValue get value to mapa key
   * @param section is a string, used to make mapa key
   * @param key is a sting, used to make mapa key
   * @return mapa key and error code
   */
  virtual const std::tuple<std::string, error::ErrorCode> GetStringValue(
      const std::string& section, const std::string& key) const = 0;
  /**
   * @brief SetIntValue set value for mapa key
   * @param section is a string which will be part of mapa key
   * @param key is a string which will be part of mapa key
   * @param value is a number which will be contained in mapa key
   */
  virtual void SetIntValue(const std::string& section,
                           const std::string& key,
                           const int value) = 0;
  /**
   * @brief SetStringValue set value for mapa key
   * @param section is a string which will be part of mapa key
   * @param key is a string which will be part of mapa key
   * @param value is a number which will be contained in mapa key
   * */
  virtual void SetStringValue(const std::string& section,
                              const std::string& key,
                              const std::string& value) = 0;
  virtual void Save() = 0;
  /**
   * @brief ConfigImpl::Load loads infomation from file
   */
  virtual bool Load() = 0;
};

}  // namespace config
#endif  // CONFIG_H
