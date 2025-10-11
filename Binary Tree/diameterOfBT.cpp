#include<iostream>
#include<vector>
using namespace std;

// LeetCode : 543
// Diameter of Binary Tree

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
    if(tree[idx] == -1){
        return NULL;
    }

    TreeNode* root = new TreeNode(tree[idx]);
    root->left = buildTree(tree);
    root->right = buildTree(tree);

    return root;
}

int ans = 0;
int height(TreeNode* root){
    if(root == NULL) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    ans = max(ans, leftHt+rightHt);

    return max(leftHt, rightHt)+1;
}

int diameterOfBinaryTree(TreeNode* root){
    height(root);

    return ans;
}

int main(){
    vector<int> tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    TreeNode* root = buildTree(tree);
    int diameter = diameterOfBinaryTree(root);
    cout << diameter << endl;

    return 0;
}