// Doubly circular ll, first create(int n), display(),isEmpty(),size(),indexOf(x),get(index),delete(index), insert(x,index)
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* Llink;
    Node* Rlink;
};


class DoublyCLL{
public:
    Node* first;
    Node* cur;

    DoublyCLL() {
    first = NULL;
    cur = NULL;
}

    Node* createNewNode() {
        Node* newNode = new Node;
        newNode->Llink = NULL;
        newNode->Rlink = NULL;
        return newNode;
    }

    void create(int n) {
    if (n <= 0) return;

    Node* cur = NULL;
    Node* prev = NULL;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cur = first = createNewNode();
        } else {
            prev = cur;
            cur->Rlink = createNewNode();
            cur = cur->Rlink;
            cur->Llink = prev;
        }

        cout << "Enter data: ";
        cin >> cur->data;
    }

    // Make the list circular
    cur->Rlink = first;
    first->Llink = cur;
}

    void display(){
        if (first == NULL) {
            cout << "List is Empty";
            return;
        }
        Node* temp = first;
        while(temp->Rlink != first){
            cout<< temp->data<<"<=>";
            temp = temp->Rlink;
        }
    cout << temp->data;
    }

    bool isEmpty(){
        if(first == NULL)
            return true;
        
        return false;
    }

    int size(){
        if(first == NULL){
            cout<<"List is Empty";
            return 0;
        }
        int s = 1; cur = first;
        while(cur->Rlink != first){
            s++;
            cur = cur->Rlink;
        }
        return s;
    }

    int indexOf(int x){
        if (first == NULL)
            return -1;
        int index = 0;
        cur = first;
        while(cur->data != x && cur->Rlink != first ){
            cur = cur->Rlink;
            index++;
        }
        if(cur->data != x)
            return -1;
        return index;
    }

    int get(int idx){
        if(idx < 0 || idx >= size()){
            cout<<"Invalid index"<<endl;
            return -1;
        }
        cur = first;
        for(int i = 0; i < idx; i++){
            cur = cur->Rlink;
        }
        return cur->data;
    }

    int del(int idx){
        if(first == NULL){
            cout<<"LL is Empty";
            return -1;
        }

        if(idx < 0 || idx >= size()){
            cout<<"Invalid Index";
            return -1;
        }
        Node*del;
        if(idx == 0 && size() == 1){
            del = first;
            first = NULL;
        }
        else if(idx == 0){
            Node*last = first->Llink;
            del = first;
            first = del->Rlink;
            last->Rlink = first;
            first->Llink = last;

        }
        else {
            Node* prev = first;

            for (int i = 0; i < idx - 1; i++) {
                prev = prev->Rlink;
            }

            del = prev->Rlink;
            Node* next = del->Rlink;

            prev->Rlink = next;
            next->Llink = prev;
        }

        int x = del->data;
        delete(del);
        return x;
    }

    void insert(int x, int idx){
        if(idx < 0 || idx >= size()){
            cout<<"Invalid index";
            return;
        }
        Node* newNode = createNewNode();
        newNode->data = x;
        newNode->Llink = newNode->Rlink = newNode;

        if(first == NULL){
           first = newNode;
        }
        else if(idx == 0){
            Node* last = first->Llink;
            Node* next = first;
            newNode->Llink = last;
            first = newNode;
            next->Llink = first;
            last->Rlink = first;
        }
        else {
            Node* prev = first;

            for (int i = 0; i < idx - 1; i++) {
                prev = prev->Rlink;
            }

            Node* next = prev->Rlink;

            newNode->Rlink = next;
            newNode->Llink = prev;

            prev->Rlink = newNode;
            next->Llink = newNode;
        }
    }
};

int main(){
    DoublyCLL d1;
    d1.create(5);
    d1.display();

    d1.insert(5,2);
    d1.display();

    d1.del(1);
    d1.display();

    cout << d1.get(2) << endl;

    cout << "The size is: " << d1.size() << endl;

    cout << "Index: " << d1.indexOf(5) << endl;

    if(d1.isEmpty()){
        cout<<"List Empty";
    }


    return 0;
}