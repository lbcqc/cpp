//
// Created by root on 4/6/24.
//
#include <iostream>

enum Global{
  Unknown = 0,
};

//enum Global2 { // conflict with Global Unknown, which will lead to compile error
//  Unknown = 1,
//};

enum struct LimitEnum1 { // don't conflict with Global Unknown
  Unknown = 2,
};

enum class LimitEnum2 { // don't conflict with Global Unknown
  Unknown = 3,
};

//using enum LimitEnum2; // since by c++20，Unknown is expressed as LimitENum2::Unknown

int main(int argc, char *argv[])
{
  std::cout << "Global::Unknown = " << static_cast<int>(Unknown) << std::endl;
  std::cout << "LimitEnum1::Unknown = " << static_cast<int>(LimitEnum1::Unknown) << std::endl;
  std::cout << "LimitEnum2::Unknown = " << static_cast<int>(LimitEnum2::Unknown) << std::endl;
  return 0;
}