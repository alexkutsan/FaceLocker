#include "config_impl.h"

#include "limo/test_main.hpp"

LTEST(config_test) {
  config::ConfigImpl test_config("./config.ini");
  EXPECT_EQ(1, 2);
  test_config.Load();
};
