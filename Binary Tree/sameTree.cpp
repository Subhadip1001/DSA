#include<iostream>
#include<vector>
using namespace std;

// LeetCode : 100
// Same Tree

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

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==NULL || q==NULL) return p==q;

    int isLeftSame = isSameTree(p->left, q->left);
    int isRightSame = isSameTree(p->right, q->right);

    return isLeftSame && isRightSame && p->val == q->val;
}

int main(){
    // Test case 1
    // vector<int> tree1 = {1,2,-1,-1,-1};
    // vector<int> tree2 = {1,-1,2,-1,-1};

    // Test case 2
    vector<int> tree1 = {1,2,-1,-1,3,-1,-1};
    vector<int> tree2 = {1,2,-1,-1,3,-1,-1};

    // Test case 3
    // vector<int> tree1 = {1,3,-1,-1,2,-1,-1};
    // vector<int> tree2 = {1,2,-1,-1,3,-1,-1};

    int idx1 = -1;
    TreeNode* rootP = buildTree(tree1, idx1);
    
    int idx2 = -1;
    TreeNode* rootQ = buildTree(tree2, idx2);

    cout << isSameTree(rootP, rootQ) << endl;
    return 0;
}