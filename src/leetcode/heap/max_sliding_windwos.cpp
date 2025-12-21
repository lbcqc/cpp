//
// Created by root on 2025/9/6.
//
// 最大滑动窗口：[239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/description/)
// 解法：利用最大值堆维护窗口内的最大值，注意，要考虑堆内最大值有效期仅在窗口内，超出窗口的最大值要立即出堆
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#include "fmt/ranges.h"

class Solution {
 public:
  std::vector<int> maxSlidingWindows(std::vector<int> nums, int k) {
    if (k <= 1 || nums.empty()) return nums;
    std::vector<int> output(nums.size() - k + 1, 0);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<>> max_heap;
    for (int i = 0; i < k - 1; i++) {
      max_heap.emplace(nums[i], i);
      // max_heap.push(std::make_pair(nums[i], i));
    }
    for (int i = k - 1; i < nums.size(); i++) {
      max_heap.emplace(nums[i], i);
      while (max_heap.top().second < i - k) {
        max_heap.pop();
      }
      output[i - k + 1] = max_heap.top().first;
    }
    return output;
  }
};

int main() {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution s;
  auto output = s.maxSlidingWindows(nums, k);
  fmt::print("inputs: {}\n", nums);
  fmt::print("outputs: {}\n", output);
  return 0;
}