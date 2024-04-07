//
// Created by root on 4/7/24.
//

class A {
 public:
  class X{};
  int X;
};

class B{
 public:
  class X{};
};

template <typename T>
int foo(T t){
  typename T::X x;
}

int main(int argc, char** argv) {
  A a;
  //foo(a);

  B b;
  foo(b);
  return 0;
}