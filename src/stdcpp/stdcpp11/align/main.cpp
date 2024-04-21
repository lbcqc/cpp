//
// Created by root on 4/20/24.
//
#include <iostream>

struct A {
  char a;
  int b;
  float c;
  long long int d;
};

struct alignas(max_align_t) B {
  char a;
  int b;
  float c;
  long long int d;
};

int main(int argc, char **argv) {
  std::cout << "align A: " << alignof(A) << std::endl;
  std::cout << "align B: " << alignof(B) << std::endl;
  return 0;
}