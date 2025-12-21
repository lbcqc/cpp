//
// Created by root on 2025/9/13.
//
// 46. 全排列 https://leetcode.cn/problems/permutations/description/
// 题解：递归，先在nums中挑选一个数字出来放到第 pos 位，然后在剩余的nums中继续挑选数字放到第 pos+1位，知道选了
// nums.size() 个数字 注意：本题不需要考虑顺序
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    used.resize(nums.size(), false);
    choose.resize(nums.size(), 0);
    recur(nums, 0);
    return ans;
  }

 private:
  vector<vector<int>> ans;
  vector<int> choose;
  vector<bool> used;
  void recur(vector<int>& nums, int pos) {
    if (nums.size() == pos) {
      ans.push_back(choose);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (!used[i]) {
        // 第 pos 个位置选中 i
        choose[pos] = nums[i];
        used[i] = true;
        recur(nums, pos + 1);
        // 第 pos 个位置没选中 i，需要恢复
        used[i] = false;
      }
    }
  }
};