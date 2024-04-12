//
// Created by root on 4/10/24.
//
#include <iostream>

// 类型推导：传值，会去掉引用和const，推到为原始类型
template <typename T>
void foo1(T t) {
  std::cout << "foo1(T t): " << typeid(t).name() << std::endl;
}

// 类型推导：引用，int &会推到为int &，其他情况会推导为原始类型
template <typename T>
void foo2(T &t) {
  std::cout << "foo2(T &t): " << typeid(t).name() << std::endl;
}

// 类型推导：万能引用，传左值进来就是左值，传右值进来就是右值
// 本质上是利用模板推导+引用折叠来生成不同的实例化模板接受参数
// int & & 折叠为 int&
// int & && 折叠为 int&
// int && & 折叠为 int&
// int && && 折叠为 int &&
template <typename T>
void foo3(T &&t) {
  std::cout << "foo3(T &&t): " << typeid(t).name() << std::endl;
}

template <typename _Tp>
_GLIBCXX_NODISCARD constexpr _Tp &&forward(typename std::remove_reference<_Tp>::type &__t) noexcept {
  std::cout << "forward &" << std::endl;
  return static_cast<_Tp &&>(__t);
}

template <typename _Tp>
_GLIBCXX_NODISCARD constexpr _Tp &&forward(typename std::remove_reference<_Tp>::type &&__t) noexcept {
  std::cout << "forward &&" << std::endl;
  static_assert(!std::is_lvalue_reference<_Tp>::value,
                "std::forward must not be used to convert an rvalue to an lvalue");
  return static_cast<_Tp &&>(__t);
}

template <typename T>
void print(T &t) {
  std::cout << "左值" << std::endl;
}

template <typename T>
void print(T &&t) {
  std::cout << "右值" << std::endl;
}

template <typename T>
void testForward(T &&v) {
  print(forward<T>(v));
}

int main(int argc, char *argv[]) {
  int a = 10;    // a is a lvalue
  int &b = a;    // b is lvalue reference, and b is lvalue
  int &&c = 10;  // c is rvalue reference，but c is lvalue
  // int &&d = a; // error, d is rvalue reference, but a is lvalue
  int &&d = std::move(a);
  // int &&e = b; // error, e is rvalue reference, but b is lvalue
  int &&e = std::move(b);
  int &&f = b + 10;  // ok, f is rvalue reference, b is lvalue, b+10 is rvalue
  int &g = f;        // f is lvalue

  // foo1
  int aa = 10;
  const int bb = 20;
  const int &cc = 30;
  int *dd = &aa;
  int &ee = aa;
  int &&ff = 10;
  foo1(aa);
  foo1(bb);
  foo1(cc);
  foo1(dd);
  foo1(ee);
  foo1(ff);
  foo1(40);

  foo2(aa);  // T is int
  foo2(bb);  // T is const int
  foo2(cc);  // T is const int&
  foo2(dd);  // T is int*
  foo2(ee);  // T is int&
  foo2(ff);  // T is int
  // foo2(40); // error，引用类型故而不允许传常量

  foo3(aa);  // T is int&
  foo3(ff);  // T is int&&
  foo3(40);  // T is int

  testForward(ee);       // forward &
  testForward(ff);       // forward &
  testForward(10);       // forward &
  testForward(10 + ff);  // forward &

  // rvalue reference can be modified
  int &&i = 1;
  i = i + 1;
  std::cout << i << std::endl;

  return 0;
}