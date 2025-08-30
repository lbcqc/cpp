//
// Created by root on 2025/8/30.
//
// https://leetcode.cn/problems/valid-parentheses/
#include <string>
#include <stack>
#include <map>
#include <array>
using namespace std;
// class Solution {
// public:
//   bool isValid(string s) {
//     stack<char> stk;
//     map<char, char> match = {
//       {')', '('},
//       {']', '['},
//       {'}', '{'},
//     };
//     for (auto c:s) {
//       char m = match[c];
//       if (m != '\0' ) {
//         if (stk.empty()) {
//           return false;
//         }
//         if (stk.top() != m) {
//           return false;
//         }
//         stk.pop();
//         continue;
//       }
//       stk.push(c);
//     }
//     return stk.empty();
//   }
// };


// class Solution {
// public:
//   bool isValid(string s) {
//     stack<char> stk;
//     for (auto c:s) {
//       if (c == '(') stk.push(')');
//       else if (c == '[') stk.push(']');
//       else if (c == '{') stk.push('}');
//       else if (!stk.empty() && stk.top() == c) stk.pop();
//       else return false;
//     }
//     return stk.empty();
//   }
// };

// 耗时最优
class Solution {
public:
  bool isValid(string s) {
    array<char,256> match = {0};
    match['('] = ')';
    match['['] = ']';
    match['{'] = '}';
    stack<char> stk;
    for (auto c:s) {
      char tmp = match[c];
      if (tmp != '\0') stk.push(tmp);
      else if (!stk.empty() && stk.top() == c) stk.pop();
      else return false;
    }
    return stk.empty();
  }
};