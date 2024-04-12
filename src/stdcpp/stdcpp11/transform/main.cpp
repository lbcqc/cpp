//
// Created by root on 4/6/24.
//
#include <algorithm>
#include <cctype>
#include <iostream>

enum class E1 {
  Unknown,
};

enum class E2 {
  Unknown,
};

int main(int argc, char *argv[]) {
  int a{0};  // init list a = 0; a(0);
  std::string str = "abcd";
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  std::cout << str << a << std::endl;
  return 0;
}