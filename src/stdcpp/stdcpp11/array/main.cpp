//
// Created by root on 3/24/24.
//
#include <fmt/ranges.h>
#include <algorithm>
#include <array>
#include <iostream>

int main(int argc, char *argv[]) {
  // create an array with three elements
  std::array<int, 3> a = {2, 1, 3};
  fmt::print("{}\n", a);

  // sort by less
  std::sort(a.begin(), a.end(), std::less<int>());
  fmt::print("{}\n", a);

  // sort by greater
  std::sort(a.begin(), a.end(), std::greater<int>());
  fmt::print("{}\n", a);

  // sort by greater lambda
  std::sort(a.begin(), a.end(), [](int a, int b) { return a > b; });
  fmt::print("{}\n", a);

  // print the third element
  fmt::print("a[2]: {}\n", a[2]);

  // iterate over array
  for (const auto &i : a) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}