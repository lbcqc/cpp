//
// Created by root on 4/21/24.
//
#include <unordered_map>
#include <iostream>

int main(int argc, char **argv) {
    std::unordered_map<char, int> m;

    for (int i = 0; i < 10; i++) {
        m['a'+i] = 'a' + i;
    }

    for (auto const &v: m) {
      std::cout << v.first << " " << v.second<< std::endl;
    }

    return 0;
}