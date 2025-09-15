//
// Created by root on 2025/9/14.
//
// 111. 二叉树的最小深度 https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
// 题解：递归查找，特别关注需要区分处理有两个子树和只有一个子树的情况
#include <algorithm>
#include <ios>
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
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    // 最多只有一个子树的情况
    if (root->left == nullptr || root->right==nullptr) {
      return max(minDepth(root->left), minDepth(root->right)) + 1;
    }
    // 有两个子树的情况
    return min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};