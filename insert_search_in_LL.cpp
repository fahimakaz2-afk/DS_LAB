// Linked List Question
// WAP to create a Linked List
// 1.	Each node should carry a pointer to the next node and a value. 
// 2.	Insert a new element at the beginning of the linked list. 
// 3.	Search the linked list for any value entered by the user. 

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LList {
    Node* head;

public:
    LList() {
        head = nullptr;
    }

    void InsertAtBeg(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void Search(int val) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Value found" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Value not found" << endl;
    }
};

int main() {
    LList l;
    int n, val, SearchVal;

    cout << "Enter no. of elements: ";
    cin >> n;

    cout << "Enter elements: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> val;
        l.InsertAtBeg(val);
    }

    cout << "Enter the value you want to search for: ";
    cin >> SearchVal;

    l.Search(SearchVal);

    return 0;
}