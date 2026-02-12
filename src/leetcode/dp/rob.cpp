//
// Created by root on 2026/2/12.
//
// 198. 打家劫舍 https://leetcode.cn/problems/house-robber/description/?envType=problem-list-v2&envId=2cktkvj

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    vector<int> dp(nums.size() + 2, 0);
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      dp[i+2] = max(dp[i]+ nums[i], dp[i+1]);
      ans = max(dp[i+2], ans);
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1,2,3,1};
  cout << s.rob(nums) << endl;
}
