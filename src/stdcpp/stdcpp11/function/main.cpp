//
// Created by root on 4/12/24.
//
#include <functional>
#include <iostream>
int main(int argc, char *argv[]) {
  int a = 1;
  int b = 2;
  std::function<int(int, int)> f = [](int a, int b) -> int { return a + b; };
  auto f2 = std::bind(f, std::ref(a), std::placeholders::_1);  // bind a by reference
  a = f(a, b);
  std::cout << "f(a,b) = " << a << std::endl;
  std::cout << "f2(b) = " << f2(b) << std::endl;
  return 0;
}