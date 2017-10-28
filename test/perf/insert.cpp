#include <benchmark/benchmark.h>

#include <boost/container/flat_map.hpp>
#include <map>
#include <unordered_map>

#include "common.hpp"
#include "insert_bm.hpp"

BENCHMARK_TEMPLATE(BM_map_insert, std::map<int64_t, int64_t>)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_TEMPLATE(BM_map_insert, std::unordered_map<int64_t, int64_t>,
                   ondemand_sort)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_TEMPLATE(BM_map_insert, std::unordered_map<int64_t, int64_t>, presort)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_TEMPLATE(BM_map_insert, boost::container::flat_map<int64_t, int64_t>)
    ->RangeMultiplier(multiplier)
    ->Range(multiplier, multiplier << scaler);
BENCHMARK_MAIN();
