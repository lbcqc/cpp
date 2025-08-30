// https://leetcode.cn/problems/plus-one/
//
// Created by root on 2025/8/30.
//
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