//
// Created by root on 4/6/24.
//

#include <functional>
#include <iostream>
#include <string>
#include <thread>

void foo(int &a, std::string &str) {
    str += " called";
    a++;
}

int main(int argc, char **argv) {
  int a = 10;
  std::string str = "hello world";
  std::thread t1([&a, &str]() {
    a = 20;
    str = "hello world2";
  });
  t1.join();
  std::cout << "a: " << a << std::endl;
  std::cout << "str: " << str << std::endl;

  std::thread t2(foo, std::ref(a), std::ref(str)); // don't add std::ref causing compilation errors
  t2.join();
  std::cout << "a: " << a << std::endl;
  std::cout << "str: " << str << std::endl;

  std::function<void()> bind_f = std::bind(foo, a, std::ref(str)); // default bind by value, a value will don't change
  bind_f();
  std::cout << "a: " << a << std::endl;
  std::cout << "str: " << str << std::endl;

  std::function<void()> bind_f2 = std::bind(foo, std::ref(a), std::ref(str));
  bind_f2();
  std::cout << "a: " << a << std::endl;
  std::cout << "str: " << str << std::endl;
  return 0;
}