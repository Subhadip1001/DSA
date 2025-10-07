#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
// Create a binary tree
Node* buildTree(vector<int>& preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); // LEFT
    root->right = buildTree(preorder); // RIGHT

    return root;
}

// Traversals
void preOrder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    cout << "Preorder traversal : ";
    preOrder(root);
    cout << endl;
    
    cout << "Inorder traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Postorder traversal : ";
    postOrder(root);
    cout << endl;

    return 0;
}