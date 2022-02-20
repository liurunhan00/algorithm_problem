#include <bits/stdc++.h>
#include <ios>
#include "Tree.h"
// zc | 折叠 zo | 展开折叠
// za，打开或关闭当前折叠；zM，关闭所有折叠；zR，打开所有折叠
void Pre_order_iter(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* top = st.top();
        std::cout << top->val << " ";
        st.pop();
        if (top->right) st.push(top->right);
        while (top->left) {
            top = top->left;
            if (top->right) st.push(top->right);
            std::cout << top->val << " ";
        }
    }
    std::cout << std::endl;
}
void  In_order_iter(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    TreeNode* p = root;
    while (!st.empty() || p) {
        while (p) {
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            p = st.top();
            std::cout << p->val << " ";
            st.pop();
            p = p->right;
        }  
    }
    std::cout << std::endl;
}

void  Po_order_iter(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    TreeNode* cur;
    TreeNode* pre = nullptr;
    st.push(root);
    while (!st.empty()) {
        // 思路：子节点若都访问过|子节点为空 则可访问 
        cur = st.top();
        if ((cur->left == nullptr && cur->right == nullptr) ||
            (pre &&(pre != cur->left || pre != cur->right))) {
            std::cout << cur->val << " ";
            st.pop();
            pre = cur;
        } else {
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
    }
    std::cout << std::endl;
}

int tree_height(TreeNode *root) {
    if (!root) return 0;
    return max(tree_height(root->left) + 1, tree_height(root->right) + 1);
}

// 二叉树直径
static int max_d = 0;
int dfs_d(TreeNode* root) {
    if (!root->left && !root->right) return 0;
    int left_d = root->left == nullptr ? 0: dfs_d(root->left) + 1;
    int right_d = root->right == nullptr ? 0: dfs_d(root->right) + 1;
    max_d  = max(max_d, left_d + right_d);
    return max(left_d, right_d);
}


int diameterOfBinaryTree(TreeNode *root) {
    // 函数内部的static只能在函数内部访问但是值不会消失
    static int t;
    if (!root) return 0;
    dfs_d(root);
    return max_d;
}

static int Minval = INT_MIN;
bool isValidBST(TreeNode *root) {
    if (!root) return true;
    isValidBST(root->left);
    if (Minval > root->val) return false;
    else {
        Minval = root->val;
    }
    isValidBST(root->right);
    return true;
}

static bool hasPathflag = false;
void dfs_has_path(TreeNode *root, int targetSum) {
    if (!root) return; 
    if (root->left == nullptr && root->right == nullptr) {
        if ( root->val == targetSum) {
            hasPathflag = true;
        } 
        return;
    }
    dfs_has_path(root->left, targetSum - root->val);
    dfs_has_path(root->right, targetSum - root->val);
}

bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    hasPathflag = false;
    dfs_has_path(root, targetSum); 
    return hasPathflag;
}

// 镜像二叉树
static bool Symmet_flag = true;
void dfs_isSymmetric(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) return;
    if (!root1 || !root2) {
        Symmet_flag = false;
        return;
    }
    if (root1->val != root2->val) {
        Symmet_flag = false;
        return;
    }
    dfs_isSymmetric(root1->left, root2->right);
    dfs_isSymmetric(root1->right, root2->left);
}

    
bool isSymmetric(TreeNode *root) {
    Symmet_flag = true;
    dfs_isSymmetric(root, root);
    return Symmet_flag;
}

// 交换左右孩子
TreeNode* invertTree_pre_re(TreeNode *root) {
    if (!root) return nullptr;
    swap(root->left, root->right);
    invertTree_pre_re(root->left);
    invertTree_pre_re(root->right);
    return root;
}
TreeNode* invertTree_pre_iter(TreeNode* root) {
    stack<TreeNode*> st;
    if (!root) return nullptr;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        swap(node->left, node->right);
        // node->left 放前面也行
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return root;
}

// ！！！中序递归
TreeNode* invertTree_in_re(TreeNode* root) {
    if (!root) return root;
    invertTree_in_re(root->left);
    swap(root->left, root->right);
    // 左右交换已经完成了所以还是left
    invertTree_in_re(root->left);
    return root;
}

// 后序递归
TreeNode* invertTree_po_re(TreeNode* root) {
    if (!root) return root;
    invertTree_po_re(root->left);
    invertTree_po_re(root->right);
    swap(root->left, root->right);
    return root;
}
// 层次遍历交换
TreeNode* invertTree_bfs(TreeNode* root) {
    std::queue<TreeNode*> que;
    if (root) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* front = que.front();
            que.pop();
            swap(front->left, front->right);
            if (front->left) que.push(front->left);
            if (front->right) que.push(front->right);
        }
    }
    return root;
}

