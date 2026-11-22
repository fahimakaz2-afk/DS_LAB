#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val){
        data  = val;
        next = prev = NULL;
    }
};

class Deque{
    Node* front;
    Node* rear;
    public:

    Deque(){
        front = rear = NULL;
    }

    void insertFront(int x){
        Node* n = new Node(x);
        if(front == NULL){
            front = rear = n;
            n->next = n;
            n->prev = n;
        }
        else{
            n->next = front;
            n->prev = rear;

            front->prev = n;
            rear->next = n;
            
            front = n;
        }

    }
    
    void insertRear(int x){
        Node* newNode = new Node(x);
        if(rear == NULL){
            front = rear = newNode;
            newNode->next = newNode->prev = newNode;
        }
        else{
            newNode->next = front;
            newNode->prev = rear;

            rear->next = newNode;
            front->prev = newNode;
            rear = newNode;
        }
    }

    int delete_front(){
        if(front == NULL) {
            cout <<"Deque empty";
            return -1;
        }
        int x;
        x = front->data;
        if(front == rear){
            delete front;
            front = rear = NULL;
        }
        else{
            Node*temp = front;
            front = front->next;

            front->prev = rear;
            rear->next = front;

            delete temp;
        }
        return x;
    }

    int delete_rear(){
        if(rear == NULL){
            cout<<"dequeue empty";
            return -1;
        }
        
        int x = rear->data;
        
        if(front == rear){
            delete rear;
            front = rear = NULL;
        }
        else{
            Node* temp = rear;
            rear = rear->prev;

            front->prev = rear;
            rear->next = front;

            delete temp;
        }
        return x;
    }

    void display(){
        if(front == NULL){
            cout<<"deque is empty\n";
            return;
        }
        Node* cur = front;

        while(cur->next!=front){
            cout<<cur->data<<"->";
            cur = cur->next;
        }
        cout<<cur->data<<endl;
    }

    int size(){
        if(front == NULL){
            return 0;
        }
        int s = 1;
        Node* cur = front;

        while(cur->next != front){
            s++;
            cur = cur->next;
        }
        return s;
    }

};

int main(){
    Deque d1;
    d1.insertFront(1);
    d1.insertFront(2);
    d1.insertFront(3);

    d1.display();

    d1.insertRear(5);
    d1.insertRear(6);
    d1.insertRear(8);

    d1.display();
    cout<<"\nThe size of Deque is "<<d1.size()<<endl;


    d1.delete_front();

    d1.display();

    d1.delete_rear();

    d1.display();

    cout<<"\nThe size of Deque is "<<d1.size()<<endl;
    return 0;
}