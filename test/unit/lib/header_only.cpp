#include <gmock/gmock.h>

#include "header_only/header.hpp"

class HeaderOnlyTest : public ::testing::Test {
protected:
  void SetUp() override { sut = LibHeader::HeaderOnly{2, 42}; }
  void TearDown() override {}

  LibHeader::HeaderOnly sut{};
};

TEST_F(HeaderOnlyTest, should_multiply) { EXPECT_EQ(2 * 42, sut.mult()); }

TEST_F(HeaderOnlyTest, should_add) { EXPECT_EQ(2 + 42, sut.add()); }
