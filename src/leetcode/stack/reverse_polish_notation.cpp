//
// Created by root on 2025/8/31.
//
#include <cstdlib>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// class Solution {
// public:
//   int evalRPN(vector<string>& tokens) {
//     stack<int> stk = {};
//     if (tokens.empty()) {
//       return 0;
//     }
//     for (const string &t : tokens) {
//       if (isOperator(t)) {
//         int param_b = stk.top(); stk.pop();
//         int param_a = stk.top(); stk.pop();
//         int result = execOperator(param_a, param_b, t);
//         stk.push(result);
//       } else {
//         stk.push(atoi(t.c_str()));
//       }
//     }
//     return stk.top();
//   }
//   bool isOperator(string_view str) {
//     if ("+" == str || "-" == str || "*" == str || "/" == str) {
//       return true;
//     }
//     return false;
//   }
//   int execOperator(int a, int b, string op) {
//     if ("+" == op) {
//       return a+b;
//     }
//     if ("-" == op) {
//       return a-b;
//     }
//     if ("*" == op) {
//       return a*b;
//     }
//     if ("/" == op) {
//       return a/b;
//     }
//     return 0; // 异常
//   }
// };

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stk = {};
    unordered_map<string, function<int(int, int)>> opr = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }},
    };
    for (const string& token : tokens) {
      if (opr.count(token)) {
        int right = stk.top();
        stk.pop();
        int left = stk.top();
        stk.pop();
        int result = opr[token](left, right);
        stk.push(result);
        continue;
      }
      stk.push(atoi(token.c_str()));
    }
    return stk.top();
  }
};

int main() {
  Solution s;
  // auto tokens = vector<string>{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  auto tokens = vector<string>{"2", "1", "+", "3", "*"};
  cout << s.evalRPN(tokens) << endl;
}