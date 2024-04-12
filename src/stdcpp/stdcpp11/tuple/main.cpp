//
// Created by root on 3/24/24.
//
#include <fmt/ranges.h>
#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> get_student(int num) {
  switch (num) {
    case 0:
      return std::make_tuple(0, 0.1, "hello 0");
    case 1:
      return std::make_tuple(1, 1.1, "hello 1");
    default:
      return std::make_tuple(2, 2.1, "hello 2");
  }
}

int main(int argc, char *argv[]) {
  // std::tie
  int num;
  double gpa;
  std::string name;
  std::tie(num, gpa, name) = get_student(1);
  std::cout << "num: " << num << ", gpa: " << gpa << ", name: " << name << std::endl;

  // std::get
  std::tuple<int, double, std::string> stu = get_student(2);
  double stu_gpa = std::get<1>(stu);
  std::cout << "stu_gpa: " << stu_gpa << std::endl;

  // std::tuple_cat
  auto cat = std::tuple_cat(get_student(2), std::move(stu));
  fmt::print("cat: {}\n", cat);
  fmt::print("stu: {}\n", stu);
  return 0;
}