#include "generic_map_bm.hpp"

#include <benchmark/benchmark.h>
#include <map>

BENCHMARK_TEMPLATE(BM_map_insert, std::map<int64_t, int64_t>)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 8);
BENCHMARK_MAIN();
