#pragma once 
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};
// 遍历
void Pre_order_iter(TreeNode* root);
void In_order_iter(TreeNode* root);
void Po_order_iter(TreeNode* root);
// 二叉树高度
int tree_height(TreeNode* root);
// 二叉树直径
int diameterOfBinaryTree(TreeNode* root);
// 验证二叉搜索树
bool isValidBST(TreeNode* root);
// 二叉搜索树的后序遍历
bool verifyPostorder(vector<int>& postorder);

// 根到叶子路径长度
bool hasPathSum(TreeNode* root, int targetSum);
// 根到叶节点数字之和
// 1，3，2 ==> 12 + 13
int sumNumbers(TreeNode* root);
// 对称二叉树
bool isSymmetric(TreeNode* root);
// 翻转二叉树
TreeNode* invertTree_pre_re(TreeNode* root);
TreeNode* invertTree_pre_iter(TreeNode* root);
TreeNode* invertTree_po_re(TreeNode* root);
TreeNode* invertTree_in_re(TreeNode* root);
TreeNode* invertTree_bfs(TreeNode* root);

// 二叉树的完全性检验
bool isCompleteTree(TreeNode* root);

// 根据中序和前序构建二叉树
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

// 节点之和的最大路径
// 后序遍历
int maxPathSum(TreeNode* root);


// 序列化与反序列化二叉树
string serialize(TreeNode* root);
TreeNode* deserialize(string data);
