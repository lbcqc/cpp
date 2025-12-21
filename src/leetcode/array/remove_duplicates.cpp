//
// Created by root on 5/9/24.
//
// 26. 删除有序数组中的重复项 https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//

#include <iostream>
#include <vector>

#include "spdlog/fmt/ranges.h"
#include "spdlog/spdlog.h"

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int index = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[index]) {
        nums[++index] = nums[i];
      }
    }
    return index + 1;
  }
};

int main(int argc, char** argv) {
  Solution s;
  vector<int> input = {1, 1, 2};
  int len = s.removeDuplicates(input);
  spdlog::info("len: {}, output: {}", len, input);
  return 0;
}