//
// Created by root on 2025/9/7.
//
// 53. 最大子数组和 https://leetcode.cn/problems/maximum-subarray/
// 题解：S[i] = S[i-1] + nums[i]；如若要找最大的S[l,r] = S[r]-S[l-1]，当 S[r]是固定时，只需 S[l-1]
// 越小越好，故而，我们可以记录 r 前面的最小子序列号 技巧
// 技巧1：子序列和问题，由于没有任何数字也算一个序列，为处理这个边界，i 从 1 开始更方便
// 技巧2：ans 要使用最小数字开始
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> s(n + 1, 0);
    int min = 0;
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + nums[i - 1];
      ans = std::max(ans, s[i] - min);
      min = std::min(min, s[i]);
    }
    return ans;
  }
};