//
// Created by root on 5/9/24.
//
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int width;
  int height;
  Node(): width(0),height(0){};
  Node(int _width, int _height): width(_width),height(_height){};
  int Area(){return width*height;};
};

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int size = heights.size();
    int max = 0;
    vector result(size, vector<Node>(size));
    // 初始化长度为 1 时的结果
    for (int i = 0; i < size; i++) {
      result[i][0] = Node(1, heights[i]);
      max = max>heights[i]? max:heights[i];
    }
    for (int len = 1; len < size; len++) {
      for (int i = len; i < size; i++) {
        // [i-len, i] = [i-len-1] + [i]
        Node a(1, heights[i]);
        Node b = result[i-1][len-1];
        // 计算 a+b
        int min_height = a.height<b.height? a.height:b.height;
        int max_width = a.width + b.width;
        result[i][len] = Node(max_width, min_height);
        // 计算最大值
        max = max>result[i][len].Area()? max:result[i][len].Area();
      }
    }
    return max;
  }
};

int main(int argc, char **argv) {
  vector<int> input = {2,1,5,6,2,3};
  Solution s;
  cout << s.largestRectangleArea(input) << endl;
  return 0;
}