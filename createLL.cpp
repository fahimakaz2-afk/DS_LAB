//creating list, size, insert, delete, indexof, get index of particular value ,without switch

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* link;
    
};
class ll{
    Node* first;
    Node* cur;

    Node* createNewNode(){
        Node* temp = new Node;
        temp->link = NULL;
        return temp;
    }

    public:
    ll(){
        first = NULL;
        cur = NULL;
    }

    void create(int n){
        for(int i = 1; i <= n; i++){
            if(i == 1){
                first = cur = createNewNode();
            }
            else{
                cur->link = createNewNode();
                cur = cur->link;
            }
            cout<<"Enter the data: ";
            cin >> cur->data;
        }
        cur->link = NULL;
    }

    void display(){
        cur = first;
        while(cur!=NULL){
            cout << cur->data << "->";
            cur = cur->link;
        }
        cout <<"NULL";
    }

    int size(){
        cur = first;
        int sz = 0;
        while(cur!=NULL){
            sz++;
            cur = cur->link;
        }
        return sz;
    }

    void insert(int x,int index){
        if(index <0 || index > size()){
            cout<<"invalid index";
            return;
        }
        Node*newNode;
        newNode = createNewNode();
        newNode -> data = x;
        if(index == 0){
            newNode->link = first;
            first = newNode;
        }
        else{
            Node* prev  = first;
            for(int i = 0 ; i < index-1; i++){
                prev = prev->link;
            }
            newNode->link = prev->link;
            prev->link = newNode;
        }
    }

    void del(int index){
        if(size() == 0){
            cout<<"List is empty ";
            return;
        }

        if(index < 0|| index > size()){
            cout<<"invalid index";
            return;
        }

        Node* dele;
        if(index == 0){
            dele = first;
            first = first->link;
        }
        else{
            Node*prev = first;
            for(int i = 0;i < index-1; i++){
                prev = prev->link;
            }
            dele = prev->link;
            prev->link = dele->link;
        }
    }

    int indexof(int x){
    int index = 0;
    cur = first;
    
    while(cur != NULL){
        if(cur->data == x){
            return index; 
        }
        cur = cur->link; 
        index++;
    }
    cout << "Not Found in the List " << endl;
    return -1;   
}

    int get(int index){
        if(index < 0 || index >= size()){
            cout<<"Invalid index ";
            return -1;
        }

        cur = first;
        for(int i = 0; i < index; i++){
            cur = cur->link;
        }
            return cur->data;
    }
};
int main() {
     ll l1;
    int n;
    cout <<"Enter the no. of nodes: ";
    cin>>n;
    
    l1.create(n);

    cout<<"The list is: "<<endl;

    l1.display();
    cout<<endl;

    cout << "The size is: ";
    cout << l1.size();

    cout << endl;
    
    l1.insert(5,0);
    cout << endl;
    l1.insert(6,1);

    l1.display();

    cout<<endl;

    cout << "The size is: ";
    cout << l1.size();

    cout << endl;

    l1.del(3);
    l1.display();
    cout<<endl;
    cout << "The size is: ";
    cout << l1.size();

    cout <<endl;

    cout << "\nFinding indices:\n";
    cout << "Index of 5 is: " << l1.indexof(5) << endl;
    cout << "Index of 0 is: " << l1.indexof(0) << endl;

    cout<<"get the value at index 3: "<<l1.get(3);
    
    return 0;
}