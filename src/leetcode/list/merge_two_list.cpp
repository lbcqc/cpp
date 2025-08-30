//
// Created by root on 2025/8/30.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode *list = &dummy;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        list->next = list1;
        list1 = list1->next;
      } else {
        list->next = list2;
        list2 = list2->next;
      }
      list = list->next;
    }
    // while (list1 != nullptr) {
    //   list->next = list1;
    //   list = list->next;
    //   list1 = list1->next;
    // }
    // while (list2 != nullptr) {
    //   list->next = list2;
    //   list = list->next;
    //   list2 = list2->next;
    // }
    // list->next = nullptr;
    // 合并之后最多还有一个链表未被遍历完，直接追加即可
    list->next = list1 == nullptr? list2:list1;
    return dummy.next;
  }
};