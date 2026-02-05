//
// Created by root on 2026/2/5.
//
// 236. 二叉树的最近公共祖先 https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=problem-list-v2&envId=2cktkvj
// 题解：使用深度优先搜索，一旦左子节点和右子节点均发现 p q，则当前节点即是共同的父节点
// 注意，这里要同时考虑当前节点本身就是 p q 的情况。

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* ans;
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || p == nullptr || q == nullptr)
      return nullptr;
    lowestCommonAncestorImpl(root, p, q);
    return ans;
  }
  bool lowestCommonAncestorImpl(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return false;
    bool left = lowestCommonAncestorImpl(root->left, p, q);
    bool right = lowestCommonAncestorImpl(root->right, p, q);
    if ((left && right) || ((root->val == p->val || root->val == q->val) && (left||right))) {
      ans = root;
    }
    return left || right || root->val == p->val  || root->val == q->val;
  }
};
