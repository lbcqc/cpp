//
// Created by root on 2026/2/2.
//
// 最小会议室：https://zhuanlan.zhihu.com/p/690215895
// 题解：贪心+最小值堆，只需要按开始时间对会议进行排序，从最早的会议开始安排，先检查已安排的会议室（按结束时间排序的最小值堆）有没有可复用的，
// 可复用：新会议开始时间大于已安排会议室的释放时间，则弹出旧安排的时间，插入新的

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  static bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
  }
  int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), cmp);
    priority_queue<int> minHeap = {};
    minHeap.push(intervals[0][1]);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] >= minHeap.top()) {
        minHeap.pop();
      }
      minHeap.push(intervals[i][1]);
    }
    return minHeap.size();
  }
};

int main() {
  Solution s;
  vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
  cout << s.minMeetingRooms(intervals) << endl;
  return 0;
}