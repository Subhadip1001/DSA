#include<iostream>
#include<vector>
using namespace std;

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

static int idx = -1;
TreeNode* buildTree(vector<int>& tree){
    idx++;
    if(tree[idx] == -1) return NULL;

    TreeNode* root = new TreeNode(tree[idx]);
    root->left = buildTree(tree);
    root->right = buildTree(tree);

    return root;
}

// Kth Level on a binary tree
void kthLevel(TreeNode* root, int k){
    if(root == NULL) return;

    if(k == 1){
        cout << root->val << " ";
        return;
    }

    kthLevel(root->left, k-1);
    kthLevel(root->right, k-1);
}

int main(){
    vector<int> tree = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    TreeNode* root = buildTree(tree);

    kthLevel(root, 3);
    return 0;
}