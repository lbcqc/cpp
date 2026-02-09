//
// Created by root on 2026/2/8.
//
// 215. 数组中的第K个最大元素
// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/?envType=problem-list-v2&envId=2cktkvj

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// class Solution {
// public:
//   int findKthLargest(vector<int>& nums, int k) {
//     priority_queue<int, vector<int>, less<int>> max_heap;
//     for (const auto & num : nums) {
//       max_heap.push(num);
//     }
//     while(--k) {
//       max_heap.pop();
//     }
//     return max_heap.top();
//   }
// };

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    return findKthLargestImpl(nums,0, nums.size()-1, nums.size() - k);
  }
private:
  int findKthLargestImpl(vector<int>& nums, int l, int r, int k) {
    if (l == r) return nums[k];
    int l_tmp = l;
    int r_tmp = r;
    int partition = nums[l];
    while (l < r) {
      while (nums[l] < partition) l++;
      while (nums[r] > partition) r--;
      if (l < r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
      }
    }
    if (k <= l) {
      return findKthLargestImpl(nums, l_tmp, l, k);
    }
    return findKthLargestImpl(nums, l+1, r_tmp, k);
  }
};


int main() {
  Solution s;
  vector<int> nums = {3,2,1,5,6,4};
  int k = 2;
  cout << s.findKthLargest(nums, k) << endl;
}