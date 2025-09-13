//
// Created by root on 2025/9/13.
//
// 77. 组合 https://leetcode.cn/problems/combinations/
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    recur(n,k,0);
    return ans;
  }

 private:
  vector<vector<int>> ans;
  vector<int> choose;
  void recur(int n, int k, int i) {
    if (choose.size() == k) {
      ans.push_back(choose);
      return;
    }
    if (i == n) {
      return;
    }
    choose.push_back(i+1);
    recur(n, k, i + 1);
    choose.pop_back();
    recur(n, k, i + 1);
  }
};