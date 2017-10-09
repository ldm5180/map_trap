#include <GUnit.h>

#include "num_gen/num_gen.hpp"

GTEST("Num Gen") {
  NumGen sut{};

  SHOULD("start with 0") { EXPECT_EQ(0, sut()); }

  SHOULD("increment") {
    EXPECT_EQ(0, sut());
    EXPECT_EQ(1, sut());
    EXPECT_EQ(2, sut());
  }
}
