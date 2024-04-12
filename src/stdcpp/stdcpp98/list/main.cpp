//
// Created by root on 4/6/24.
//
#include <fmt/ranges.h>
#include <algorithm>
#include <iostream>
#include <list>
int main(int argc, char *argv[]) {
  std::list<int> l = {1, 2, 3, 4, 5};  // initialize since by c++11
  for (auto it = l.begin(); it != l.end();) {
    if (*it % 2 == 0) {
      l.erase(it++);
    } else {
      it++;
    }
  }
  fmt::println("list after erase: {}", l);

  for (auto it = l.begin(); it != l.end();) {
    l.insert(it, *it - 1);
    it++;
  }
  fmt::println("list after inset: {}", l);
  return 0;
}