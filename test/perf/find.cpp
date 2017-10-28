#include <benchmark/benchmark.h>

#include <boost/container/flat_map.hpp>
#include <map>
#include <unordered_map>

#include "common.hpp"
#include "find_bm.hpp"

BENCHMARK_TEMPLATE(BM_map_find, std::map<int64_t, int64_t>)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_TEMPLATE(BM_map_find, std::unordered_map<int64_t, int64_t>)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_TEMPLATE(BM_map_find, boost::container::flat_map<int64_t, int64_t>)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_MAIN();
