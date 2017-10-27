#include "add_to_map.hpp"

#include <benchmark/benchmark.h>
#include <cstdlib>
#include <string>
#include <unordered_map>

using map_t = std::unordered_map<int, std::string>;

static void BM_unordered_map_insert_sort(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  map.reserve(state.range(0));
  std::vector<map_t::key_type> keys{};
  keys.reserve(state.range(0));

  for (auto _ : state) {
    add_to_map_and_key_list(state.range(0), map, keys);
  }
}
BENCHMARK(BM_unordered_map_insert_sort)->RangeMultiplier(2)->Range(8, 8 << 8);
BENCHMARK_MAIN();
