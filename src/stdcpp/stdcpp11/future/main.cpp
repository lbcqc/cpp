//
// Created by root on 4/20/24.
//
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

int main(int argc, char **argv) {
  std::packaged_task<int()> task([]() -> int {
    std::cout << "task done" << std::endl;
    return 10;
  });

  std::future<int> v = task.get_future();
  std::thread(std::move(task)).detach();
  std::cout << "wait..." << std::endl;
  v.wait();
  std::cout << v.get() << std::endl;
  return 0;
}