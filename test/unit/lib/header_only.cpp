#include <GUnit.h>

#include "header_only/header.hpp"

GTEST("Header Only") {
  LibHeader::HeaderOnly sut{2, 42};

  SHOULD("multiply") { EXPECT_EQ(2 * 42, sut.mult()); }
  SHOULD("add") { EXPECT_EQ(2 + 42, sut.add()); }
}
