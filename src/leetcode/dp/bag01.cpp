//
// Created by root on 2025/9/17.
//
// 46. 携带研究材料（第六期模拟笔试）https://kamacoder.com/problempage.php?pid=1046
// 题解：01背包问题，可以按物品和重量进行遍历，当遍历到第 n 个物品第 w 容量时，f(n,w) = max(f(n-1,w-weight[n])+value[n], f(n-1,w))
// 即第 n个物品只有两种状态：选 or 不选
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int num;
  int bag_weight;
  cin >> num >> bag_weight;
  vector<int> weights(num+1, 0); // 货物重量
  vector<int> values(num+1, 0); // 货物价值
  for (int i = 1; i <= num; i++) {
    cin >> weights[i];
  }
  for (int i = 1; i <= num; i++) {
    cin >> values[i];
  }
  vector<vector<int>> dp(num+1, vector<int>(bag_weight+1, 0));
  for (int i = 1; i <= num; i++) {
    for (int j = 0; j <= bag_weight; j++) {
      if (j < weights[i]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]]+values[i]);
    }
  }
  cout << dp[num][bag_weight];
}