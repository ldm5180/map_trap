#include <gmock/gmock.h>

#include "simplelib/simple.hpp"

class SimpleTest : public ::testing::Test {
protected:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(SimpleTest, should_have_default_value) {
  EXPECT_EQ(0, LibSimple::Simple{}.value());
}

TEST_F(SimpleTest, should_have_initialized_value) {
  EXPECT_EQ(42, LibSimple::Simple(42).value());
}
