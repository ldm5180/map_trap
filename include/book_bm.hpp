#ifndef BOOK_BM_HPP
#define BOOK_BM_HPP

#include "add_to_map.hpp"

#include <cstdlib>

template <class map_t, int levels>
static void BM_map_book(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  std::vector<typename map_t::key_type> keys;
  keys.reserve(levels);
  add_to_map_and_key_list(levels, map, keys,
                          /* is_sorted = */ false);

  const auto is_top_update = [] { return std::rand() % 2 == 0; };
  const auto is_remove_level = [&state] {
    return std::rand() % (100 / state.range(0)) == 0;
  };
  const auto non_top_price_level = [&keys] {
    return keys[std::rand() % levels];
  };

  constexpr auto is_unordered = std::is_same<
      std::unordered_map<typename map_t::key_type, typename map_t::mapped_type>,
      map_t>::value;

  const auto top_of_book = [](auto &map) {
    if
      constexpr(is_unordered) {
        std::vector<
            std::pair<typename map_t::key_type, typename map_t::mapped_type>>
            sorted(map.begin(), map.end());
        std::sort(sorted.begin(), sorted.end(), [](auto &a, auto &b) {
          const auto[key, qty] = a;
          return (key < b.first) and qty;
        });
        const auto key_of_top = sorted.front().first;
        return map.find(key_of_top);
      }
    else {
      return std::find_if(map.begin(), map.end(),
                          [](const auto &kv) { return kv.second != 0; });
    }
  };

  typename map_t::key_type top_level = top_of_book(map)->first;

  for (auto _ : state) {
    const auto quantity_at_level = is_remove_level() ? 0 : 1;
    if (is_top_update()) {
      auto top = top_of_book(map);
      top->second = quantity_at_level;
    } else {
      auto &price_level = map[non_top_price_level()];
      price_level = quantity_at_level;
    }
    benchmark::DoNotOptimize(top_level = top_of_book(map)->first);
  }
}

#endif // BOOK_BM_HPP
