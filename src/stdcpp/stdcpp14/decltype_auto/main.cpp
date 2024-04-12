//
// Created by root on 4/11/24.
//
#include <iostream>

// run: g++ -std=c++14 -o main main.cpp

template <typename T>
T f();

decltype(auto) f1() { return 1; }
decltype(auto) f2() {
  int a = 0;
  return a;
}
decltype(auto) f3() {
  int a = 0;
  return (a);
}

auto g1() { return 1; }
auto g2() {
  int a = 0;
  return a;
}
auto g3() {
  int a = 0;
  return (a);
}

int main(int argc, char** argv) {
  f<decltype(f1())>();
  f<decltype(f2())>();
  f<decltype(f3())>();

  f<decltype(g1())>();
  f<decltype(g2())>();
  f<decltype(g3())>();
  return 0;
}