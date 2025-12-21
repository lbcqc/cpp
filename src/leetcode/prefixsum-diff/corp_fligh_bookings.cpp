//
// Created by root on 2025/9/7.
//
// 1109. 航班预订统计 https://leetcode.cn/problems/corporate-flight-bookings/description/
// 题解：利用差分思想，将a[i,j]内的统一加减操作，变化为 d[i] d[j] 的加减操作
// 差分：d[0] = a[0]，d[i] = a[i] - a[i-1]，d_s[i] = a[i]
// 利用差分简化区间累加：a[i, j] += n ---> d[i]+=n, d[j+1]-=n
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> d(n + 1, 0);
    for (const auto& booking : bookings) {
      int start = booking[0] - 1;  // 注意，传入的参数是从 1 开始的，需要偏移回来
      int end = booking[1];
      int num = booking[2];
      d[start] += num;
      d[end] -= num;
    }
    vector<int> s(n, 0);
    s[0] = d[0];
    for (int i = 1; i < n; i++) {
      s[i] = s[i - 1] + d[i];
    }
    return s;
  }
};