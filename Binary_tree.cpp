//Construct Binary tree , Inorder Traversal

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

Node* CreateTree(){
    int value;
    cout << "Enter data(-1 for no node): ";
    cin >> value;

    if(value == -1)
        return NULL;

    Node* newNode = new Node(value);

    cout <<"Enter left child of "<< value << endl;
    newNode->left = CreateTree();
   
    cout <<"Enter right child of "<< value << endl;
    newNode->right = CreateTree();

    return newNode;
}

//Inorder traversal

void inorder(Node* root){
    if( root == NULL)
        return;

    inorder( root->left );
    cout<< root->data << " ";
    inorder( root->right);

}

int main(){
    Node* root = NULL;

    cout << "Construct Binary Tree"<< endl;
    root = CreateTree();

    cout << "\nInorder Traversal: ";
    inorder(root);

    return 0;
}