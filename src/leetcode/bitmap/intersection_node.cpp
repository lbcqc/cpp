//
// Created by root on 2026/2/5.
//
// 160. 相交链表 https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=problem-list-v2&envId=2cktkvj
// 题解：使用 bitmap 来记录链表元素是否被遍历过，只需要先遍历一个链表，记录其出现过的元素，再遍历第二个链表，判断其元素是否出现过，即可

#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> exist;
    while(headA != nullptr || headB != nullptr) {
      if (headA != nullptr) {
        if (exist.count(headA)) {
          return headA;
        }
        exist.insert(headA);
        headA = headA->next;
      }
      if (headB != nullptr) {
        if (exist.count(headB)) {
          return headB;
        }
        exist.insert(headB);
        headB = headB->next;
      }
    }
    return nullptr;
  }
};