//BST traversal inorder, preorder and postorder,search(x),del(x)
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

Node* del(Node* root, int x){

    Node* r = root;
    Node* p = NULL;

    // Search for the node
    while(r != NULL && r->data != x){
        p = r;

        if(x < r->data)
            r = r->left;
        else
            r = r->right;
    }

    // Key does not exist
    if(r == NULL){
        cout << "Key does not exist in BST!";
        return root;
    }

    // CASE 1: Node has no children
    if(r->left == NULL && r->right == NULL){

        if(p == NULL)
            root = NULL;

        else if(r == p->left)
            p->left = NULL;

        else
            p->right = NULL;

        delete r;
    }

    // CASE 2A: Only right child
    else if(r->left == NULL){

        Node* child = r->right;

        if(p == NULL)
            root = child;

        else if(r == p->left)
            p->left = child;

        else
            p->right = child;

        delete r;
    }

    // CASE 2B: Only left child
    else if(r->right == NULL){

        Node* child = r->left;

        if(p == NULL)
            root = child;

        else if(r == p->left)
            p->left = child;

        else
            p->right = child;

        delete r;
    }

    // CASE 3: Node has two children
    else{

        Node* suc = r->right;
        Node* sp = r;

        // Find inorder successor
        while(suc->left != NULL){
            sp = suc;
            suc = suc->left;
        }

        // Replace data
        r->data = suc->data;

        // Remove successor from original position
        if(sp == r)
            sp->right = suc->right;
        else
            sp->left = suc->right;

        delete suc;
    }

    return root;
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
    

    cout << "\nEnter value to delete: ";
    cin >> x;

    root = del(root, x);

    cout << "\nInorder after deletion: ";
    inorder(root);

    cout << "\nLevel Order after deletion: ";
    levelorder(root);

    return 0;

}

