//
// Created by root on 2026/2/1.
//
// 基本计算器 iii: https://leetcode.com/problems/basic-calculator-iii/
// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。s 由数字、'+'、'-'、'('、')'、 ' '、'*'、'/' 组成
// 该题核心在于：
// ① 解析字符串，对各类字符分别做处理
// ② +和-可以通过栈来做延迟处理，因为表达式优先级的原因，其无法直接计算答案
// ③ */可以直接和栈顶做计算后替换栈顶的值
// ④ 触发计算的时机在于遇到计算符号(+-*/))，如若字符串已结束但是当前数字不为空，也应该触发计算。
// ⑤ 最后只需要将栈里的值全部相加即可，记得负数入栈时直接标记为负数
// ⑥ 这里可能有临时变量溢出问题，可以使用 long long 来存储

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    if (s.empty()) return 0;
    int pos = 0;
    return calculateImpl(s.c_str(), s.length(), pos);
  }
private:
  int calculateImpl(const char *str, const size_t len, int &pos) {
    stack<int> stk;
    int num = 0;
    char sign = '+';
    for (; pos < len; pos++) {
      if (str[pos] == '+' || str[pos] == '-' || str[pos] == '/' || str[pos] == '*') {
        applyOperator(stk, sign, num);
        sign = str[pos];
        num = 0;
        continue;
      }
      if (str[pos] == ')') {
        applyOperator(stk, sign, num);
        num = 0;
        break;
      }
      if (str[pos] == '(') {
        pos++;
        num = calculateImpl(str, len, pos);
      }
      if (str[pos]>='0' && str[pos]<='9') {
        num = num*10 + str[pos] - '0';
      }
    }
    if (num != 0) {
      applyOperator(stk, sign, num);
    }
    int result = 0;
    while (!stk.empty()) {
      result += stk.top();
      stk.pop();
    }
    return result;
  }
  void applyOperator(stack<int> &stk, const char sign, int num) {
    if (sign == '+') {
      stk.push(num);
      return;
    }
    if (sign == '-') {
      stk.push(-num);
      return;
    }
    if (sign == '*') {
      num = num * stk.top();
      stk.pop();
      stk.push(num);
    }
    if (sign == '/') {
      num = stk.top()/num;
      stk.pop();
      stk.push(num);
    }
  }
};

int main() {
  Solution s;
  cout << s.calculate("1+2*3+(6-5)") << endl;
  return 0;
}