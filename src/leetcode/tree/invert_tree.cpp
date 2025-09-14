//
// Created by root on 2025/9/14.
//
// 226. 翻转二叉树 https://leetcode.cn/problems/invert-binary-tree/description/
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};