//
// Created by root on 4/10/24.
//
#include <iostream>

template <typename... T>
auto sum(T... args) {
  return (args + ...);
}

int main(int argc, char **argv) {
  std::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9.0, 0.01) << std::endl;
  return 0;
}