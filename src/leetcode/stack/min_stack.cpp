//
// Created by root on 2025/8/31.
//
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>

using namespace std;

// 使用最小值堆进行辅助
// struct Node {
//   int val;
//   bool invalid;
//   explicit Node(const int& val):val(val), invalid(false){};
// };
//
// bool operator<(const shared_ptr<Node>& a, const shared_ptr<Node>& b) {
//   return a->val > b->val;
// }
// class MinStack {
// private:
//   stack<shared_ptr<Node>> stk;
//   priority_queue<shared_ptr<Node>> min_heap;
// public:
//   MinStack() {
//
//   }
//
//   void push(int val) {
//     shared_ptr<Node> node = make_shared<Node>(val);
//     min_heap.push(node);
//     stk.push(node);
//   }
//
//   void pop() {
//     auto node = stk.top();
//     node->invalid = true;
//     stk.pop();
//   }
//
//   int top() {
//     return stk.top()->val;
//   }
//
//   int getMin() {
//     auto node = min_heap.top();
//     while (node->invalid) {
//       min_heap.pop();
//       node = min_heap.top();
//     }
//     return node->val;
//   }
// };

// 使用最小值栈进行辅助
// class MinStack {
// private:
//   stack<int> stk;
//   stack<int> min_stk;
// public:
//   MinStack() {
//     stk.push(INT32_MAX);
//     min_stk.push(INT32_MAX);
//   }
//
//   void push(int val) {
//     int min_val = val<min_stk.top()? val:min_stk.top();
//     stk.push(val);
//     min_stk.push(min_val);
//   }
//
//   void pop() {
//     stk.pop();
//     min_stk.pop();
//   }
//
//   int top() {
//     return stk.top();
//   }
//
//   int getMin() {
//     return min_stk.top();
//   }
// };

// 不使用辅助栈，一个元素同时存储原始值+最小值
struct Node {
  int val;
  int min_val;
};
class MinStack {
 private:
  stack<Node> stk;

 public:
  MinStack() { stk.push(Node{.val = INT32_MAX, .min_val = INT32_MAX}); }

  void push(int val) {
    int min_val = val < stk.top().min_val ? val : stk.top().min_val;
    stk.push(Node{.val = val, .min_val = min_val});
  }

  void pop() { stk.pop(); }

  int top() { return stk.top().val; }

  int getMin() { return stk.top().min_val; }
};

int main() {
  MinStack* obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  cout << obj->getMin() << endl;
  obj->pop();
  cout << obj->top() << endl;
  cout << obj->getMin() << endl;
}
