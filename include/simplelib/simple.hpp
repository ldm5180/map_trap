#ifndef SIMPLE_HPP
#define SIMPLE_HPP

namespace LibSimple {
inline namespace v1 {

class Simple {
public:
  constexpr Simple() = default;
  explicit Simple(const int v) : val(v) {}

  int value() const;

private:
  int val{};
};

} // v1
} // LibSimple

#endif // SIMPLE_HPP
