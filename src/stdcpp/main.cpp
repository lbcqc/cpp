//
// Created by root on 3/24/24.
//
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

auto add(int a, std::unique_ptr<int> b) { return a + *b; }

int main(int argc, char *argv[]) {
  std::vector<bool> test = {false};
  auto t = test[0];
  std::cout << typeid(t).name() << std::endl;

  char a_char = 'a';
  int a = static_cast<int>(a_char);
  std::unique_ptr<int> p = std::make_unique<int>(1);
  add(a, std::move(p));
  // a = *p; // will cause panic
  return 0;
}