#ifndef WEILY_MATHS_HPP
#define WEILY_MATHS_HPP
#include "weily/bits.hpp"
namespace weily {
inline constexpr i64 fast_gcd(i64 a, i64 b) {
  i64 i = countr_zero(a);
  i64 j = countr_zero(b);
  i64 k = i < j ? i : j;
  i64 d = 0;
  b >>= j;
  while (a) {
    a >>= i;
    d = b - a;
    i = countr_zero(d);
    if (a < b)
      b = a;
    if (d < 0)
      a = -d;
    else
      a = d;
  }
  return b << k;
}
} // namespace weily
#endif