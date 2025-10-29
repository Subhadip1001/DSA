#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};

static int idx = -1;
TreeNode *buildTree(vector<int> &tree)
{
    idx++;
    if (idx >= tree.size() || tree[idx] == -1)
        return NULL;

    TreeNode *root = new TreeNode(tree[idx]);
    root->left = buildTree(tree);
    root->right = buildTree(tree);

    return root;
}

TreeNode* findNode(TreeNode* root, int value) {
    if (!root) return NULL;
    if (root->val == value) return root;
    TreeNode* left = findNode(root->left, value);
    if (left) return left;
    return findNode(root->right, value);
}

// Leetcode: 236
// Lowest Common Ancestor of a Binary Tree

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    if (root == NULL) return NULL;

    if (root->val == p->val || root->val == q->val){
        return root;
    }

    TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA){
        return root;
    } else if (leftLCA != NULL){
        return leftLCA;
    } else{
        return rightLCA;
    }
}

int main(){
    vector<int> tree = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
    TreeNode* root = buildTree(tree);

    // Find nodes with given values (example: p = 5, q = 1)
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}
