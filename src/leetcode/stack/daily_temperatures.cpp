//
// Created by root on 2026/2/8.
//
// 739. 每日温度 https://leetcode.cn/problems/daily-temperatures/description/?envType=problem-list-v2&envId=2cktkvj
// 题解：单调栈，每个元素对应的下一个最大元素需要在后续才能知道，故而均需将当前元素入栈，下一个元素出现时，和栈顶对比，看是否为更大元素
// 是的话出栈，记录结果，最后遍历结束还在栈中没结果的，结果为 0

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    if (temperatures.empty()) return {};
    stack<int> st;
    vector<int> ans(temperatures.size());
    for(int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[i]> temperatures[st.top()]) {
        ans[st.top()] = i-st.top();
        st.pop();
      }
      st.push(i);
    }
    while(!st.empty()) {
      ans[st.top()] = 0;
      st.pop();
    }
    return ans;
  }
};