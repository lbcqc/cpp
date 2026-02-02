//
// Created by root on 2025/9/13.
//
// [1. 两数之和](https://leetcode.cn/problems/two-sum/description/)
// 题解 1：使用 x + y = target, y = target-x, 只需要使用 Hash 来记录过往x的信息，每次遍历时去寻找 target-x 是否存在即可。O(n)
// 题解 2：先排序，再使用左右双指针进行遍历，如果 l + r > target，那么缩小 r，如果 < target，那么增大 l。O(nlogn)
#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// 题解 1
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> index;
    for (int i = 0; i < nums.size(); i++) {
      int need = target - nums[i];
      const auto it = index.find(need);
      if (it != index.end()) {
        return {it->second, i};
      }
      index[nums[i]] = i;
    }
    return {};
  }
};

// 题解 2
class Solution2 {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> index;
    for (int i = 0; i < nums.size(); i++) {
      index.push_back({nums[i], i});
    }
    sort(index.begin(), index.end());
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int sum = index[left].first + index[right].first;
      if (sum < target) {
        left++;
        continue;
      }
      if (sum > target) {
        right--;
        continue;
      }
      return {index[left].second, index[right].second};
    }
    return {};
  }
};