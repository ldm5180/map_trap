#ifndef ITERATE_BM_HPP
#define ITERATE_BM_HPP

#include "add_to_map.hpp"
#include <cstdlib>

template <class map_t, bool presort = false>
static void BM_map_iterate(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  std::vector<typename map_t::key_type> keys{};

  constexpr auto is_unordered = std::is_same<
      std::unordered_map<typename map_t::key_type, typename map_t::mapped_type>,
      map_t>::value;

  if
    constexpr(is_unordered) {
      add_to_map_and_key_list(state.range(0), map, keys, presort);
    }
  else {
    add_to_map(state.range(0), map);
  }

  constexpr auto needs_sorting = is_unordered and not presort;

  for (auto _ : state) {
    if
      constexpr(needs_sorting) {
        keys.clear();
        std::transform(map.begin(), map.end(), std::back_inserter(keys),
                       [](const auto &kv) { return kv.first; });
        std::sort(keys.begin(), keys.end());
      }

    if
      constexpr(is_unordered) {
        typename map_t::mapped_type v{};
        for (const auto &k : keys) {
          benchmark::DoNotOptimize(v = map[k]);
        }
      }
    else {
      typename map_t::mapped_type v{};
      for (const auto &kv : map) {
        benchmark::DoNotOptimize(v = kv.second);
      }
    }
  }
}

#endif // ITERATE_BM_HPP
