// Create circular linked list using create(n), isempty(), 
//insert(x, index),display(),indexOf(c), get(index)

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*link;
};
class CLL{
Node* first;
Node* cur;

Node* createNewNode(){
    Node* temp = new Node;
    temp->link = NULL;
    return temp;
}
public:
    CLL(){
        first = cur = NULL;
    }

    void create(int n){
        for(int i = 0; i < n; i++){
            if(i == 0){
                cur = first = createNewNode();
            }
            else{
                cur->link = createNewNode();
                cur = cur->link;
            }
            cout <<"Enter data"<< endl;
            cin >> cur->data;
        }
        cur->link = first;
    }

    void display(){
        if(first == NULL) {cout<<"List is empty"<<endl; return;}

        Node* tempo = first;
        while(tempo->link!=first){
            cout<<tempo->data<<"->";
            tempo = tempo->link;
        }
        cout<<tempo->data<<endl;
    }

    bool IsEmpty(){
        if(first == NULL){
            return true;
        }
        return false;
    }

    int size(){
        if(first == NULL) return 0;

        int s = 1; cur = first;
        while(cur->link != first){
            s++;
            cur = cur->link;
        }
        return s;
    }

    void insert(int x , int idx){
        if(idx<0 || idx > size()){
            cout<<"Invalid index: ";
            return;}
        Node* newNode = createNewNode();
        newNode->data = x;
        newNode->link = newNode;

        if(first == NULL)
            first = newNode;
        else if(idx == 0){
            Node* last = first;
            while(last->link != first){
                last = last->link;
            }
            newNode->link = first;
            first = newNode;
            last->link = first;
        }
        else{
            Node* prev = first;
            for(int i = 0; i < idx - 1; i++){
                prev = prev->link;
            }
            
            newNode->link = prev->link;
            prev->link = newNode;
        }
    }

    int del(int idx){
        if(idx < 0 || idx >= size()){
            cout<<"Invalid Index"<<endl;
            return 0;
        }

        if(first == NULL){
            cout<<"Empty"<<endl;
            return 0;
        }

        int x;
        Node* del;
        if(idx == 0 && size() == 1){
            del = first;
            x = del->data;
            first = NULL;
        }

        else if(idx == 0){
            Node* last = first;
            while(last->link != first){
                last = last->link;
            }
            del = first;
            x = del->data;
            first = del->link;
            last->link = first;
        }

        else{
            Node* prev = first;
            for(int i = 0; i < idx-1; i++){
                prev = prev->link;
            }
            del = prev->link;
            x = del->data;
            prev->link = del->link;
        }
        delete(del);
        return x;
    }

    int indexOf(int x){
        if(first == NULL)return -1;
        int index = 0;
        cur = first;
        while(cur->link!=first && cur->data!=x){
            cur = cur->link;
            index++;
        }
        if(cur->data!=x){
            return -1;
        }
        return index;
    }

    int get(int index){
        if(index < 0 || index >= size()){
            cout<<"Invalid index";
        }
        cur = first;
        for(int i = 0; i < index; i++){
            cur = cur->link;
        }
        return cur->data;
    }
    
};

int main(){
    CLL CL1;
    CL1.create(4);
    CL1.display();

    int space = CL1.size();
    cout<<"The size of CLL is: "<< space << endl;

    int val, index;
    cout<<"Enter the value and index to add in the CLL: "<<endl;
    cin>>val>>index;
    CL1.insert(val,index);

    CL1.display();
    space = CL1.size();
    cout<<"The size of CLL is: "<< space << endl;

    cout<<"Deleted: " << CL1.del(3)<<endl;
    CL1.display();
    space = CL1.size();
    cout<<"The size of CLL is: "<< space << endl;



    int x;
    cout<<"Enter no. u want to find: ";
    cin>>x;
    cout<<"The no. is at: "<<CL1.indexOf(x)<<endl;

    int idx;
    cout<<"Enter the value at index u want: ";
    cin>>idx;
    cout<<"The value is: "<<CL1.get(idx);
    return 0;
}