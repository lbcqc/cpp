//
// Created by root on 2026/2/8.
//
// 221. 最大正方形  https://leetcode.cn/problems/maximal-square/description/?envType=problem-list-v2&envId=2cktkvj
// 题解：动态规划，if nums[i][j] == '1' then dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
    int ans = 0;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == '0') {
          dp[i+1][j+1] = 0;
          continue;
        }
        dp[i+1][j+1] = min(min(dp[i][j], dp[i][j+1]), dp[i+1][j]) + 1;
        ans = max(ans, dp[i+1][j+1]);
      }
    }
    return ans*ans;
  }
};

int main() {
  Solution s;
  // vector<vector<char>> matrix{
  //   {'1','0','1','0','0'},
  //   {'1','0','1','1','1'},
  //   {'1','1','1','1','1'},
  //   {'1','0','0','1','0'},
  // };
  vector<vector<char>> matrix{
    {'0', '1'}
  };
  cout << s.maximalSquare(matrix) << endl;
  return 0;
}