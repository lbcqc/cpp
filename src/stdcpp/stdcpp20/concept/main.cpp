//
// Created by root on 4/20/24.
//
#include <concepts>
#include <iostream>
#include <cstdint>

template <typename T>
concept always_true = true;

template <typename T>
concept integral = std::is_integral_v<T>;

template <typename T>
concept signal_integral = integral<T> && std::is_signed_v<T>;

template <always_true T>
T foo(T a, T b) {
  return a*b;
}

template <integral T>
T foo_integral(T a, T b) {
  return a*b;
}

template<integral T>
T foo_signed_integral(T a, T b) {
  return a*b;
}

int main(int argc, char **argv) {
  //std::cout << foo("abc","abc") << std::endl; // error: invalid operands of types 'const char*' and 'const char*' to binary 'operator*'
  std::cout << foo(2,3) << std::endl;
  //std::cout << foo_integral(2.0,3.0) << std::endl; // note: the expression 'is_integral_v<T> [with T = double]' evaluated to 'false'
  std::cout << foo_integral(2,3) << std::endl;
  std::cout << foo_signed_integral(uint32_t(2),uint32_t(3)) << std::endl;
  return 0;
}