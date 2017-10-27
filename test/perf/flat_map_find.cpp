#include "generic_map_bm.hpp"

#include <benchmark/benchmark.h>
#include <boost/container/flat_map.hpp>

BENCHMARK_TEMPLATE(BM_map_find, boost::container::flat_map<int, std::string>)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 4);
BENCHMARK_MAIN();
