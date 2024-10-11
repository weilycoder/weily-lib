#ifndef WEILY_ST_HPP
#define WEILY_ST_HPP
#include "weily/bits.hpp"
#include "weily/utility.hpp"
#include <vector>

namespace weily {
/**
 * ST（稀疏表）模板
 * @tparam T 元素类型；
 * @tparam Merge 合并贡献函数，为了正确计算，函数应该可重复贡献。
 */
template <typename T, class Merge> class sparse_table {
  std::vector<std::vector<T>> st;
  Merge merge;

public:
  template <class InputIt> sparse_table(InputIt first, InputIt last) {
    st.emplace_back(first, last);
    st[0].shrink_to_fit();
    size_t N = st[0].size();
    for (size_t i = 1; (size_t)1 << i <= N; ++i) {
      st.emplace_back(N - (1 << i));
      for (size_t j = 0; j < N - (1 << i); ++j)
        st[i][j] = merge(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    st.shrink_to_fit();
  }
  T get(size_t l, size_t r) const {
    size_t k = int_log2(r - l);
    return merge(st[k][l], st[k][r - ((size_t)1 << k)]);
  }
};

template <typename T> using sparse_table_min = sparse_table<T, Min>;
template <typename T> using sparse_table_max = sparse_table<T, Max>;
template <typename T> using sparse_table_gcd = sparse_table<T, Gcd>;
} // namespace weily
#endif
