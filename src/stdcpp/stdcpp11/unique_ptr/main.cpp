//
// Created by root on 24-4-17.
//
#include <iostream>
#include <memory>

class Foo : public std::enable_shared_from_this<Foo> {
  public:
  Foo() { std::cout << "Foo::Foo" << std::endl; }
  ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
  void foo() { std::cout << "Foo::foo" << " " << std::endl; }
};

void f(const Foo &) {
  std::cout << "f(const Foo&)" << std::endl;
}

int main() {
  std::unique_ptr<Foo> p1 = std::make_unique<Foo>();
  std::shared_ptr<Foo> haha = std::move(p1);
  // p1 不空, 输出
  if (p1) {
    std::cout << "p1 ";
    p1->foo();
  }
  if (haha) {
    std::cout << "haha ";
    haha->foo();
  }
  {
    std::unique_ptr<Foo> p2(std::move(p1));
    // p2 不空, 输出
    f(*p2);
    // p2 不空, 输出
    if(p2) p2->foo();
    // p1 为空, 无输出
    if(p1) p1->foo();
    p1 = std::move(p2);
    // p2 为空, 无输出
    if(p2) p2->foo();
    std::cout << "p2 被销毁" << std::endl;
  }
  // p1 不空, 输出
  if (p1) p1->foo();
  // Foo 的实例会在离开作用域时被销毁
}