#include<iostream>
#include<vector>
using namespace std;

// LeetCode: 572
// Subtree of Another Tree

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

// Make a tree
TreeNode* buildTree(vector<int>& tree, int& idx){
    idx++;
    if(tree[idx] == -1) return NULL;

    TreeNode* root = new TreeNode(tree[idx]);
    root->left = buildTree(tree, idx);
    root->right = buildTree(tree, idx);

    return root;
}

bool isIdentical(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL)
        return p == q; // handles all NULL cases safely

    return p->val == q->val
        && isIdentical(p->left, q->left)
        && isIdentical(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL)return subRoot == NULL;

    if (isIdentical(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main(){
    vector<int> tree = {3,4,-1,-1,1,2,-1,-1,3,-1,-1};
    vector<int> subTree = {1,2,-1,-1,3,-1,-1};

    int treeIdx = -1;
    TreeNode* root = buildTree(tree, treeIdx);

    int subTreeIdx = -1;
    TreeNode* subRoot = buildTree(subTree, subTreeIdx);

    cout << isSubtree(root, subRoot) << endl;

    return 0;
}