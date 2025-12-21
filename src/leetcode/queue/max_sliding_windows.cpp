//
// Created by root on 2025/9/6.
//
// 239. 滑动窗口最大值 https://leetcode.cn/problems/sliding-window-maximum/submissions/660039774/
// 题解：关键在于要维持窗口内的最大值，当遍历一个新值，将新值和队尾的元素比较，如果队尾元素还比新值小，那将被淘汰，然后将新值插入队尾
// 每次从队列头部取最大值，判断其是否区间有效，如果无效则淘汰，重新取，直到从队头取到最新有效值。
// 关键：单调队列，队列 back -> front 永远维持单调递增，每次新值从 back 开始插入并淘汰旧址值。

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.emplace_back(i);
    }
    ans.push_back(nums[q.front()]);
    for (int i = k; i < nums.size(); i++) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.emplace_back(i);
      while (q.front() <= i - k) {
        q.pop_front();
      }
      ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, -1};
  Solution s;
  auto ans = s.maxSlidingWindow(nums, 1);
  for (auto a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}