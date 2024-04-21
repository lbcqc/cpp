//
// Created by root on 4/21/24.
//
#include <chrono>
#include <coroutine>
#include <iostream>
#include <thread>

class task {
 public:
  class promise_type {
   public:
    promise_type() { std::cout << "1. create promise." << std::endl; }
    task get_return_object() {
      std::cout << "2. create coroutine return object." << std::endl;
      return {std::coroutine_handle<task::promise_type>::from_promise(*this)};
    }
    std::suspend_never initial_suspend() {
      std::cout << "3.do you want to susupend the current coroutine?\n";
      std::cout << "4.don't suspend because return std::suspend_never, so continue to execute coroutine body\n";
      return {};
    }
    std::suspend_never final_suspend() noexcept {
      std::cout << "14. coroutine body finished, do you want to susupend the current coroutine?\n";
      std::cout << "15. don't suspend because return std::suspend_never, and the continue will be automatically "
                   "destroyed, bye\n";
      return {};
    }
    void return_void() { std::cout << "13. coroutine don't return value, so return_void is called\n"; }
    void unhandled_exception() {}
  };
  std::coroutine_handle<task::promise_type> handle_;
};

class awaiter {
 public:
  bool await_ready() {
    std::cout << "6. do you want to suspend coroutine? yes or no" << std::endl;
    std::cout << "7. yes, suspend because awaiter.await_read() return false" << std::endl;
    return false;
  }
  bool await_suspend(std::coroutine_handle<task::promise_type> handle) {
    std::cout << "8. execute awaiter.await_suspend()\n";
    std::thread([handle]() mutable {
      std::cout << "child thread id="<< std::this_thread::get_id()<< std::endl;
      handle();
    }).detach();
    std::cout << "9. a new thread lauched, and will return back to caller\n";
    return true;
  }
  void await_resume() { std::cout << "11. await_resume()" << std::endl; }
};

task test() {
  std::cout << "5.begin to execute coroutine body, the thread id=" << std::this_thread::get_id() << std::endl;
  co_await awaiter{};
  std::cout << "12. coroutine resumed, continue execcute coroutine body now, the thread id="
            << std::this_thread::get_id() << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "father thread id="<< std::this_thread::get_id()<< std::endl;
  test();
  std::cout << "10.come back to caller becuase of co_await awaiter\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  return 0;
}