//BST traversal inorder, preorder and postorder,search(x)
#include<iostream>
#include<queue>
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
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root){
    if(root == NULL)
        return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if(temp->left != NULL)
            q.push(temp->left);

        if(temp->right != NULL)
            q.push(temp->right);
    }
}


Node* search(Node* root, int x){

    Node* r = root;

    while(r != NULL){

        if(r->data == x){
            cout << x << " found in BST!";
            return r;
        }

        else if(x < r->data){
            r = r->left;
        }

        else{
            r = r->right;
        }
    }

    cout << x << " does not exist. Search failed!";
    return NULL;
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

    cout << "\nLevel Order Traversal: ";
    levelorder(root);

    int x;
    cout << "\nEnter what you want to search: ";
    cin >> x;

    Node* k = search(root, x);

    if(k != NULL)
        cout << x << " found in BST!";
    else
        cout << x << " does not exist. Search failed!";

}

