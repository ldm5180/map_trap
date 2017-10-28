#ifndef FIND_BM_HPP
#define FIND_BM_HPP

#include "add_to_map.hpp"
#include <cstdlib>

template <class map_t> static void BM_map_find(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  std::vector<typename map_t::key_type> keys{};
  add_to_map_and_key_list(state.range(0), map, keys);

  for (auto _ : state) {
    typename map_t::mapped_type v{};
    const auto key = keys[std::rand() % keys.size()];
    benchmark::DoNotOptimize(v = map[key]);
  }
}

#endif // FIND_BM_HPP
