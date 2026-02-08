//
// Created by root on 2026/2/8.
//
// 234. 回文链表 https://leetcode.cn/problems/palindrome-linked-list/?envType=problem-list-v2&envId=2cktkvj
// 题解1：使用双向队列/链表来存储元素，而后通过对比前后两个元素是否相等来判断回文
// 题解2：寻找到链表终点，将其拆分为两半，然后翻转最后一半链表，再一一比较，直到有其中一个链表结束，最后需要将链表重新合并回去

#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 题解 1
// class Solution {
// public:
//   bool isPalindrome(ListNode* head) {
//     deque<int> dq;
//     // list<int> dq;
//     while(head) {
//       dq.push_back(head->val);
//       head = head->next;
//     }
//     bool ans = true;
//     while(true) {
//       if (dq.empty()) break;
//       int front = dq.front();
//       dq.pop_front();
//       if (dq.empty()) break;
//       int back = dq.back();
//       dq.pop_back();
//       if (front != back) {
//         ans = false;
//         break;
//       }
//     }
//     return ans;
//   }
// };

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr) return true;
    ListNode *firstHalfEndNode = firstHalfEnd(head);
    ListNode *secondHalfHead = reverseList(firstHalfEndNode->next);

    bool ans = true;
    ListNode* head1 = head;
    ListNode* head2 = secondHalfHead;
    while (head1 && head2) {
      if (head1->val != head2->val) {
        ans = false;
        break;
      }
      head1 = head1->next;
      head2 = head2->next;
    }

    // 恢复原链表
    secondHalfHead = reverseList(secondHalfHead);
    firstHalfEndNode->next = secondHalfHead;
    return ans;
  }
private:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) return head;
    ListNode dummy(0, nullptr);
    while (head) {
      ListNode* cur = head;
      head = head->next;

      cur->next = dummy.next;
      dummy.next = cur;
    }
    return dummy.next;
  }
  ListNode *firstHalfEnd(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};

int main() {
  ListNode node3(1);
  ListNode node2(2, &node3);
  ListNode node1(1, &node2);

  Solution s;
  cout << s.isPalindrome(&node1) << endl;
}