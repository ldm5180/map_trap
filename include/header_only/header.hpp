#ifndef HEADER_HPP
#define HEADER_HPP

namespace LibHeader {
inline namespace v1 {

class HeaderOnly {
public:
  explicit HeaderOnly() = default;
  explicit HeaderOnly(const int a, const int b) : a_(a), b_(b) {}
  constexpr int mult() const { return a_ * b_; }
  constexpr int add() const { return a_ + b_; }

private:
  int a_{};
  int b_{};
};

} // v1
} // LibHeader

#endif // HEADER_HPP
