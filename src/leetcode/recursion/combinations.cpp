//
// Created by root on 2025/9/13.
//
// 77. 组合 https://leetcode.cn/problems/combinations/
// 题解：递归实现，每个数有两个可能：选或不选，在此基础上去遍历
// 注意：本次题目不需要考虑顺序；本次题目可以进行剪枝优化
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    recur(n, k, 0);
    return ans;
  }

 private:
  vector<vector<int>> ans;
  vector<int> choose;
  void recur(int n, int k, int i) {
    // 剪枝优化
    if (choose.size() > k || n - i + choose.size() < k) {
      return;
    }
    // 选中
    if (choose.size() == k) {
      ans.push_back(choose);
      return;
    }
    // 边界条件
    if (i == n) {
      return;
    }
    choose.push_back(i + 1);
    recur(n, k, i + 1);
    choose.pop_back();
    recur(n, k, i + 1);
  }
};