#include <boost/container/flat_map.hpp>
#include <map>
#include <unordered_map>

#include "book_bm.hpp"

BENCHMARK_TEMPLATE(BM_map_book, std::map<int64_t, int64_t>, 100)
    ->Arg(1)
    ->Arg(10)
    ->Arg(20)
    ->Arg(30)
    ->Arg(40)
    ->Arg(50)
    ->Arg(60)
    ->Arg(70)
    ->Arg(80)
    ->Arg(90)
    ->Arg(99);

BENCHMARK_TEMPLATE(BM_map_book, std::unordered_map<int64_t, int64_t>, 100)
    ->Arg(1)
    ->Arg(10)
    ->Arg(20)
    ->Arg(30)
    ->Arg(40)
    ->Arg(50)
    ->Arg(60)
    ->Arg(70)
    ->Arg(80)
    ->Arg(90)
    ->Arg(99);

BENCHMARK_TEMPLATE(BM_map_book, boost::container::flat_map<int64_t, int64_t>,
                   100)
    ->Arg(1)
    ->Arg(10)
    ->Arg(20)
    ->Arg(30)
    ->Arg(40)
    ->Arg(50)
    ->Arg(60)
    ->Arg(70)
    ->Arg(80)
    ->Arg(90)
    ->Arg(99);

BENCHMARK_TEMPLATE(BM_map_book, std::map<int64_t, int64_t>, 65536)
    ->Arg(1)
    ->Arg(10)
    ->Arg(20)
    ->Arg(30)
    ->Arg(40)
    ->Arg(50)
    ->Arg(60)
    ->Arg(70)
    ->Arg(80)
    ->Arg(90)
    ->Arg(99);

BENCHMARK_TEMPLATE(BM_map_book, std::unordered_map<int64_t, int64_t>, 65536)
    ->Arg(1)
    ->Arg(10)
    ->Arg(20)
    ->Arg(30)
    ->Arg(40)
    ->Arg(50)
    ->Arg(60)
    ->Arg(70)
    ->Arg(80)
    ->Arg(90)
    ->Arg(99);

BENCHMARK_TEMPLATE(BM_map_book, boost::container::flat_map<int64_t, int64_t>,
                   65536)
    ->Arg(1)
    ->Arg(10)
    ->Arg(20)
    ->Arg(30)
    ->Arg(40)
    ->Arg(50)
    ->Arg(60)
    ->Arg(70)
    ->Arg(80)
    ->Arg(90)
    ->Arg(99);
BENCHMARK_MAIN();
