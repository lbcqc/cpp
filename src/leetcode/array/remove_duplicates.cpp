//
// Created by root on 5/9/24.
//
// 26. 删除有序数组中的重复项 https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//
// 题解：使用快慢指针，快指针遍历数组，慢指针记录不重复的元素
// 快指针遇到不重复的元素，则将快指针的元素赋值给慢指针的下一个元素
// 最后返回慢指针的下一个元素，即为不重复元素的个数
// 注意：最后需要将数组resize为不重复元素的个数

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
    nums.resize(index + 1);
    return nums.size();
  }
};

int main(int argc, char** argv) {
  Solution s;
  vector<int> input = {1, 1, 2};
  int len = s.removeDuplicates(input);
  spdlog::info("len: {}, output: {}", len, input);
  return 0;
}