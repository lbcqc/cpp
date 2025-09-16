//
// Created by root on 2025/9/16.
//
// 70. 爬楼梯 https://leetcode.cn/problems/climbing-stairs/description/
// 题解：动态规划，第 n 阶楼梯的爬法 f(n) = f(n-1) + f(n-2)
// 注意：当 n=1/2 的时候，n-1和 n-2将导致 dp 数组越界，这类边界值，可以直接硬编码简化代码
// 优化：由于只需要保存前两个数，无需 dp 数组，故而直接使用两个变量 dp1 dp2 即可
#include <iostream>
using namespace std;
class Solution {
public:
  int climbStairs(int n) {
    int dp1 = 1;
    int dp2 = 2;
    if (n == 1) {
      return dp1;
    }
    if (n == 2) {
      return dp2;
    }
    for (int i = 3; i <= n; i++) {
      int dp3 = dp2 + dp1;
      dp1 = dp2;
      dp2 = dp3;
    }
    return dp2;
  }
};