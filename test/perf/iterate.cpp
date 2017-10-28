#include <benchmark/benchmark.h>

#include <boost/container/flat_map.hpp>
#include <map>
#include <unordered_map>

#include "common.hpp"
#include "iterate_bm.hpp"

BENCHMARK_TEMPLATE(BM_map_iterate, std::map<int64_t, int64_t>)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_TEMPLATE(BM_map_iterate, std::unordered_map<int64_t, int64_t>,
                   ondemand_sort)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_TEMPLATE(BM_map_iterate, std::unordered_map<int64_t, int64_t>,
                   presort)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_TEMPLATE(BM_map_iterate, boost::container::flat_map<int64_t, int64_t>)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);

BENCHMARK_MAIN();
