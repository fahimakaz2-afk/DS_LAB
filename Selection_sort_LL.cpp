//Selection Sort in LnkedList
#include<iostream>
#include<algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void insert(int);
    void Selection_sort();
    void display();

};

//Insert at the end
void LinkedList:: insert(int val){
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
//Sort using selection sort
void LinkedList::Selection_sort(){
    Node* i = head;
    while( i != NULL ){
        Node* minNode = i;
        Node*j = i->next;

        while (j != NULL)
        {
            if(j->data < minNode->data){
                minNode = j;
            }
            j = j->next;
        }

        // swap(minNode,i);
        int t = i->data;
        i->data = minNode->data;
        minNode->data = t;

        i = i->next;
    }  
}
//display
void LinkedList::display(){
    Node* temp;
    temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}


int main(){
    LinkedList l1;
    l1.insert(100);
    l1.insert(10);
    l1.insert(8);
    l1.insert(90);
    l1.insert(9);

    l1.display();

    cout<<"\n----Sorted List----"<<endl;

    l1.Selection_sort();

    l1.display();

    return 0;
}