//
// Created by root on 2025/9/6.
//

// c list
// struct Node {
//   Node *pre;
//   Node *next;
//   int val;
//   Node(int val):val(val), pre(nullptr), next(nullptr){};
// };
//
// class MyCircularDeque {
//   Node *head;
//   Node *tail;
//   int max;
//   int size;
// public:
//   MyCircularDeque(int k):max(k) {
//     size = 0;
//     head = new Node(0);
//     tail = new Node(0);
//     head->next = tail;
//     tail->pre = head;
//   }
//   ~MyCircularDeque() {
//     while (!isEmpty()) {
//       deleteFront();
//     }
//     delete head;
//     delete tail;
//     head = nullptr;
//     tail = nullptr;
//     size = 0;
//   }
//
//   bool insertFront(int value) {
//     if (isFull()) {
//       return false;
//     }
//     Node *tmp = new Node(value);
//     tmp->next = head->next;
//     tmp->pre = head;
//     head->next->pre = tmp;
//     head->next = tmp;
//     size++;
//     return true;
//   }
//
//   bool insertLast(int value) {
//     if (isFull()) {
//       return false;
//     }
//
//     Node *tmp = new Node(value);
//     tmp->next = tail;
//     tmp->pre = tail->pre;
//     tail->pre->next = tmp;
//     tail->pre = tmp;
//     size++;
//     return true;
//   }
//
//   bool deleteFront() {
//     if (isEmpty()) {
//       return false;
//     }
//     Node* tmp = head->next;
//     head->next = tmp->next;
//     tmp->next->pre = head;
//     delete tmp;
//     size--;
//     return true;
//   }
//
//   bool deleteLast() {
//     if (isEmpty()) {
//       return false;
//     }
//     Node* tmp = tail->pre;
//     tmp->pre->next = tmp->next;
//     tmp->next->pre = tmp->pre;
//     delete tmp;
//     size--;
//     return true;
//   }
//
//   int getFront() {
//     if (isEmpty()) {
//       return -1;
//     }
//     return head->next->val;
//   }
//
//   int getRear() {
//     if (isEmpty()) {
//       return -1;
//     }
//     return tail->pre->val;
//   }
//
//   bool isEmpty() {
//     if (size <= 0) {
//       return true;
//     }
//     return false;
//   }
//
//   bool isFull() {
//     if (size >= max) {
//       return true;
//     }
//     return false;
//   }
// };

#include <memory>
// c++ list
// struct Node {
//   std::shared_ptr<Node> pre;
//   std::shared_ptr<Node> next;
//   int val;
//   Node(int val):val(val), pre(nullptr), next(nullptr){};
// };
//
// class MyCircularDeque {
//   std::shared_ptr<Node> head;
//   std::shared_ptr<Node> tail;
//   int max;
//   int size;
// public:
//   MyCircularDeque(int k):max(k) {
//     size = 0;
//     head = std::make_shared<Node>(0);
//     tail = std::make_shared<Node>(0);
//     head->next = tail;
//     tail->pre = head;
//   }
//
//   bool insertFront(int value) {
//     if (isFull()) {
//       return false;
//     }
//     auto tmp = std::make_shared<Node>(value);
//     tmp->next = head->next;
//     tmp->pre = head;
//     head->next->pre = tmp;
//     head->next = tmp;
//     size++;
//     return true;
//   }
//
//   bool insertLast(int value) {
//     if (isFull()) {
//       return false;
//     }
//
//     auto tmp = std::make_shared<Node>(value);
//     tmp->next = tail;
//     tmp->pre = tail->pre;
//     tail->pre->next = tmp;
//     tail->pre = tmp;
//     size++;
//     return true;
//   }
//
//   bool deleteFront() {
//     if (isEmpty()) {
//       return false;
//     }
//     auto tmp = head->next;
//     head->next = tmp->next;
//     tmp->next->pre = head;
//     size--;
//     return true;
//   }
//
//   bool deleteLast() {
//     if (isEmpty()) {
//       return false;
//     }
//     auto tmp = tail->pre;
//     tmp->pre->next = tmp->next;
//     tmp->next->pre = tmp->pre;
//     size--;
//     return true;
//   }
//
//   int getFront() {
//     if (isEmpty()) {
//       return -1;
//     }
//     return head->next->val;
//   }
//
//   int getRear() {
//     if (isEmpty()) {
//       return -1;
//     }
//     return tail->pre->val;
//   }
//
//   bool isEmpty() {
//     if (size <= 0) {
//       return true;
//     }
//     return false;
//   }
//
//   bool isFull() {
//     if (size >= max) {
//       return true;
//     }
//     return false;
//   }
// };

// c++ vector
// 题解：这道题的关键在于 cap 要多加一个节点，通过 Head==tail 还是 head和 tail 差 1 来区分空还是满
// 否则如果 cap为 k 的话，空和满都是 head==tail。
#include <vector>
using namespace std;
class MyCircularDeque {
  vector<int> vec;
  int head;
  int tail;
  int cap;
public:
  MyCircularDeque(int k):vec(k+1),cap(k+1),head(0), tail(0) {
  }

  bool insertFront(int value) {
    if (isFull()) {
      return false;
    }
    head = (head+1+cap) % cap;
    vec[head] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) {
      return false;
    }
    vec[tail] = value;
    tail = (tail-1+cap) % cap;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) {
      return false;
    }
    head = (head-1+cap) % cap;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) {
      return false;
    }
    tail = (tail+1+cap) % cap;
    return true;
  }

  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return vec[head];
  }

  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    int tmp = (tail + 1+cap)%cap;
    return vec[tmp];
  }

  bool isEmpty() {
    if (head==tail) {
      return true;
    }
    return false;
  }

  bool isFull() {
    int tmp = (head + 1+ cap) % cap;
    if (tmp == tail) {
      return true;
    }
    return false;
  }
};
