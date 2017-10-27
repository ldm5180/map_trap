#include "add_to_map.hpp"

#include <benchmark/benchmark.h>
#include <cstdlib>
#include <string>
#include <unordered_map>

using map_t = std::unordered_map<int, std::string>;

static void BM_unordered_map_iterate(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  map.reserve(state.range(0));
  std::vector<map_t::key_type> keys{};
  keys.reserve(state.range(0));

  for (auto i = 0; i < state.range(0); ++i) {
    add_to_map(state.range(0), map);
  }

  for (auto _ : state) {
    keys.clear();
    std::transform(map.begin(), map.end(), std::back_inserter(keys),
                   [](const auto &kv) { return kv.first; });
    std::sort(keys.begin(), keys.end());
    map_t::mapped_type v{};
    for (const auto &k : keys) {
      benchmark::DoNotOptimize(v = map[k]);
    }
  }
}
BENCHMARK(BM_unordered_map_iterate)->RangeMultiplier(2)->Range(8, 8 << 4);

BENCHMARK_MAIN();
