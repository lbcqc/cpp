//
// Created by root on 4/6/24.
//
#include <iostream>

class Poing{
 public:
  Poing(int _x, int _y):x(_x), y(_y){}
  friend constexpr std::strong_ordering operator<=>(const Poing &a, const Poing &b) {
    if (a.x < b.x) {
      return std::strong_ordering::less;
    }
    if (a.x > b.x) {
      return std::strong_ordering::greater;
    }
    if (a.y < b.y) {
      return std::strong_ordering::less;
    }
    if (a.y > b.y) {
      return std::strong_ordering::greater;
    }
    return std::strong_ordering::equivalent;
  }

 private:
  int x;
  int y;
};

void print_order(std::strong_ordering order) {
  if (order == std::strong_ordering::less) {
    std::cout << "less" << std::endl;
  } else if (order == std::strong_ordering::equal) {
    std::cout << "less" << std::endl;
  } else if  (order == std::strong_ordering::equivalent) {
    std::cout << "equivalent" << std::endl;
  } else if (order == std::strong_ordering::greater) {
    std::cout << "equivalent" << std::endl;
  } else {
    std::cout << "unknown" << std::endl;
  }
}

int main(int argc, char *argv[])
{
  int a{10};
  std::strong_ordering order{a <=> 1};
  print_order(order);

  Poing pa(10, 10);
  Poing pb(20, 0);
  std::strong_ordering porder{pa <=> pb};
  print_order(porder);

  return 0;
}
