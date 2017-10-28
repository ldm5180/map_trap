#include "add_to_map.hpp"

#include <benchmark/benchmark.h>
#include <cstdlib>
#include <unordered_map>

using map_t = std::unordered_map<int64_t, int64_t>;

static void BM_unordered_map_insert_sort_iterate(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  map.reserve(state.range(0));
  std::vector<map_t::key_type> keys{};
  keys.reserve(state.range(0));

  for (auto i = 0; i < state.range(0); ++i) {
    add_to_map_and_key_list(state.range(0), map, keys);
  }

  for (auto _ : state) {
    map_t::mapped_type v{};
    for (const auto &k : keys) {
      benchmark::DoNotOptimize(v = map[k]);
    }
  }
}
BENCHMARK(BM_unordered_map_insert_sort_iterate)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 4);
BENCHMARK_MAIN();
