#include <gmock/gmock.h>

#include "num_gen/num_gen.hpp"

class NumGenTest : public ::testing::Test {
protected:
  void SetUp() override {}
  void TearDown() override {}

  NumGen sut{};
};

TEST_F(NumGenTest, should_start_with_0) { EXPECT_EQ(0, sut()); }

TEST_F(NumGenTest, should_increment) {
  EXPECT_EQ(0, sut());
  EXPECT_EQ(1, sut());
  EXPECT_EQ(2, sut());
}
