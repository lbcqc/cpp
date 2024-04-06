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

int main(int argc, char *argv[])
{
  MyList<int> l = {1,2,3,4,5,6};
  std::cout << l.to_string() << std::endl;
  return 0;
}