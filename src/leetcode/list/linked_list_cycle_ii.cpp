//
// Created by root on 2025/8/30.
//
#include <climits>
#include <iostream>
#include <unordered_set>

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

// 快慢指针法
// fast len = 2(l+p) = l + p + k*r  ---> l + p = k*r;
// slow len = l + p;
//
// l + p + l = l + p + k*r - p = l + kr
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    int fast_len = 0;
    int slow_len = 0;
    while (fast->next && fast->next->next) {
      fast_len+=2;
      slow_len+=1;
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        while (slow != head) {
          head = head->next;
          slow = slow->next;
        }
        return head;
      }
    }
    return nullptr;
  }
};

int main(int argc, char **argv) {
  ListNode node4(4);
  ListNode node3(3, &node4);
  ListNode node2(2, &node3);
  ListNode node1(1, &node2);
  ListNode head(0, &node1);

  Solution s;
  ListNode *detect = s.detectCycle(&head);
  if (detect != nullptr) {
    std::cout << detect->val << std::endl; // expect false
  }


  // create cycle
  node4.next = &node2;
  detect = s.detectCycle(&head);
  if (detect != nullptr) {
    std::cout << detect->val << std::endl; // expect false
  }
  return 0;
}