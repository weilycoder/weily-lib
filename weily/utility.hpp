#ifndef WEILY_UTILITY_HPP
#define WEILY_UTILITY_HPP
namespace weily {
struct Min {
  template <typename T>
  constexpr T operator()(const T &a, const T &b) const {
    return a < b ? a : b;
  }
} min;
struct Max {
  template <typename T>
  constexpr T operator()(const T &a, const T &b) const {
    return b < a ? a : b;
  }
} max;
struct Gcd {
  template <typename T> constexpr T operator()(T a, T b) const {
    while (b ^= a ^= b ^= a)
      a %= b;
    return a;
  }
} gcd;
} // namespace weily
#endif