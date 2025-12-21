//
// Created by root on 4/20/24.
//
#include <iostream>
#include <thread>

int main(int argc, char **argv) {
  int flag = 0;
  int a = 0;  // a 没有被 volatile 修饰，消费者线程有可能没有看到 a 的最新值

  auto t1 = std::thread([&]() {
    while (flag == 0)
      ;
    int b = a;
    std::cout << b << std::endl;
  });
  auto t2 = std::thread([&]() {
    a = 10;  // 由于编译器对指令重排的影响，flag 不一定在 a 之后被赋值
    flag = 1;
  });
  t1.join();
  t2.join();
  return 0;
}