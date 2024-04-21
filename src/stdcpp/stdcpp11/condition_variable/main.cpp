//
// Created by root on 4/20/24.
//
#include <array>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <thread>

std::queue<int> q;
std::mutex mut;
std::condition_variable cv;
bool notify = false;
bool done = false;

void producer() {
  for (int i = 0; i < 10; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lk(mut);
    q.push(i);
    notify = true;
    std::cout << "produced: " << i << std::endl;
    cv.notify_all();
  }
  done = true;
}

void consumer() {
  while (!done) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::unique_lock<std::mutex> lk(mut);
    while (!notify && !done) {
      cv.wait(lk);
    }
    if (done) {
      break;
    }
    //    if (!notify) {
    //      std::cout << "forbidden dead lock" << std::endl;
    //      continue;
    //    }
    int val = q.front();
    q.pop();
    std::cout << "Consumed: " << std::this_thread::get_id() << ", value: " << val << std::endl;
    notify = false;
  }
}

int main(int argc, char **argv) {
  std::thread t1(producer);
  std::array<std::thread, 2> t2;
  for (auto &t : t2) {
    t = std::thread(consumer);
  }
  t1.join();
  std::cout << "producer thread finish" << std::endl;
  for (auto &t : t2) {
    t.join();
  }
  std::cout << "consumer thread finish" << std::endl;
  return 0;
}