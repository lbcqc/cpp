//
// Created by root on 2025/9/14.
//
// 98. 验证二叉搜索树 https://leetcode.cn/problems/validate-binary-search-tree/description/
// 题解：这里不只是判断左节点小于父节点、右节点大于父节点，关键是要小于或大于整个子树的值
// 注意：这里如果给一个初始最大最小值，要关注 INT 越界的情况
#include <cstdint>
#include <climits>
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
  bool isValidBST(TreeNode* root) {
    return checkBST(root, INT64_MIN, INT64_MAX);
  }
  bool checkBST(TreeNode* root, const long min, const long max) {
    // 边界条件
    if (root == nullptr) return true;
    // 剪枝
    long val = static_cast<long>(root->val);
    if (val <= min || val >= max ) return false;
    // 递归
    return checkBST(root->left, min, val) && checkBST(root->right, val, max);
  }
};