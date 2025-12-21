//
// Created by root on 2025/9/15.
//
// 746. 使用最小花费爬楼梯 https://leetcode.cn/problems/min-cost-climbing-stairs/description/
// 题解：使用 dp，ans[i] = min(ans[i-1]+cost[i-1], ans[i-2]+cost[i-2])
// 注意：由于此处只需要保存过去两个状态，故而无需保存整张表
#include <algorithm>
#include <complex>
#include <vector>
using namespace std;
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int ans_pre_2 = 0;  // ans[i-2]
    int ans_pre_1 = 0;  // ans[i-1]
    int ans = 0;        // ans[i]
    int i = 2;          // 从 2 开始
    for (; i <= cost.size(); i++) {
      ans = min(cost[i - 2] + ans_pre_2, cost[i - 1] + ans_pre_1);
      ans_pre_2 = ans_pre_1;
      ans_pre_1 = ans;
    }
    return ans;
  }
};

class Solution2 {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> ans(cost.size() + 1, 0);
    for (int i = 2; i <= cost.size(); i++) {
      ans[i] = min(cost[i - 2] + ans[i - 2], cost[i - 1] + ans[i - 1]);
    }
    return ans[cost.size()];
  }
};