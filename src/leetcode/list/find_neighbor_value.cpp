//
// Created by Administrator on 2025/8/24.
//
#include <algorithm>
#include <cstdio>
#include <exception>

struct Node {
  int val;
  int index;
  Node* pre;
  Node* next;
};

void ListAppend(Node* cur, Node* next) {
  Node* tmp = cur->next;
  cur->next = next;
  next->pre = cur;
  tmp->pre = next;
  next->next = tmp;
}

class List {
public:
  Node _head;
  Node _tail;
  List() {
    _head.next = &_tail;
    _head.pre = nullptr;
    _tail.next = nullptr;
    _tail.pre = &_head;
  }
  // 添加到前面
  void PushBack(Node *pre) {
    Node *tmp = _tail.pre;
    tmp->next = pre;
    pre->pre = tmp;
    pre->next = &_tail;
    _tail.pre = pre;
  }

  void Del(Node* cur) {
    Node* pre = cur->pre;
    Node* next = cur->next;
    pre->next = next;
    next->pre = pre;
  }

  void Print() {
    printf("head->");
    Node* cur = _head.next;
    while (cur != &_tail) {
      printf("%d->", cur->val);
      cur = cur->next;
    }
    printf("tail\n");
  }

  bool IsDummy(Node *cur) {
    return cur == &_head || cur == &_tail;
  }
};



int main() {
  // 双链表
  List list;
  // list.PushBack(new Node{.val = 1});
  // list.PushBack( new Node{.val = 2});
  // Node *node3 = new Node{.val = 3};
  // list.PushBack(node3);
  // list.PushBack( new Node{.val = 4});
  // list.PushBack( new Node{.val = 5});
  // list.Print();
  // list.Del(node3);
  // list.Print();

  int num = 0;
  scanf("%d", &num);
  if (num <= 1) {
    return 0;
  }
  int vals[num];
  int index[num];
  int select[num];
  Node nodes[num];
  for (int i = 0; i < num; i++) {
    scanf("%d", &vals[i]);
    index[i] = i;
  }
  std::sort(index, index+num, [&](int idi, int idj)->bool{return vals[idi]<vals[idj];});
  // for (int i = 0; i < num; i ++) {
  //   printf("%d ", index[i]);
  // }
  // printf("\n");
  for (int i = 0; i < num; i++) {
    nodes[index[i]].val = vals[index[i]];
    nodes[index[i]].index = index[i];
    list.PushBack(&nodes[index[i]]);
  }

  for (int i = num-1; i >=1; i --) {
    // list.Print();
    Node* cur = &nodes[i];
    if (list.IsDummy(cur->next)) {
      select[i] = cur->pre->index;
    } else if (list.IsDummy(cur->pre)) {
      select[i] = cur->next->index;
    } else if (std::abs(cur->pre->val - cur->val) <= std::abs(cur->next->val - cur->val)) {
      select[i] = cur->pre->index;
    } else {
      select[i] = cur->next->index;
    }
    list.Del(cur);
  }
  for (int i = 1; i < num; i++) {
    printf("%d %d\n", std::abs(vals[select[i]] - vals[i]), select[i]+1);
  }

  return 0;
}




//#include <algorithm>
// #include <functional>
// #include <iostream>
// #include <list>
// #include <memory>
//
// class ListNode {
// public:
//   int val;
//   int index;
//   int neighbor_value;
//   int neighbor_index;
//
//   // ListNode* pre;
//   // ListNode* next;
//   //
//   ListNode() = default;
//   ListNode(int _val):val(_val){};
//   ListNode(int _val, int _index): val(_val), index(_index){};
//   //
//   // void insert(ListNode *_next) {
//   //   _next->next = this->next;
//   //   this->next->pre = _next;
//   //
//   //   this->next = _next;
//   //   _next->pre = this;
//   // }
//   //
//   // void del() {
//   //   auto _pre = this->pre;
//   //   auto _next = this->next;
//   //   _pre->next = _next;
//   //   _next->pre = _pre;
//   // }
// };
//
// class ValNode {
// public:
//   int val;
//  std::reference_wrapper<ListNode> it;
//   ValNode() = default;
// };
//
//
// int main(int argc, char **argv) {
//   // 输入
//   int num = 0;
//   std::cin >> num;
//
//   if (num <= 1) {
//     return 0;
//   }
//
//   ValNode vals[num];
//   // ListNode list[num];
//   std::list<ListNode> head;
//   for (int i = 0; i<num; i++) {
//     int tmp;
//     std::cin >> tmp;
//     head.push_back(ListNode{tmp, i});
//     vals[i].val = tmp;
//     vals[i].it = std::ref(head.back());
//   }
//
//   // 排序
//   head.sort([](const ListNode &a, const ListNode &b)->bool{return a.val < b.val;});
//   for (auto it = head.begin(); it != head.end(); ++it) {
//     std::cout << it->val << std::endl;
//   }
//   for (int i = 0; i < num; i++) {
//     std::cout << vals[i].it->val << ":" << vals[i].it->index << std::endl;
//   }
//
//   // // 查找邻值
//   // for (int i = num-1; i >=1; i--) {
//   //   auto node = vals[i].p;
//   //   int pre_neighbor_val = 0;
//   //   int pre_neighbor_index = 0;
//   //   int next_neighbor_val = 0;
//   //   int next_neighbor_index = 0;
//   //   if (node-> != nullptr) {
//   //     pre_neighbor_val = std::abs(node->pre->val - node->val);
//   //     pre_neighbor_index = node->pre->index;
//   //   }
//   //   if (node->next != nullptr) {
//   //     next_neighbor_val = std::abs(node->next->val - node->val);
//   //     next_neighbor_index = node->next->index;
//   //   }
//   //   if (pre_neighbor_val < next_neighbor_val || (
//   //     pre_neighbor_val == next_neighbor_val && pre_neighbor_index< next_neighbor_index )) {
//   //     node->neighbor_index = pre_neighbor_index;
//   //     node->neighbor_value = pre_neighbor_val;
//   //   } else {
//   //     node->neighbor_index = next_neighbor_index;
//   //     node->neighbor_value = next_neighbor_val;
//   //   }
//   //   node->del();
//   // }
//
//   // 输出
//   // for (int i = 1; i < num; i++) {
//   //   std::cout << vals[i].p->neighbor_value << " " << vals[i].p->neighbor_index + 1<< std::endl;
//   // }
//   return 0;
// }
