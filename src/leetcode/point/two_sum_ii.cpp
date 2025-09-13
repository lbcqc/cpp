//
// Created by root on 2025/9/13.
//
// 167. 两数之和 II - 输入有序数组 https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
// 题解：左右双指针，如果 left + right > target 则 right --，如果小于则 left ++
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum < target) {
        left++;
        continue;
      }
      if (sum > target) {
        right --;
        continue;
      }
      return {left+1, right+1};
    }
    return {};
  }
};