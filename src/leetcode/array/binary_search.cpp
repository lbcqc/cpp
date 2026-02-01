//
// Created by root on 5/9/24.
//
#include <iostream>
#include <vector>

template <typename T>
class Searcher {
 public:
  virtual int Search(std::vector<T> &vec, T val) = 0;
};

template <typename T>
class BinarySearch : public Searcher<T> {
 public:
  int Search(std::vector<T> &vec, T val) noexcept override final {
    return SearchImplByCircle(vec, val, 0, static_cast<int>(vec.size()) - 1);
  }

 private:
  // 递归实现
  int SearchImplByRecursion(std::vector<T> &vec, int val, int left, int right) noexcept {
    if (left > right) {
      return -1;
    }
    int mid = (left + right) / 2;
    if (val == vec[mid]) {
      return mid;
    }
    if (val < vec[mid]) {
      return SearchImplByRecursion(vec, val, left, mid - 1);
    }
    return SearchImplByRecursion(vec, val, mid + 1, right);
  }
  // 迭代实现
  int SearchImplByCircle(std::vector<T> &vec, int val, int left, int right) noexcept {
    while (left <= right) {
      int mid = (left + right) / 2;
      if (val == vec[mid]) {9
        return mid;
      }
      if (val < vec[mid]) {
        right = mid - 1;
        continue;
      }
      left = mid + 1;
    }
    return -1;
  }
};

int main(int argc, char **argv) {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  BinarySearch<int> bs;
  std::cout << bs.Search(vec, 3) << std::endl;
  return 0;
}

// class Solution {
//  public:
//   int search(std::vector<int>& nums, int target) noexcept{
//     BinarySearch<int> bs;
//     return bs.Search(nums, target);
//   }
// };
