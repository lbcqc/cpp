//
// Created by root on 4/6/24.
//
#include <fmt/ranges.h>
#include <algorithm>
#include <set>
int main(int argc, char *argv[]) {
  std::set<int> s = {1, 2, 3, 4, 5};  // initialize since by c++11
  for (auto it = s.begin(); it != s.end();) {
    if (*it % 2 == 0) {
      s.erase(it++);
    } else {
      it++;
    }
  }
  fmt::println("set after erase: {}", s);

  for (auto it = s.begin(); it != s.end();) {
    s.insert(it, *it - 1);
    it++;
  }
  s.insert(s.begin(),1); // set no allow repeated value
  s.insert(s.begin(),1);
  s.insert(s.begin(),1);
  s.insert(s.begin(),1);
  fmt::println("set count 1: {}", s.count(1));
  fmt::println("set after insert: {}", s);
  return 0;
}