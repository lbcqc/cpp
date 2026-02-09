//
// Created by root on 2026/2/9.
//
// 208. 实现 Trie (前缀树) https://leetcode.cn/problems/implement-trie-prefix-tree/description/?envType=problem-list-v2&envId=2cktkvj
// 题解

#include <iostream>
#include <string>
using namespace std;

class Trie {
public:
  Trie() {
    left = nullptr;
    right = nullptr;
    word = "";
  }
  Trie(string word) {
    this->left = nullptr;
    this->right = nullptr;
    this->word = word;
  }

  void insert(string word) {
    if (this->word <= word) {
      if (this->right!=nullptr) {
        this->right->insert(word);
        return;
      }
      this->right = new Trie(word);
      return;
    }
    if (this->left!=nullptr) {
      this->left->insert(word);
      return;
    }
    this->left = new Trie(word);
    return;
  }

  bool search(string word) {
    if (this->word == word) {
      return true;
    }
    if (this->word <= word && this->right!=nullptr) {
      return this->right->search(word);
    }
    if (this->word > word && this->left!=nullptr) {
      return this->left->search(word);
    }
    return false;
  }

  bool startsWith(string prefix) {
    if (this->word.starts_with(prefix)) {
      return true;
    }
    if (this->word <= prefix && this->right!=nullptr) {
      return this->right->startsWith(prefix);
    }
    if (this->word > prefix && this->left!=nullptr) {
      return this->left->startsWith(prefix);
    }
    return false;
  }
private:
  class Trie* left;
  class Trie* right;
  string word;
};

int main() {
  Trie* obj = new Trie();
  obj->insert("apple");
  // cout << obj->search("apple") << endl;
  cout <<  obj->startsWith("a") << endl;
  return 0;
}
