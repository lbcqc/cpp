//
// Created by root on 2026/2/3.
//
// 划分字母区间：https://programmercarl.com/0763.%E5%88%92%E5%88%86%E5%AD%97%E6%AF%8D%E5%8C%BA%E9%97%B4.html#%E6%80%9D%E8%B7%AF
// 题解：贪心算法，本质上是从第一个字符开始遍历，找他的闭区间，然后再这个区间内遍历时刷新闭区间的位置
// 先要先遍历一次构建字符闭区间的映射

#include <vector>
#include <unordered_map>
#include <string>
#include "spdlog/fmt/ranges.h"
#include "spdlog/spdlog.h"

using namespace std;

class Solution {
public:
  vector<int> partitionLabels(const string& s) {
    if (s.empty()) return {};
    vector<int> ans = {};
    unordered_map<char, int> index = {};
    for (int i = 0; i < s.length(); i++) {
      index[s[i]] = i;
    }
    int left = 0;
    int right = -1;
    for (int i = 0; i < s.length(); i++) {
      if (right == -1) {
        left = i;
        right = index[s[i]];
      }
      if (i == right) {
        ans.push_back(right-left+1);
        right = -1;
        continue;
      }
      if (index[s[i]] > right) {
        right = index[s[i]];
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  auto ans = s.partitionLabels("ababcbacadefegdehijhklij");
  spdlog::info("{}", ans);
}