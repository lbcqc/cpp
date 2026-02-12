//
// Created by root on 2026/2/12.
//
// 200. 岛屿数量 https://leetcode.cn/problems/number-of-islands/description/?envType=problem-list-v2&envId=2cktkvj
// 题解：深度优先搜索/贪心，找到一个'1'后，遍历其四周所有'1'，将其消除/收归到第一个'1'，这样岛屿重复计数

#include <vector>
#include <iostream>
using namespace  std;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          ans++;
          fixGrid(grid, i, j);
        }
      }
    }
    return ans;
  }
  void fixGrid(vector<vector<char>>& grid, int i, int j) {
    if (i>=grid.size() || i< 0 || j >= grid[i].size() || j <0) {
      return;
    }
    if (grid[i][j] == '1') {
      grid[i][j] = '0';
      fixGrid(grid, i, j+1);
      fixGrid(grid, i, j-1);
      fixGrid(grid, i+1, j);
      fixGrid(grid, i-1, j);
    }
    return;
  }
};

int main() {
  Solution s;
  vector<vector<char>> grid = {
    {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'},
  };
  cout << s.numIslands(grid) << endl;
}