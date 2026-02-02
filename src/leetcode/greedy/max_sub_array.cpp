//
// Created by root on 2026/2/2.
//
// 最大子数组和 https://leetcode.cn/problems/maximum-subarray/
// 题解：贪心算法，一个数字的最大子序列，只能要么是它自己，要么是它+它前一序列的最优解
// 前一序列的最优解如果为负数，则直接置零，这样即可简化为每个数字的最优解都是它+前一序列的最优解
// 单独一个变量记录全局所有子序列和的最大值即可
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++) {
      sum = sum + nums[i];
      if (sum <= 0) sum = 0;
      ans = max(ans, sum);
    }
    return ans;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout << s.maxSubArray(nums) << endl;
  return 0;
}