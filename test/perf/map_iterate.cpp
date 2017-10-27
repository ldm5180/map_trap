#include "generic_map_bm.hpp"

#include <benchmark/benchmark.h>
#include <map>

BENCHMARK_TEMPLATE(BM_map_iterate, std::map<int, std::string>)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 4);
BENCHMARK_MAIN();
