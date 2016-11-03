#include <iostream>
#include "config_impl.h"

#include "limo/test_main.hpp"

LTEST(config_test) {

  LTEST(load_config) {
        config::ConfigImpl test_config("./valid_config.ini");
        EXPECT_TRUE(test_config.Load());
  };

  LTEST(invalid_path_to_config) {
      config::ConfigImpl test_config("./path_to_invalid_config.ini");
      EXPECT_FALSE(test_config.Load());
  };

  LTEST(set_int_get_int_test) {
        config::ConfigImpl test_config("./config.ini");
        test_config.SetIntValue("Main", "int", 5);
        auto int_val = test_config.GetIntValue("Main", "int");
        const config::error::ErrorCode error = std::get<1>(int_val);
        EXPECT_EQ(5, std::get<0>(int_val));
        EXPECT_EQ(config::error::ErrorCode::kSuccess,
                  std::get<1>(int_val));
  };

  LTEST(set_string_get_string_test) {
        config::ConfigImpl test_config("./config.ini");
        test_config.SetStringValue("Main", "string", "str");
        auto string_val = test_config.GetStringValue("Main", "string");
        const config::error::ErrorCode error = std::get<1>(string_val);
        EXPECT_EQ("str", std::get<0>(string_val));
        EXPECT_EQ(config::error::ErrorCode::kSuccess,
                  std::get<1>(string_val));
  };

  LTEST(read_int_test) {
        config::ConfigImpl test_config("./config.ini");
        EXPECT_TRUE(test_config.Load());
        auto int_val = test_config.GetIntValue("Main", "int");
        std::cout << std::get<0>(int_val) << std::endl;
        const config::error::ErrorCode error = std::get<1>(int_val);
        std::cout << (int) error << std::endl;
        EXPECT_EQ(5, std::get<0>(int_val));
        EXPECT_EQ(config::error::ErrorCode::kSuccess,
                  std::get<1>(int_val));
  };

};
