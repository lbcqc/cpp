//
// Created by root on 4/25/24.
//
#include <boost/type_index.hpp>
#include <iostream>

template <typename T>
void foo(const T& param) {
  std::cout << "T = " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << std::endl;
  std::cout << "param = " << boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}

class Widget {};

int main(int argc, char** argv) {
  Widget w = {};
  foo(&w);
  return 0;
}