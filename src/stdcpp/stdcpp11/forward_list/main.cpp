//
// Created by root on 3/24/24.
//
#include <forward_list>
#include <fmt/ranges.h>

int main(int argc, char* argv[]) {
  std::forward_list<int> l = {1,2,3};
  fmt::print("reverse before: {}\n", l);
  l.reverse();
  fmt::print("reverse after: {}\n", l);
  l.sort();
  fmt::print("reverse sort: {}\n", l);
  return 0;
}