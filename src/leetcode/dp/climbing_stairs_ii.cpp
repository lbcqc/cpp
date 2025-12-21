//
// Created by root on 2025/9/16.
//
// 57. 爬楼梯（第八期模拟笔试）https://kamacoder.com/problempage.php?pid=1067
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int climbStairs(int n, int m) {
    if (n <= 0) {
      return 0;
    }
    vector<int> ans(n + 1, 0);
    ans[0] = 1;
    for (int i = 1; i <= n; i++) {
      int step = min(i, m);
      for (int j = i - step; j < i; j++) {
        ans[i] += ans[j];
      }
    }
    return ans[n];
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  Solution s;
  cout << s.climbStairs(n, m);
}