//Bubble Sort using Linked list
#include<iostream>
#include<algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Linkedlist{
Node* head;
public:
    Linkedlist(){
        head = NULL;
    }

    void insert(int);
    void bubble_sort();
    void display();
};

//Insert at the end
void Linkedlist:: insert(int val){
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
}

//Bubble Sort

void Linkedlist::bubble_sort(){
    if(head == NULL)
        return;
    Node* last = NULL;
    bool isSorted;
    do{
        isSorted = true;
        Node*temp = head;

        while(temp->next != last){
            if(temp->data > temp->next->data){
                // swap(temp->data, temp->next->data); <-- either use swap() or
                int t = temp->data; // or u can simply use this method to swap the values of Nodes;
                temp->data = temp->next->data;
                temp->next->data = t;

                isSorted = false;
            }
            temp = temp->next;
        }
        last = temp;
    }while(isSorted == false);
}

//Display

void Linkedlist::display(){
    Node* temp;
    temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Linkedlist l1;
    l1.insert(5);
    l1.insert(2);
    l1.insert(8);
    l1.insert(6);
    l1.insert(0);

    l1.display();

    cout<<endl;

    cout<<"------Sorted List------"<<endl;

    l1.bubble_sort();

    l1.display();

    return 0;
}
        

