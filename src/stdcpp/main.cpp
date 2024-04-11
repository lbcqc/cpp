//
// Created by root on 3/24/24.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

auto add(int a, std::unique_ptr<int> b) {
    return a + *b;
}

int main(int argc, char *argv[]) {
  int a = 1;
  std::unique_ptr<int> p =  std::make_unique<int>(1);
  add(a, std::move(p));
  a = *p;
  return 0;
}