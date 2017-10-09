#include <GUnit.h>

#include "simplelib/simple.hpp"

GTEST("Simple") {
  SHOULD("have default value") { EXPECT_EQ(0, LibSimple::Simple{}.value()); }

  SHOULD("have initialized value") {
    EXPECT_EQ(42, LibSimple::Simple(42).value());
  }
}
