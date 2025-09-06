//
// Created by root on 2025/9/6.
//
// 最大矩形 https://leetcode.cn/problems/maximal-rectangle/description/
// 题解：这道题非常难！它需要先给每一行统计其累计宽度，然后基于每一列去计算最大柱状图面积
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return 0;
    }
    int ans = 0;
    vector<vector<int>> heights(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == '1') {
          heights[i][j] = j==0? 1:heights[i][j-1]+1;
        }
      }
    }
    for (int j = 0; j < matrix[0].size(); j++) {
      stack<int> stk;
      for (int i = 0; i< matrix.size(); i++) {
        while (!stk.empty() && heights[stk.top()][j] > heights[i][j]) {
          int height = heights[stk.top()][j];
          stk.pop();
          int width = stk.empty()? i:i-stk.top()-1;
          ans = ans > height*width? ans:height*width;
        }
        stk.push(i);
      }
      while (!stk.empty()) {
        int height = heights[stk.top()][j];
        stk.pop();
        int width = stk.empty()? matrix.size():matrix.size()-stk.top()-1;
        ans = ans > height*width? ans:height*width;
      }
    }
    return ans;
  }
};