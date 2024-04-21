//
// Created by root on 4/20/24.
//
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

template <class T>
using Vec = std::vector<T>;
// typedef std::vector<T> Vec; // not allowed

Vec<int> vec;

int main(int argc, char **argv) {
  std::cout << "thread before" << std::endl;
  std::thread t([]() {
    std::mutex mtx;
    // std::lock_guard<std::mutex> lock(mtx); // RAII，auto unlocked when out of scope，Even if an exception occurs, it
    // will be unlocked
    std::unique_lock<std::mutex> lock(mtx); // RAII，compared with lock_guard, it is more flexible and can be manually unlocked and locked.
    vec.push_back(10);
    lock.unlock();

    // the second critical section
    lock.lock();
    vec.at(0) = 100;

    std::cout << "Hello world from a thread!, value is " << vec.at(0) << std::endl;
  });
  std::cout << "thread running!" << std::endl;
  t.join();
  std::cout << "thread after!" << std::endl;
  return 0;
}