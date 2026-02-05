//
// Created by root on 2026/2/5.
//
// 128. 最长连续序列 https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=problem-list-v2&envId=2cktkvj
// 题解：使用 hash 表记录元素是否存在，对 C++ 来说，可以使用 unordered_set，通过 insert()和count() 来操作
// 先遍历一遍数组，记录 set 状态
// 再遍历 set(主要是为了去重)，如若这个数的前置数字不存在，即它为开头，即开始遍历连续子数组

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    unordered_set<int> exist;
    for (const int &num : nums) {
      exist.insert(num);
    }
    int max_length = 0;
    for (const int &num : exist) {
      if (!exist.count(num-1)) {
        int cur_num = num;
        int len = 1;
        while(exist.count(cur_num+1)) {
          cur_num++;
          len++;
        }
        if (len > max_length) max_length = len;
      }
    }
    return max_length;
  }
};

int main() {
  Solution s;
  vector<int> nums = {100,4,200,1,3,2};
  cout << s.longestConsecutive(nums) << endl;
  return 0;
}