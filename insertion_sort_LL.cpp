//Insertion sort using Linked List
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void Insertion_Sort(){
        Node* i = head->next;
        
        while( i != NULL){
            Node*j = i->prev;
            int x = i->data;

            while(j != NULL && x < j->data){
                j->next->data = j->data;
                j = j->prev; 
            }

            if(j == NULL)
                head->data = x;
            else
                j->next->data = x;

            i = i->next;
        }
    }

    void display(){
        Node* temp = head;
        cout<<"\nLinked List is: "<<endl;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        } 
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList l1;
    l1.insert(5);
    l1.insert(56);
    l1.insert(10);
    l1.insert(20);

    l1.display();

    cout<<"\n---Sorted LL is---"<<endl;
    l1.Insertion_Sort();
    l1.display();

    return 0;
}