//BST traversal inorder, preorder and postorder
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value){
    if(root == NULL)
        return new Node(value);
    
    if( value < root->data )
        root->left = insert(root->left, value);

    else if( value > root->data )
        root->right = insert(root->right, value);
    
    return root;
}

void inorder(Node* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;
    int n,val;

    cout<<"Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n;  i++){
        cout << "Enter value: ";
        cin >> val;

        root = insert(root,val);
    }

    cout << "\nInOrder Traversal of BST: ";
    inorder(root);

    cout << "\nPreOrder Traversal of BST: ";
    preorder(root);

    cout << "\nPostOrder Traversal of BST: ";
    postorder(root);

}

