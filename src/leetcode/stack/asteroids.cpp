//
// Created by root on 2026/2/1.
//
// 735. 小行星碰撞 https://leetcode.cn/problems/asteroid-collision/description/
// 题解：只用栈来模拟小行星碰撞，遇到正数入栈，入到负数则和栈顶做对抗，直到该负数将所有栈顶的正数消灭，或者它自己被消灭，最终栈结果即使存活行星
#include <stack>
#include <iostream>
#include <vector>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ranges.h"

using namespace std;

class Solution {
public:
  vector<int> crash(vector<int> asters) {
    vector<int> ans;
    for (int i = 0; i < asters.size(); ++i) {
      if (ans.empty() || asters[i] > 0) {
        ans.push_back(asters[i]);
        continue;
      }
      // 小行星碰撞
      bool alive = true;
      while (!ans.empty() && ans.back() > 0) {
        int ret = ans.back() + asters[i];
        if (ret == 0) {
          ans.pop_back();
          alive = false;
          break;
        }
        if (ret > 0) {
          alive = false;
          break;
        }
        ans.pop_back();
      }
      if (alive) {
        ans.push_back(asters[i]);
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> asters = {3,5,-6,2,-1,4};
  vector<int> ans = s.crash(asters);
  spdlog::info("{}", ans);
  return 0;
}