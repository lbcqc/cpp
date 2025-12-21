//
// Created by root on 2025/9/13.
//
// 15. 三数之和 https://leetcode.cn/problems/3sum/description/
// 题解：先排序，然后固定 i，就变成了找两数 j k 的和为-nums[i]
// 关键点：需要注意不包含重复的结果，这只需在遍历 i j 时均确保其不和前一个相同即可
// nums[k] = -(nums[i]+nums[j])，当 i j 均不想等时，k不可能相等，故而 k 无需特意去重
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      twoSum(ans, nums, i);
    }
    return ans;
  }
  void twoSum(vector<vector<int>>& ans, const vector<int>& nums, int i) {
    int k = nums.size() - 1;
    int target = -nums[i];
    for (int j = i + 1; j < k; j++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) continue;
      while (j < k && nums[j] + nums[k] > target) k--;
      if (j < k && nums[j] + nums[k] == target) {
        ans.push_back({nums[i], nums[j], nums[k]});
      }
    }
  }
};