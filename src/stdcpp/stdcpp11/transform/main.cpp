//
// Created by root on 4/6/24.
//
#include <iostream>
#include <algorithm>
#include <cctype>

int main(int argc, char *argv[])
{
  std::string str = "abcd";
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  std::cout << str << std::endl;
  return 0;
}