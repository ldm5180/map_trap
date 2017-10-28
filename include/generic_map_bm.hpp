#ifndef GENERIC_MAP_BM_HPP
#define GENERIC_MAP_BM_HPP

#include "add_to_map.hpp"

#include <boost/hana.hpp>
#include <cstdlib>

static constexpr auto has_reserve =
    boost::hana::is_valid([](auto &&x) -> decltype((void)x.reserve(0)) {});

template <class map_t> static void BM_map_insert(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  if
    constexpr(has_reserve(map)) { map.reserve(state.range(0)); }

  for (auto _ : state) {
    add_to_map(state.range(0), map);
  }
}

template <class map_t> static void BM_map_iterate(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  if
    constexpr(has_reserve(map)) { map.reserve(state.range(0)); }

  for (auto i = 0; i < state.range(0); ++i) {
    add_to_map(state.range(0), map);
  }

  for (auto _ : state) {
    // Nothing to do to sort them. Can simply iterate.
    typename map_t::mapped_type v{};
    for (const auto &kv : map) {
      benchmark::DoNotOptimize(v = kv.second);
    }
  }
}

template <class map_t> static void BM_map_find(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  if
    constexpr(has_reserve(map)) { map.reserve(state.range(0)); }
  std::vector<typename map_t::key_type> keys{};
  keys.reserve(state.range(0));

  for (auto i = 0; i < state.range(0); ++i) {
    add_to_map_and_key_list(state.range(0), map, keys);
  }

  for (auto _ : state) {
    typename map_t::mapped_type v{};
    const auto key = keys[std::rand() % keys.size()];
    benchmark::DoNotOptimize(v = map[key]);
  }
}

#endif // GENERIC_MAP_BM_HPP
