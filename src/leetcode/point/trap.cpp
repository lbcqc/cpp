//
// Created by root on 2025/9/6.
//
// 42. 接雨水 https://leetcode.cn/problems/trapping-rain-water/solutions/692342/jie-yu-shui-by-leetcode-solution-tuvc/
// 题解：这道题关键是左右两边由于是空的，故而最开始的边界无法接雨滴
// 方案一：从左开始遍历，记录当前最大值，如果当前值小于最大值，代表可以接雨水，但是注意，如果未来没有遇到比最大值更大或想等的值，
// 此时预接的都是空值，不算数；遇到直到结束，还没遇到更大值，则需要从右往回再做一次遍历，直到上一次的最大值下标。
// 方案二：基于方案一的推演，我们发现，整个数组最大值的左右两边，必需要遍历一遍，故而我们可以采用双指针，不断逼近最大值的同时做计算，此时接到的
// 雨滴最终一定是有效的，因为最大值最后比如出现。
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 方案 1：
// class Solution {
// public:
//   int trap(vector<int>& height) {
//     int max = -1;
//     int sum = 0;
//     int tmp = 0;
//     // 正向遍历所有元素
//     int end_index = 0;
//     for (int i = 0; i< height.size(); i++) {
//       if (height[i] >= max) {
//         max = height[i];
//         sum += tmp;
//         tmp = 0;
//         end_index = i;
//       } else {
//         tmp += (max - height[i]);
//       }
//     }
//     // 如果结束则直接返回
//     if (end_index == height.size() - 1) {
//       return sum;
//     }
//     // 反向遍历一次，直到遇到正向遍历时结束的点
//     max = -1;
//     tmp = 0;
//     for (int i = height.size() - 1; i >= end_index; i--) {
//       if (height[i] >= max) {
//         max = height[i];
//         sum += tmp;
//         tmp = 0;
//       } else {
//         tmp += (max - height[i]);
//       }
//     }
//     return sum;
//   }
// };

// 方案二
class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }
    int ans = 0;
    int left = 0;
    int right = height.size() - 1;
    int left_max = height[left];
    int right_max = height[right];
    while (left < right) {
      if (left_max < right_max) {
        left++;
        if (left_max > height[left]) {
          ans += (left_max - height[left]);
        } else {
          left_max = height[left];
        }
      } else {
        right--;
        if (right_max > height[right]) {
          ans += (right_max - height[right]);
        } else {
          right_max = height[right];
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << s.trap(vec);
  return 0;
}