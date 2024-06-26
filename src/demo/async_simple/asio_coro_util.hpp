//
// Created by root on 4/21/24.
//

#ifndef CPPTEST_ASIO_CORO_UTIL_HPP
#define CPPTEST_ASIO_CORO_UTIL_HPP

#include <async_simple/coro/Lazy.h>
#include <async_simple/coro/SyncAwait.h>
#include <async_simple/executors/SimpleExecutor.h>

#include <chrono>
#include <concepts>

class AsioExecutor : public async_simple::Executor {
 public:
  AsioExecutor(asio::io_context &io_context) : io_context_(io_context) {}

  virtual bool schedule(Func func) override {
    asio::post(io_context_, std::move(func));
    return true;
  }

 private:
  asio::io_context &io_context_;
};

template <typename T>
  requires(!std::is_reference<T>::value) struct AsioCallbackAwaiter {
 public:
  using CallbackFunction =
      std::function<void(std::coroutine_handle<>, std::function<void(T)>)>;

  AsioCallbackAwaiter(CallbackFunction callback_function)
      : callback_function_(std::move(callback_function)) {}

  bool await_ready() noexcept { return false; }

  void await_suspend(std::coroutine_handle<> handle) {
    callback_function_(handle, [this](T t) { result_ = std::move(t); });
  }

  auto coAwait(async_simple::Executor *executor) noexcept {
    return std::move(*this);
  }

  T await_resume() noexcept { return std::move(result_); }

 private:
  CallbackFunction callback_function_;
  T result_;
};

inline async_simple::coro::Lazy<std::error_code> async_accept(
    asio::ip::tcp::acceptor &acceptor, asio::ip::tcp::socket &socket) noexcept {
  co_return co_await AsioCallbackAwaiter<std::error_code>{
      [&](std::coroutine_handle<> handle, auto set_resume_value) {
        acceptor.async_accept(
            socket, [handle, set_resume_value = std::move(
                                 set_resume_value)](auto ec) mutable {
              set_resume_value(std::move(ec));
              handle.resume();
            });
      }};
}

template <typename Socket, typename AsioBuffer>
inline async_simple::coro::Lazy<std::pair<std::error_code, size_t>>
async_read_some(Socket &socket, AsioBuffer &&buffer) noexcept {
  co_return co_await AsioCallbackAwaiter<std::pair<std::error_code, size_t>>{
      [&](std::coroutine_handle<> handle, auto set_resume_value) mutable {
        socket.async_read_some(
            std::move(buffer),
            [handle, set_resume_value = std::move(set_resume_value)](
                auto ec, auto size) mutable {
              set_resume_value(std::make_pair(std::move(ec), size));
              handle.resume();
            });
      }};
}

template <typename Socket, typename AsioBuffer>
inline async_simple::coro::Lazy<std::pair<std::error_code, size_t>> async_read(
    Socket &socket, AsioBuffer &buffer) noexcept {
  co_return co_await AsioCallbackAwaiter<std::pair<std::error_code, size_t>>{
      [&](std::coroutine_handle<> handle, auto set_resume_value) mutable {
        asio::async_read(
            socket, buffer,
            [handle, set_resume_value = std::move(set_resume_value)](
                auto ec, auto size) mutable {
              set_resume_value(std::make_pair(std::move(ec), size));
              handle.resume();
            });
      }};
}

template <typename Socket, typename AsioBuffer>
inline async_simple::coro::Lazy<std::pair<std::error_code, size_t>>
async_read_until(Socket &socket, AsioBuffer &buffer,
                 asio::string_view delim) noexcept {
  co_return co_await AsioCallbackAwaiter<std::pair<std::error_code, size_t>>{
      [&](std::coroutine_handle<> handle, auto set_resume_value) mutable {
        asio::async_read_until(
            socket, buffer, delim,
            [handle, set_resume_value = std::move(set_resume_value)](
                auto ec, auto size) mutable {
              set_resume_value(std::make_pair(std::move(ec), size));
              handle.resume();
            });
      }};
}

template <typename Socket, typename AsioBuffer>
inline async_simple::coro::Lazy<std::pair<std::error_code, size_t>> async_write(
    Socket &socket, AsioBuffer &&buffer) noexcept {
  co_return co_await AsioCallbackAwaiter<std::pair<std::error_code, size_t>>{
      [&](std::coroutine_handle<> handle, auto set_resume_value) mutable {
        asio::async_write(
            socket, std::move(buffer),
            [handle, set_resume_value = std::move(set_resume_value)](
                auto ec, auto size) mutable {
              set_resume_value(std::make_pair(std::move(ec), size));
              handle.resume();
            });
      }};
}

inline async_simple::coro::Lazy<std::error_code> async_connect(
    asio::io_context &io_context, asio::ip::tcp::socket &socket,
    const std::string &host, const std::string &port) noexcept {
  co_return co_await AsioCallbackAwaiter<std::error_code>{
      [&](std::coroutine_handle<> handle, auto set_resume_value) mutable {
        asio::ip::tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(host, port);
        asio::async_connect(
            socket, endpoints,
            [handle, set_resume_value = std::move(set_resume_value)](
                auto ec, auto size) mutable {
              set_resume_value(std::move(ec));
              handle.resume();
            });
      }};
}

#endif  // CPPTEST_ASIO_CORO_UTIL_HPP
