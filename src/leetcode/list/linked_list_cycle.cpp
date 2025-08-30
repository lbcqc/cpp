//
// Created by root on 2025/8/30.
//
#include <iostream>
#include <climits>

// TIPS:
// 链表中节点的数目范围是 [0, 104]
//-10^5 <= Node.val <= 10^5
// pos 为 -1 或者链表中的一个 有效索引 。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* _next): val(x), next(_next) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    while (head) {
      if (head->val == INT32_MAX) {
        return true;
      }
      head->val = INT32_MAX;
      head = head->next;
    }
    return false;
  }
};

int main(int argc, char **argv) {
  ListNode node4(4);
  ListNode node3(3, &node4);
  ListNode node2(2, &node3);
  ListNode node1(1, &node2);
  ListNode head(0, &node1);

  Solution s;
  std::cout << s.hasCycle(&head) << std::endl; // expect false

  // create cycle
  node4.next = &node2;
  std::cout << s.hasCycle(&head) << std::endl;s.hasCycle(&head); // expect true
  return 0;
}