//
// Created by root on 4/7/24.
//
#include <iostream>

int foo1(){
  return 0;
}

// since C++11 return argument type deduction
auto foo2() -> decltype(0.0) {
  return 0.0;
}

// since C++14 return argument type deduction
auto foo3() {
  return 0.0;
}

// since C++14 return argument type forwarding
decltype(auto) foo11(){
  return foo1();
}

// since C++14
decltype(auto) foo22(){
  return foo2();
}

int main(int argc, char **argv) {
  int x = 1;
  int y = 2;
  decltype(x+y) z;
  typeof(x+y) p;
  if (std::is_same<decltype(z), int>::value) {
    std::cout << "decltype(z) == int" << std::endl;
  }
  if (std::is_same<typeof(z), int>::value) {
    std::cout << "typeof(z) == int" << std::endl;
  }
  if (std::is_same<decltype(p), int>::value) {
    std::cout << "decltype(p) == int" << std::endl;
  }

  std::cout << "foo11() = " << foo11() << std::endl;
  return 0;
}