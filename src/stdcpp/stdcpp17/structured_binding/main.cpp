//
// Created by root on 4/11/24.
//
#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
  std::map<std::string, int> m = {
    { "a", 1 },
    { "b", 2 },
    { "c", 3 },
  };

  for (auto &&[k, v] : m) {
    std::cout << k << " " << v << '\n';
  }

  std::tuple<std::string, int> t = { "a", 1 };
  auto &&[k, v] = t;
  std::cout << k << " " << v << '\n';\

  return 0;
}