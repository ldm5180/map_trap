#include <gmock/gmock.h>

#include "header_only/header.hpp"

class HeaderOnlyTest : public ::testing::Test {
protected:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(HeaderOnlyTest, should_multiply) {
  EXPECT_EQ(2 * 42, LibHeader::HeaderOnly(2, 42).mult());
}
