//
// Created by root on 2025/9/7.
//
// 304. 二维区域和检索 - 矩阵不可变 https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
// 题解：需要先初始化前缀和 S[i][j] = nums[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1]；
// S[row1][col1],S[row2][col2] = S[row2][col2] - S[row1-1][col2] - S[row2][col1-1] + S[row1-1][col1-1]
// 技巧 1：所有前缀和相关的问题，i都从 1 开始，这样才方便处理 S[0][0] 的边界值
// 技巧 2：需要特别注意，S[row1][col1],S[row2][col2]其实是把 row-1和 col-1开始的区域做叠加剔除
#include <vector>
using namespace std;
class NumMatrix {
 public:
  vector<vector<int>> s;
  NumMatrix(vector<vector<int>>& matrix) {
    int col = matrix.size();
    int row = matrix[0].size();
    s = vector<vector<int>>(col + 1, vector<int>(row + 1, 0));

    for (int i = 1; i <= col; i++) {
      for (int j = 1; j <= row; j++) {
        s[i][j] = matrix[i - 1][j - 1] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    // 下标从 1 开始，所以需要做偏移，注意，在计算剔除时，不能包含row1 col1，故而正好不偏移
    row2++;
    col2++;
    return s[row2][col2] - s[row1][col2] - s[row2][col1] + s[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */