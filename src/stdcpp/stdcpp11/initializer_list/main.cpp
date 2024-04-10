//
// Created by root on 4/6/24.
//

#include <iostream>
#include <memory>
#include <string>

template<typename Tp>
class MyList{
 public:
  explicit MyList(Tp _v): v(_v), next(nullptr){}
  MyList(std::initializer_list<Tp> args){
    MyList<Tp> *tail = this;
    tail->v = 0;
    for (auto &&arg : args) {
      tail->next = std::make_shared<MyList<Tp>>(arg);
      tail = tail->next.get();
    }
  }
  void insert(std::initializer_list<Tp> args) {
    for(const auto &arg : args) {
      auto node = std::make_shared<MyList<Tp>>(arg);
      node->next = this->next;
      this->next = node;
    }
  }
  std::string to_string(){
    MyList<Tp> *tail = this;
    std::string out;
    while (tail->next){
      tail = tail->next.get();
      out += std::to_string(tail->v);
      out += "->";
    }
    return out;
  }
 private:
  Tp v;
  std::shared_ptr<MyList<Tp>> next;
};

class pod{
  public:
   int a;
   int b;
};

template<typename T, typename... Ts>
void printf3(T value, Ts... args) {
  std::cout << value << " ";
  (void) std::initializer_list<T>{([&args] {
    std::cout << args << " ";
  }(), T{})...}; // 必须要有一个T{}未使用的参数触发逗号表达式执行前面的 lambda，否则会报错
  std::cout << std::endl;
}

int main(int argc, char *argv[])
{
  // array init list
  int arr[] = {1,2,3,4,5,6};
  std::cout << "array init list: " << "arr[5]: "<< arr[5] << std::endl;

  // POD init list
  pod a = {1,2};
  std::cout << "pod init a.a: " << a.a << ", a.b: " << a.b << std::endl;

  // initializer list
  MyList<int> l = {1,2,3,4,5,6};
  std::cout << "initialize list for constructor: " << l.to_string() << std::endl;
  l.insert({7,8,9});
  std::cout << "initialize list for member func: " << l.to_string() << std::endl;

  // initializer list for function
  printf3(1,2.0,3.0,4.0,5.0,6.0);
  return 0;
}