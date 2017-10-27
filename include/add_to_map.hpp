#ifndef ADD_TO_MAP_HPP
#define ADD_TO_MAP_HPP

#include <algorithm>
#include <benchmark/benchmark.h>
#include <cstdlib>
#include <string>

static const auto add_to_map = [](const auto num_elems, auto &map) {
  // Add elements to map, this sorts automatically.
  for (auto i = 0; i < num_elems; ++i) {
    const auto random_key = std::rand();
    map[random_key] = std::to_string(map.size());
  }
  benchmark::ClobberMemory();
};

static const auto add_to_map_and_key_list = [](const auto num_elems, auto &map,
                                               auto &keys) {
  // Add elements to map, this sorts automatically.
  for (auto i = 0; i < num_elems; ++i) {
    const auto random_key = std::rand();
    map[random_key] = std::to_string(map.size());
    keys.push_back(random_key);
    std::sort(keys.begin(), keys.end());
  }
  benchmark::ClobberMemory();
};

#endif // ADD_TO_MAP_HPP
