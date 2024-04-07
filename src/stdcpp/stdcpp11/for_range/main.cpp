//
// Created by root on 4/8/24.
//

#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  for (auto& v : vec) {  // writable
    std::cout << v << " ";
  }
  std::cout << std::endl;

  for (auto v : vec) {  // read only
    std::cout << v << " ";
  }
  std::cout << std::endl;
  return 0;
}