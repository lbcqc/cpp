//
// Created by root on 2025/9/13.
//
// 78. 子集 https://leetcode.cn/problems/subsets/description/
// 题解：递归思路，遍历所有数，每个数都有选和不选两种可能
// 注意：此题无需考虑子集顺序
#include <vector>
using namespace  std;
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    recur(nums, 0);
    return ans;
  }
private:
  vector<vector<int>> ans;
  vector<int> choose;
  void recur(const vector<int>& nums, int i) {
    // 递归边界条件
    if (i >= nums.size()) {
      ans.push_back(choose);
      return;
    }

    // 选择 nums[i]
    choose.push_back(nums[i]);
    recur(nums, i+1);
    // 不选 nums[i]，并还原现场
    choose.pop_back();
    recur(nums, i+1);
  }
};