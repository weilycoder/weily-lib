#ifndef WEILY_BITS_HPP
#define WEILY_BITS_HPP
#include "weily/types.hpp"
namespace weily {
constexpr u64 getBit(u64 a, int b) { return (a >> b) & 1; }
constexpr u64 unsetBit(u64 a, int b) { return a & ~(1 << b); }
constexpr u64 setBit(u64 a, int b) { return a | (1 << b); }
constexpr u64 flapBit(u64 a, int b) { return a ^ (1 << b); }
constexpr u32 popcount(u32 x) { return __builtin_popcountl(x); }
constexpr u32 popcount(i32 x) { return __builtin_popcountl(x); }
constexpr u32 popcount(u64 x) { return __builtin_popcountll(x); }
constexpr u32 popcount(i64 x) { return __builtin_popcountll(x); }
constexpr u32 countl_zero(u32 x) { return __builtin_clzl(x); }
constexpr u32 countl_zero(i32 x) { return __builtin_clzl(x); }
constexpr u32 countl_zero(u64 x) { return __builtin_clzll(x); }
constexpr u32 countl_zero(i64 x) { return __builtin_clzll(x); }
constexpr u32 countr_zero(u32 x) { return __builtin_ctzl(x); }
constexpr u32 countr_zero(i32 x) { return __builtin_ctzl(x); }
constexpr u32 countr_zero(u64 x) { return __builtin_ctzll(x); }
constexpr u32 countr_zero(i64 x) { return __builtin_ctzll(x); }
constexpr u32 int_log2(u32 x) { return 31 - countl_zero(x); }
constexpr u32 int_log2(u64 x) { return 63 - countl_zero(x); }
constexpr u64 lowbit(u64 x) { return x & -x; }
constexpr u64 highbit(u64 x) { return 1ull << int_log2(x); }
} // namespace weily
#endif