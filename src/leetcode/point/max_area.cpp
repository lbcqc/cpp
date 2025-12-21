//
// Created by root on 2025/9/13.
//
// 11. 盛最多水的容器 https://leetcode.cn/problems/container-with-most-water/description/
// 题解：双指针，遍历 l r 指针，当前面积为 l r 的最小高度* (r-l)，用一个变量记录遍历过程中的最大面积即可
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int ans = 0;
    while (l < r) {
      ans = max(ans, min(height[l], height[r]) * (r - l));
      if (height[l] <= height[r])
        l++;
      else
        r--;
    }
    return ans;
  }
};