// https://leetcode.cn/problems/plus-one/
//
// Created by root on 2025/8/30.
//
// 66. 加一 https://leetcode.cn/problems/plus-one/description/
// 题解：从后往前遍历，如果当前位是 9，则进位，否则直接返回
// 如果最后需要进一位，则插入 1 到最前面
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    for (auto it = digits.rbegin(); it != digits.rend(); it++) {
      *it += 1;
      if (*it == 10) {
        *it = 0;
      } else {
        return digits;
      }
    }
    // 如果最后需要进一位
    digits.insert(digits.begin(), 1);
    return digits;
  }
};