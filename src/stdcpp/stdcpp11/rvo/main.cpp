//
// Created by root on 4/6/24.
//
#include <iostream>

class A {
 public:
  explicit A(std::string _name) {
    this->name = _name;
    std::cout << this->name << ":"
              << "A(std::string _name) called" << std::endl;
  }
  A(const A& a) {
    this->name = a.name;
    std::cout << this->name << ":"
              << "A(const A& a) called" << std::endl;
  }
  A(const A&& a) {
    this->name = std::move(a.name);
    std::cout << this->name << ":"
              << "A(const A&& a) called" << std::endl;
  }
  A& operator=(const A& a) {
    this->name = a.name;
    std::cout << this->name << ":"
              << "operator =(const A& a) called" << std::endl;
    return *this;
  }
  ~A() {
    std::cout << this->name << ":"
              << "~A() called" << std::endl;
  }

 private:
  std::string name;
};

A GetMyA(std::string&& name) {
  A a(name);
  return a;
}

int main(int argc, char** argv) {
  const A& a1 = GetMyA("a1");
  const A a2 = GetMyA("a2");
  A a3 = GetMyA("a3");
  return 0;
}