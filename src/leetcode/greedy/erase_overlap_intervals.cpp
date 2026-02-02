//
// Created by root on 2026/2/2.
//
// 435. 无重叠区间 https://leetcode.cn/problems/non-overlapping-intervals/description/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  static bool cmp(const vector<int>& a, const vector<int> &b) {
    return a[1] < b[1];
  }
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return 0;
    sort(intervals.begin(), intervals.end(), cmp);
    int end = intervals[0][1];
    int ans = 0;
    for (int i = 1; i < intervals.size(); i++) {
      if (end <= intervals[i][0]) {
        end = intervals[i][1];
      } else {
        ans++;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
  cout << s.eraseOverlapIntervals(intervals) << endl;
  return 0;
}