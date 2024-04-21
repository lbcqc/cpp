//
// Created by root on 4/20/24.
//
#include <atomic>
#include <iostream>
#include <thread>

struct A {
  long z;
};

int main(int argc, char** argv) {
  std::atomic<int> count = {0};
  auto t1 = std::thread([&count] { count++; });
  auto t2 = std::thread([&count] { count += 1; });
  auto t3 = std::thread([&count] { count.fetch_add(1); });
  t1.join();
  t2.join();
  t3.join();
  std::cout << "count: " << count << std::endl;

  std::atomic<A> a;
  std::cout << std::boolalpha << a.is_lock_free() << std::endl;
  return 0;
}