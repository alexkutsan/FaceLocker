#include "config_impl.h"
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>

namespace config {
/**
* @brief isNumber check if input contains only digits.
* @param input is a string that should be checked.
* @return true if there are only digits, and false if not
*/
bool isNumber(const std::string& input) {
  // TODO(IoannaV): #5 Reimplement this function
  const std::string digits = "0123456789";
  return std::string::npos != input.find_first_not_of(digits);
}
/**
 * @brief makeMapaKey unites section and key to one vriable
 * @param section is a string, used to make mapa key
 * @param key is a string, used to make mapa key
 * @return string, that consist of two parametors
 */
const std::string makeMapKey(const std::string& section,
                             const std::string& key) {
  const std::string mapa_key = section + "_" + key;
  return mapa_key;
}

const std::tuple<int, error::ErrorCode> ConfigImpl::GetIntValue(
    const std::string& section, const std::string& key) const {
  if (section.empty() || key.empty()) {
    return std::make_tuple(-1, error::ErrorCode::kEmptyString);
  }

  std::string map_key = makeMapKey(section, key);
  auto it = value_storage_.find(map_key);
  if (it == value_storage_.end()) {
    return std::make_tuple(-1, error::ErrorCode::kValueNotFound);
  }
  const std::string& str_value = it->second;
  if (!isNumber(str_value)) {
    return std::make_tuple(-1, error::ErrorCode::kWrongValue);
  }
  const int value = std::stoi(str_value, nullptr, 10);
  return std::make_tuple(value, error::ErrorCode::kSuccess);
}

const std::tuple<std::string, error::ErrorCode> ConfigImpl::GetStringValue(
    const std::string& section, const std::string& key) const {
  if (section.empty() || key.empty()) {
    return std::make_tuple("-1", error::ErrorCode::kEmptyString);
  }
  const std::string map_key = makeMapKey(section, key);
  auto it = value_storage_.find(map_key);
  if (it == value_storage_.end()) {
    return std::make_tuple("", error::ErrorCode::kValueNotFound);
  }
  const std::string& value = it->second;
  return std::make_tuple(value, error::ErrorCode::kSuccess);
}

void ConfigImpl::SetIntValue(const std::string& section,
                             const std::string& key,
                             const int value) {
  std::string new_key = makeMapKey(section, key);
  value_storage_[new_key] = value;
}

void ConfigImpl::SetStringValue(const std::string& section,
                                const std::string& key,
                                const std::string& value) {
  std::string new_key = makeMapKey(section, key);
  value_storage_[new_key] = value;
}

void ConfigImpl::Save() {}

/**
 * @brief ExtractSection check if line contains section name and extract it.
 * input format: "[Section name]"
 * @param line is a srting with section name.
 * @param section is an output parameter, where section name will be stored.
 * @return true, if section name extracted successfuly, in other case return
 * false.
 */
bool ExtractSection(const std::string& line, std::string* section) {
  size_t const open_bracket = line.find('[');
  size_t const close_bracket = line.find(']');
  if (section == nullptr) {
    return false;
  } else {
    if (open_bracket == std::string::npos ||
        close_bracket == std::string::npos) {
      return false;
    }
    if (close_bracket < open_bracket) {
      return false;
    }
    if (section->empty()) {
      *section = line.substr(open_bracket, close_bracket);
      return true;
    }
  }
}

/**
 * @brief ExtractKeyValue check existing of key and value in line and extract
 * them from line.
 * input format: "key = value"
 * @param line is a string with key and value, delimeted with equal operator.
 * @param key left part of line.
 * @param value right part of line.
 * @return true if key and value extracted successfuly, in other case return
 * false.
 */
bool ExtractKeyValue(const std::string& line,
                     std::string* key,
                     std::string* value) {
  if (key != nullptr || value != nullptr) {
    size_t equal = line.find('=');
    if (equal = std::string::npos) {
      return false;
    }
    *key = line.substr(0, equal);
    *value = line.substr(equal, std::string::npos);
    return true;
  } else {
    return false;
  }
}

bool ConfigImpl::Load() {
  std::ifstream stream;
  stream.open(file_name_);
  if (!stream.is_open()) {
    return false;
  }
  std::string line;
  std::string current_section = "";
  while (std::getline(stream, line)) {
    if (ExtractSection(line, &current_section)) {
      continue;
    }
    std::string key;
    std::string value;
    if (ExtractKeyValue(line, &key, &value)) {
      SetStringValue(current_section, key, value);
      continue;
    }
    return true;
  }
}
}  // namespace config
