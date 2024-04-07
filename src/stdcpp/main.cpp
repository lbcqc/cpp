//
// Created by root on 3/24/24.
//
#include <iostream>
#include <vector>
#include <unordered_map>

int main(int argc, char *argv[]) {
  std::vector<char> vec =  {'a', 'v', 'd', 'f', 'd', 'f', 'c', 'a'};
  std::unordered_map<char, int> count;
  for (auto v:vec){
    count[v]++;
  }
  int index = 0;
  for (auto v:vec){
    if (count[v] == 1) {
      break;
    }
    index++;
  }
  std::cout << index << std::endl;
  return 0;
}