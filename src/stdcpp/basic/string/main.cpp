//
// Created by root on 24-3-27.
//
#include <iostream>
#include <string>

class TestString {
 public:
  void copy(const std::string &str) {
    value = str;
    std::cout << "str: " << str << std::endl;
    std::cout << "value: " << value << std::endl;
  }

 private:
  std::string value;
};

int main(int argc, char *argv[]) {
  uint32_t ver = 1;
  std::string str = std::to_string(ver);
  TestString ts;
  ts.copy(str);
  return 0;
}