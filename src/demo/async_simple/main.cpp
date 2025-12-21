//
// Created by root on 4/21/24.
//
#include "async_simple/coro/Lazy.h"
#include "async_simple/coro/SyncAwait.h"
#include "async_simple/executors/SimpleExecutor.h"

async_simple::coro::Lazy<void> PrintThreadId() {
  std::cout << "PrintThreadId: thread id=" << std::this_thread::get_id() << "\n";
  co_return;
}

async_simple::coro::Lazy<void> TestPrintThreadId(async_simple::executors::SimpleExecutor &executor) {
  std::cout << "TestPrintThreadId: thread id=" << std::this_thread::get_id() << "\n";
  PrintThreadId().via(&executor).detach();
  co_return;
}

int main() {
  async_simple::executors::SimpleExecutor executor(/*thread_num=*/2);
  async_simple::coro::syncAwait(TestPrintThreadId(executor));
  return 0;
}