#ifndef NUM_GEN_HPP
#define NUM_GEN_HPP

#include <iostream>
class NumGen {
public:
  auto operator()() { return next_++; }

private:
  int next_{};
};

#endif // NUM_GEN_HPP
