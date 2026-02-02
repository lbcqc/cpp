//
// Created by root on 2026/2/2.
//
// 376. 摆动序列 https://leetcode.cn/problems/wiggle-subsequence/description/
// 题解：贪心算法，局部最优解就是全局最优解
// 只需要记录当前方向，和当前方向的最新一个值，如若新值能扭转方向，则更新记录，
// 如若新值不能扭转方向，说明其使得该方向往更深处延展了，方向不变，但是值更新

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    int prefix = nums[0];
    int flag = 0; // 方向
    int ans = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (flag == 1 && nums[i]<prefix) {
        flag *= -1;
        ans++;
      }
      if (flag == -1 && nums[i]>prefix) {
        flag *= -1;
        ans++;
      }
      if (flag == 0) {
        if (nums[i] < prefix) {
          ans++;
          flag = -1;
        }
        if (nums[i] > prefix) {
          ans++;
          flag = 1;
        }
      }
      prefix = nums[i];
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {3,2,3};
  cout << s.wiggleMaxLength(nums) << endl;
  return 0;
}