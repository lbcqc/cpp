//
// Created by root on 2025/9/6.
//
// 84. 柱状图中最大的矩形 https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
// 题解：这道题的思路是确定某个柱高其最大的宽，宽*高即为面积，遍历所有柱高的面积计算最大面积；其宽=(left,right]的宽度；
// right 位置为遇到的第一个比其小的位置-1；left为上一个比它小的位置；使用栈来辅助记录，当栈顶为空/栈顶比当前值小时，栈顶
// 即当前值的 left，但是当前值的 right 还未知，当前值的 right
// 一定在未来才能确定，所以比入栈；当遇到栈顶不为空且其值比当前值 小时，当前值即栈顶的
// right，此时将当前值出栈，然后新栈顶的位置为旧栈顶left，计算面积即可。注意当遍历完全部数后，栈不为空，则栈
// 中所有元素的 right = size() - 1；
// 此题为单调栈解法：其栈元素，必须保持单调递增，如果遇到破坏此递增关系的值，弹栈计算并更新结果。
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int max_area = 0;
  stack<int> stk;
  int largestRectangleArea(vector<int>& heights) {
    for (int i = 0; i < heights.size(); i++) {
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        calculateMaxArea(heights, i - 1);
      }
      stk.push(i);
    }
    // 最后处理栈中剩余的值
    while (!stk.empty()) {
      calculateMaxArea(heights, heights.size() - 1);
    }
    return max_area;
  }
  void calculateMaxArea(vector<int>& heights, int right_index) {
    int height = heights[stk.top()];
    stk.pop();
    int left_index = stk.empty() ? -1 : stk.top();
    int width = right_index - left_index;
    max_area = std::max(max_area, width * height);
  }
};

int main(int argc, char** argv) {
  // vector<int> input = {2,1,5,6,2,3};
  vector<int> input = {0, 1, 0, 1};
  Solution s;
  cout << s.largestRectangleArea(input) << endl;
  return 0;
}