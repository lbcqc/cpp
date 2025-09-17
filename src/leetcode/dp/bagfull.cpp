//
// Created by root on 2025/9/18.
//
// 52. 携带研究材料（第七期模拟笔试） https://kamacoder.com/problempage.php?pid=1052
// 题解：完全背包问题，只需在 01 背包的基础上做修改
// 01背包方程：f(n,w) = max(f(n-1,2), f(n-1, w-weights[n]+values[n]))
// 完全背包方程：f(n,w) = max(f(n-1,2), f(n, w-weights[n]+values[n]))
// 可以看到，只是在选中 n 的时候，还能再选 n，而不是只能从 n-1 里面选
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int goods_num;
  int bag_weight;
  cin >> goods_num >> bag_weight;
  vector<int> goods_weight(goods_num+1, 0);
  vector<int> goods_values(goods_num+1, 0);
  for (int i=1; i <= goods_num; i++) {
    cin >> goods_weight[i] >> goods_values[i];
  }
  vector<vector<int>> dp(goods_num+1, vector<int>(bag_weight+1, 0));
  for (int i = 1; i <=goods_num; i++) {
    for (int j=0; j <= bag_weight; j++ ) {
      if (j < goods_weight[i]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-goods_weight[i]] + goods_values[i]);
    }
  }
  cout << dp[goods_num][bag_weight];
  return 0;
}