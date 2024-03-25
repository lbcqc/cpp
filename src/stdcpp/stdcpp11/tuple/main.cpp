//
// Created by root on 3/24/24.
//
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
  int num;
  double gpa;
  std::string name;
  std::tie(num, gpa, name) = get_student(1);
  std::cout << "num: " << num << ", gpa: " << gpa << ", name: " << name << std::endl;
  std::tuple<int, double, std::string> stu = get_student(2);
  double stu_gpa = std::get<1>(stu);
  std::cout << "stu_gpa: " << stu_gpa << std::endl;
  return 0;
}