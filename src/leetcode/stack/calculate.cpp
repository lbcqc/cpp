//
// Created by root on 2025/9/1.
//
// https://leetcode.cn/problems/basic-calculator/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 这道题关键在于只有 + -运算符，由于-运算符也可以认为是+上(-1*num)，故而这就是一个纯加法运算
// 但是要注意，当-出现在(前面时，其意味着括号内的数字全部要乘上-1。这是这道题的难点。
// 解法：只需要遇到(时，将-1 +1入栈，遇到)时将栈顶的+1 -1出栈，然后每次遇到数字，就取栈顶符号*当前符号*当前数字做累加，得到最终的结果
// 特别注意：虽然题目保证每个数字和结果都在 int32 范围内，但是表达式的中间结果，可能会超 int32，故而需要 Long 来保存中间结果
// 特别注意：sign是当前符号，需要作用域符号*当前符号，即遇到+则为栈顶，遇到-则为-栈顶。

class Solution {
public:
  int calculate(string s) {
    stack<int> stk;
    int sum = 0;
    int sign = 1;
    stk.push(sign);
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case '+':
          sign = stk.top();
          break;
        case '-':
          sign = -stk.top();
          break;
        case '(':
          stk.push(sign);
          break;
        case ')':
          stk.pop();
          break;
        case ' ':
          break;
        default:
          long num = 0;
          for (; i<s.size() && '0' <= s[i] && s[i] <= '9'; i++) {
            num = num *10 + s[i] - '0';
          }
          i--; // while循环多遍历了一次，需要回退
          sum += sign*int(num);
          break;
      }
    }
    return sum;
  }
};

int main() {
  string str = "1-(     -2)";
  Solution s;
  std::cout << s.calculate(str) << std::endl;
  return 0;
}