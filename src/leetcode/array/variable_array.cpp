//
// Created by Administrator on 2025/8/23.
//
// 变长数组
// 题解：使用 unique_ptr 来管理数组，使用 realloc 来动态调整数组容量
// 使用 push_back 来添加元素，使用 pop_back 来删除元素
// 使用 operator[] 来访问元素
// 使用 size() 来获取数组大小
// 使用 cap() 来获取数组容量
// 注意：本题需要使用 C++17 的特性，使用 unique_ptr 来管理数组
// 注意：本题需要使用 C++17 的特性，使用 unique_ptr 来管理数组

#include <iostream>
#include <memory>

class VariableArray {
 private:
  std::unique_ptr<int[]> _data;
  int _size;
  int _cap;
  static const int min_cap = 16;

 private:
  void reaclloc(int new_cap) {
    std::unique_ptr<int[]> new_data = std::make_unique<int[]>(this->_cap);
    for (int i = 0; i < this->_size; i++) {
      new_data[i] = this->_data[i];
    }
    this->_data = std::move(new_data);
  }

 public:
  explicit VariableArray(const int cap = VariableArray::min_cap) : _cap(cap) {
    // 不允许创建容量为0的数组
    if (this->_cap < VariableArray::min_cap) {
      this->_cap = VariableArray::min_cap;
    }
    this->_data = std::make_unique<int[]>(this->_cap);
    this->_size = 0;
  }
  void push_back(const int val) {
    if (this->_size == this->_cap) {
      this->reaclloc(this->_cap *= 2);
    }
    this->_data[this->_size++] = val;
  }
  int pop_back() {
    if (this->_size == 0) {
      throw std::out_of_range("数组为空");
    }
    return this->_data[--this->_size];
  }
  int& operator[](const int i) {
    if (i >= this->_size) {
      throw std::out_of_range("数组越界");
    }
    return this->_data[i];
  }
  [[nodiscard]] int size() const { return this->_size; }
  [[nodiscard]] int cap() const { return this->_cap; }
};

int main(int argc, char** argv) {
  VariableArray var;
  var.push_back(10);
  std::cout << "var[0]: " << var[0] << ", len: " << var.size() << ", cap: " << var.cap() << std::endl;
  return 0;
}