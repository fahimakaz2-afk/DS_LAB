//Stack Data structure implemented using linked list
#include <iostream>
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

    bool isEmpty(){
        if(head == NULL)
            return true;
        return false;
    }

    int size(){
        int s = 0;
        Node* cur = head;

        while(cur != NULL){
            s++;
            cur = cur->next;
        }

        return s;
    }

    void insert(int x){
        Node* newNode = new Node(x);

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

    int del(int idx){

        if(idx < 0 || idx >= size())
            return -1;

        Node* temp = head;

        if(idx == 0){
            head = head->next;
            int val = temp->data;
            delete temp;
            return val;
        }

        Node* prev = NULL;

        for(int i = 0; i < idx; i++){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;

        int val = temp->data;
        delete temp;

        return val;
    }

    void display(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

class stack{
public:
    LinkedList s;

    bool isEmpty(){
        return s.isEmpty();
    }

    int size(){
        return s.size();
    }

    void push(int x){
        s.insert(x);
    }

    int pop(){
        return s.del(size()-1);
    }

    void display(){
        s.display();
    }
};

int main(){
    stack s;
    int choice, x;

    do{
        cout << "\n----MENU----" << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Display" << endl;
        cout << "4.Size" << endl;
        cout << "5.Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Element you want to add: ";
                cin >> x;
                s.push(x);
                break;

            case 2:
                x = s.pop();
                if(x == -1)
                    cout << "Stack is empty" << endl;
                else
                    cout << "Deleted element: " << x << endl;
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "Size: " << s.size() << endl;
                break;

            case 5:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    }while(choice != 5);

    return 0;
}
