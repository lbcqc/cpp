//
// Created by root on 4/8/24.
//

#include <iostream>

constexpr int a = 1 + 1;         // since by c++11
constexpr double b = 1.0 + 1.0;  // since by c++11

template <typename T>
auto foo(const T &t) {                         // since by C++14, return argument type can be deduced
  if constexpr (std::is_integral<T>::value) {  // since by c++17
    return t + 1;
  } else {
    return t + 2.0;
  }
}

// int foo(const int& t) {
//   return t + 1;
// }
// double foo(const double& t) {
//   return t + 1.0;
// }

int main(int argc, char **argv) {
  std::cout << "foo(a): " << foo(a) << std::endl;
  std::cout << "foo(b): " << foo(b) << std::endl;
  return 0;
}