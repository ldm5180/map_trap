#ifndef INSERT_BM_HPP
#define INSERT_BM_HPP

#include "add_to_map.hpp"

#include <boost/hana.hpp>

static constexpr auto has_reserve =
    boost::hana::is_valid([](auto &&x) -> decltype((void)x.reserve(0)) {});

template <class map_t, bool presort = false>
static void BM_map_insert(benchmark::State &state) {
  std::srand(42);
  map_t map{};
  std::vector<typename map_t::key_type> keys{};

  if
    constexpr(has_reserve(map)) { map.reserve(state.range(0)); }

  constexpr auto is_unordered = std::is_same<
      std::unordered_map<typename map_t::key_type, typename map_t::mapped_type>,
      map_t>::value;

  if
    constexpr(is_unordered) { keys.reserve(state.range(0)); }

  for (auto _ : state) {
    map.clear();
    if
      constexpr(is_unordered) {
        keys.clear();
        add_to_map_and_key_list(state.range(0), map, keys, presort);
      }
    else {
      add_to_map(state.range(0), map);
    }
  }
}

#endif // INSERT_BM_HPP
