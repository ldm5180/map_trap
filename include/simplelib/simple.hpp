#ifndef SIMPLE_HPP
#define SIMPLE_HPP

namespace LibSimple {
inline namespace v1 {

class Simple {
public:
  constexpr Simple() = default;
  explicit Simple(const int v) : value_(v) {}

  int value() const;

private:
  int value_{};
};

} // v1
} // LibSimple

#endif // SIMPLE_HPP
