//
// Created by root on 2025/9/6.
//
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // 最小值堆
    priority_queue<pair<int, int>> max_heap; // 最大值堆
    for (int i = 0; i <k; i ++) {
      max_heap.emplace(nums[i], i);
    }
    vector<int> ans = {};
    ans.emplace_back(max_heap.top().first);
    for (int i = k; i < nums.size(); i++) {
      max_heap.emplace(nums[i], i);
      while (max_heap.top().second <= i-k) {
        max_heap.pop();
      }
      ans.emplace_back(max_heap.top().first);
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  Solution s;
  auto ans  = s.maxSlidingWindow(nums, 3);
  for (auto a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}