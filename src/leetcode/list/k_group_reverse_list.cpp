//
// Created by root on 5/9/24.
//
#include <iostream>
#include <variant>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 0 || k == 1) {
      return head;
    }
    if (head == nullptr) {
        return head;
    }
    return reverseKGroupImpl(head, k);
  }
  // K个一组反转链表实现
  ListNode *reverseKGroupImpl(ListNode *head, int k) {
    ListNode sentinel;
    sentinel.next = head;
    ListNode *last_head = &sentinel;
    while (head!=nullptr) {
      ListNode *next_head = head;
      ListNode *next_end = getEnd(next_head, k);
      // 已经是最后一组，无需处理
      if (next_end == nullptr) {
        last_head->next = next_head;
        break;
      }
      // 拼接下一组
      reverseImpl(next_head, next_end->next);
      last_head->next = next_end;
      last_head = next_head;
      head = last_head->next;
    }

    return sentinel.next;
  }
  //
  ListNode *getEnd(ListNode *head, int k) {
    k--;
    while (k-- && head!=nullptr){
      head = head->next;
    }
    return head;
  }
  // 反转链表实现
  void reverseImpl(ListNode *head, ListNode* stop) {
    if (head == nullptr) {
      return;
    }
    // 跳过第一个元素
    ListNode sentinel;
    sentinel.next = head;
    ListNode *tail = head;
    head = head->next;
    // 从第二个开始反转
    while (head != stop) {
      ListNode *next = head->next;
      head->next = sentinel.next;
      sentinel.next = head;
      head = next;
    }
    tail->next = stop;
  }
  // 打印链表
  void PrintList(ListNode *head) {
    std::cout << "head->";
    while(head != nullptr) {
      std::cout << head->val << "->";
      head = head->next;
    }
    std::cout << "nullptr" << std::endl;
  }
};
int main(int argc, char **argv) {
  // ListNode node5(5);
  ListNode node4(4);
  ListNode node3(3, &node4);
  ListNode node2(2, &node3);
  ListNode node1(1, &node2);
  Solution s;
  s.PrintList(&node1);
  auto reverse = s.reverseKGroup(&node1, 2);
  s.PrintList(reverse);
  return 0;
}