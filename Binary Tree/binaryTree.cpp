#include<iostream>
#include<vector>
#include<queue>
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

void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout << curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

    cout << endl;
}

// Hight of a Tree
int hightOfTree(Node* root){
    if(root == NULL) return 0;

    int leftHight = hightOfTree(root->left);
    int rightHight = hightOfTree(root->right);

    return max(leftHight, rightHight)+1;
}

// Count Nodes in the Tree
int countNode(Node*  root){
    if(root == NULL) return 0;

    int leftNodes = countNode(root->left);
    int rightNodes = countNode(root->right);

    return (leftNodes+rightNodes+1);
}

// Sum of Nodes
int sumOfNodes(Node* root){
    if(root == NULL) return 0;

    int leftNodes = sumOfNodes(root->left);
    int rightNodes = sumOfNodes(root->right);

    return (leftNodes+rightNodes+root->data);
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

    cout << "Levelorder traversal :\n";
    levelOrder(root);

    cout << "Height of this binary tree is : " << hightOfTree(root) << endl;

    cout << "Total nodes in this tree are : " << countNode(root) << endl;

    cout << "Sum of the nodes is : " << sumOfNodes(root) << endl;

    return 0;
}