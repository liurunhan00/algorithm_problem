#include "Tree.h"
#include <ios>

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *left_l_child = new TreeNode(3);
    TreeNode *right = new TreeNode(4);
    root->left = left;
    left->left = left_l_child;
    root->right = right;
    
    TreeNode *Symroot = new TreeNode(1);
    TreeNode *Symroot_left = new TreeNode(2);
    TreeNode *Symroot_right = new TreeNode(2);
    Symroot->left = Symroot_left;
    Symroot->right = Symroot_right;

    TreeNode *inComroot = new TreeNode(1);
    TreeNode *inComroot_left = new TreeNode(2);
    TreeNode *inComroot_right = new TreeNode(3);
    TreeNode *inComroot_right_left = new TreeNode(6);
    inComroot->left = inComroot_left;
    inComroot->right = inComroot_right;
    inComroot_right->left = inComroot_right_left;

    cout << tree_height(root) << endl;
    cout << boolalpha << isValidBST(root) << endl;
    cout << boolalpha << hasPathSum(root, 5) << endl;
    cout << boolalpha << isSymmetric(root) << endl;
    cout << boolalpha << isSymmetric(Symroot) << endl;

    Pre_order_iter(root);
    In_order_iter(root);
    Po_order_iter(root);
    Pre_order_iter(Symroot);
    In_order_iter(Symroot);
    Po_order_iter(Symroot);

    
    cout << isCompleteTree(root) << ' ' << isCompleteTree(Symroot) << ' ' << isCompleteTree(inComroot)<< endl;
    vector<int> preorder = {3, 2, 1, 4};
    vector<int> inorder = {1, 2, 3, 4};
    Pre_order_iter(buildTree(preorder, inorder));

}
