#include "add_to_map.hpp"

#include <benchmark/benchmark.h>
#include <cstdlib>
#include <unordered_map>

using map_t = std::unordered_map<int64_t, int64_t>;

static void BM_unordered_map_find(benchmark::State &state) {
  std::srand(42);
  map_t map{};

  for (auto i = 0; i < state.range(0); ++i) {
    add_to_map(state.range(0), map);
  }

  for (auto _ : state) {
    map_t::mapped_type v{};
    benchmark::DoNotOptimize(v = map[std::rand()]);
  }
}
BENCHMARK(BM_unordered_map_find)->RangeMultiplier(2)->Range(8, 8 << 8);
BENCHMARK_MAIN();
