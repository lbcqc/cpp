#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

#include "spdlog/fmt/ranges.h"
#include "spdlog/spdlog.h"

int main() {
  std::list<int> l = {1, 2, 3, 4, 5};
  std::_List_iterator<int> a2 = find(l.begin(), l.end(), 2);
  std::_List_iterator<int> a4 = find(l.begin(), l.end(), 4);
  for (auto it = a2; it != a4; it++) {
    spdlog::info("{}->", *it);
  }
  return 0;
}