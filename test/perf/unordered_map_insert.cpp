#include "add_to_map.hpp"

#include <benchmark/benchmark.h>
#include <cstdlib>
#include <unordered_map>

using map_t = std::unordered_map<int64_t, int64_t>;

static void BM_unordered_map_insert(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  map.reserve(state.range(0));

  for (auto _ : state) {
    add_to_map(state.range(0), map);
  }
}
BENCHMARK(BM_unordered_map_insert)->RangeMultiplier(2)->Range(8, 8 << 8);

BENCHMARK_MAIN();
