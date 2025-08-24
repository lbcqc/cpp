//
// Created by shuaili on 8/24/25.
//
#include <iostream>
#include <memory>
#include <sstream>
#include <stack>
#include <utility>

class ListNode {
public:
  int val{};
  std::shared_ptr<ListNode> next;
  ListNode()= default;
  explicit ListNode(const int _val): val(_val), next(nullptr) {};
  ListNode(const int _val, std::shared_ptr<ListNode> _next): val(_val), next(_next){}
};

class List {
public:
  std::shared_ptr<ListNode> head;
  List() {
    head = std::make_unique<ListNode>();
  }
  List(std::shared_ptr<ListNode> next) {
    head = std::make_unique<ListNode>(0, next);
  }
public:
  void Reverse() {
    std::stack<std::shared_ptr<ListNode>> stack;
    auto last = head;
    while (last->next != nullptr) {
      stack.push(last->next);
      last = last->next;
    }
    last = head;
    while (!stack.empty()) {
      last->next = stack.top();
      stack.pop();
      last = last->next;
    }
    last->next = nullptr;
  }
  std::string DebugString() {
    std::stringstream ss;
    ss << "head->";
    std::shared_ptr<ListNode> last = head->next;
    while (last != nullptr) {
      ss << last->val << "->";
      last = last->next;
    }
    ss << "nullptr";
    return ss.str();
  }
};

int main(int argc, char **argv) {
  std::shared_ptr<ListNode> node5 = std::make_shared<ListNode>(5);
  std::shared_ptr<ListNode> node4 = std::make_shared<ListNode>(4, node5);
  std::shared_ptr<ListNode> node3 = std::make_shared<ListNode>(3, node4);
  std::shared_ptr<ListNode> node2 = std::make_shared<ListNode>(2, node3);
  std::shared_ptr<ListNode> node1 = std::make_shared<ListNode>(1, node2);
  List list(node1);
  // List list;
  std::cout << list.DebugString() << std::endl;
  list.Reverse();
  std::cout << list.DebugString() << std::endl;
  return 0;
}