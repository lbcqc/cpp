#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
#include "fmt/ranges.h"

int main() {
  std::vector<int> nums = {2, 2, 2};
  int target = 4;
  std::map<int, std::vector<int>> m;
  std::vector<std::vector<int>> ans;
  for (int i = 0; i < nums.size(); i++) {
    // 查找匹配
    int match_value = target - nums[i];
    if (m.find(match_value) != m.end()) {
      auto match_indexs = m[match_value];
      for (auto match_index : match_indexs) {
        std::vector<int> tmp = {match_index, i};
        ans.push_back(tmp);
      }
    }
    // 入map
    m[nums[i]].push_back(i);
    // if (m.find(nums[i]) != m.end()) {
    //
    // } else {
    //   m[nums[i]] = std::vector<int>(i);
    // }
  }
  fmt::print("ans: {}", ans);
  return 0;
}