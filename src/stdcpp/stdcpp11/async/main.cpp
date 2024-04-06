//
// Created by root on 4/7/24.
//
#include <future>
#include <iostream>
#include <thread>

int main(int argc, char** argv) {
  std::future<int> res = std::async(std::launch::async, []() { return 8; });
  std::cout << res.get() << std::endl;

  std::future<int> res2 = std::async(std::launch::async, []() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 18;
  });
  //  std::future_status status = res2.wait_for(std::chrono::seconds(1));
  //  while(status != std::future_status::ready){
  //    std::cout << "waiting for result" << std::endl;
  //    status = res2.wait_for(std::chrono::seconds(1));
  //  }
  res2.wait();
  std::cout << res2.get() << std::endl;
  return 0;
}