// 遇到空节点后在遇到非空即为false
// 第一次遇到push empty node
// 的题目
bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    if (!root) return true;
    q.push(root);
    bool com_flag = false;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (!top) com_flag = true;
        if (top) {
            if (com_flag) {
                return false;
            } 
            q.push(top->left);
            q.push(top->right);
        }
    }
    return true;
}

// 重建二叉树
TreeNode* rebuildTree(int root, int left, int right, unordered_map<int, int>& u_map, const vector<int>& preorder) {
    if (left > right) return nullptr;
    TreeNode* node = new TreeNode(preorder[root]);
    int i = u_map[preorder[root]]; // root中序位置
    node->left = rebuildTree(root + 1, left, i - 1, u_map, preorder);
    node->right = rebuildTree(root + i - left + 1, i + 1, right, u_map, preorder);
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    unordered_map<int, int> u_map;
    for (int i = 0; i < n; ++i) {
        u_map[inorder[i]] = i;
    }
    return rebuildTree(0, 0, n - 1, u_map, preorder);
}

// 最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return root;
    if (p->val == root->val || q->val == root->val) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    if (right) return right;
    return left;
}

// 二叉树转双向链表
TreeNode* treeToDouble_prev = nullptr, *treeToDouble_head = nullptr;
void treeToDoublyList_dfs(TreeNode* root) {
    if (!root) return;
    treeToDoublyList_dfs(root->left);
    if (treeToDouble_prev == nullptr) treeToDouble_head = root;
    else {
        treeToDouble_prev->right = root; 
    }
    root->left = treeToDouble_prev;
    treeToDouble_prev = root;
    treeToDoublyList_dfs(root->right);
}
TreeNode* treeToDoublyList(TreeNode* root) {
    if (!root) return nullptr;
    treeToDoublyList_dfs(root);
    treeToDouble_head->left = treeToDouble_prev;
    treeToDouble_prev->right = treeToDouble_head;
    return treeToDouble_head;
}

// BST展平二叉搜索树
TreeNode* increasingBST_prev = nullptr;
TreeNode* increasingBST_head = nullptr;
void increasingBST_dfs(TreeNode* root) {
    if (!root) return;
    increasingBST_dfs(root->left);
    if (!increasingBST_prev) {
        increasingBST_prev = root;
        increasingBST_head = root;
    } else {
        root->left = nullptr;
        increasingBST_prev->left = nullptr;
        increasingBST_prev->right = root;
        increasingBST_prev = root;
    }
    increasingBST_dfs(root->right);
}

TreeNode* increasingBST(TreeNode* root) {
    increasingBST_dfs(root);
    return increasingBST_head;
}

// BST 节点的中序后继
bool inorderSuccessor_flag = false;
TreeNode* inorderSuccessor_cur = nullptr;
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (!root) return nullptr;
    inorderSuccessor(root->left, p);
    if (inorderSuccessor_flag) {
        inorderSuccessor_cur = root;
        inorderSuccessor_flag = false;
    }
    if (root == p) {
        inorderSuccessor_flag = true;
    } 
    inorderSuccessor(root->right, p);
    return inorderSuccessor_cur;
}

// BST所有大于等于节点值之和
// 将它的每个节点替换成大于等于该节点值的所有节点值之和
TreeNode* convertBST_prev = nullptr;
TreeNode* convertBST(TreeNode* root) {
    // 右中左的中序
    if (!root) return nullptr;
    convertBST(root->right);
    if (!convertBST_prev) {
        convertBST_prev = root;
    } else {
        root->val += convertBST_prev->val;
        convertBST_prev = root;
    }
    convertBST(root->left);
    return root;
}

// 节点之和最大的路径
static int maxPathsum = INT_MIN;
int max_dfs(TreeNode* root) {
    if (!root) return 0;
    int left_d = max_dfs(root->left);
    int right_d = max_dfs(root->right);
    int cursum = (left_d > 0 ? left_d: 0) + (right_d > 0 ? right_d: 0) + root->val;
    maxPathsum = max(maxPathsum, cursum);
    if (left_d < 0 && right_d < 0) return root->val;
    return left_d > right_d ? root->val + left_d: root->val + right_d; 
}
int maxPathSum(TreeNode* root) {
    max_dfs(root);
    return maxPathsum;
}

// 


