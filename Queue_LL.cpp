//Queue implementation in Linkedlist , isEmpty(), size(), insert(x), del(), display().

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    int size() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void insert(int x, int pos) {
        Node* newNode = new Node(x);

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    int del(int pos) {
        if (isEmpty())
            return -1;

        Node* temp = head;
        int x;

        if (pos == 0) {
            x = head->data;
            head = head->next;
            delete temp;
            return x;
        }

        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        Node* delNode = temp->next;
        x = delNode->data;

        temp->next = delNode->next;
        delete delNode;

        return x;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

class Queue {
    LinkedList q;

public:
    bool isEmpty() {
        return q.isEmpty();
    }

    int size() {
        return q.size();
    }

    void insert(int x) {
        q.insert(x, q.size());
    }

    int del() {
        return q.del(0);
    }

    void display() {
        q.display();
    }
};

int main() {
    Queue q;
    int choice, x;

    do {
        cout << "\n--- QUEUE USING LINKED LIST ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Size\n";
        cout << "5. Check Empty\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter element: ";
                cin >> x;
                q.insert(x);
                break;

            case 2:
                if (q.isEmpty()) {
                    cout << "Queue is Empty\n";
                }
                else {
                    cout << "Deleted element: "
                         << q.del() << endl;
                }
                break;

            case 3:
                if (q.isEmpty())
                    cout << "Queue is Empty\n";
                else
                    q.display();
                break;

            case 4:
                cout << "Queue size: " << q.size() << endl;
                break;

            case 5:
                if (q.isEmpty())
                    cout << "Queue is Empty\n";
                else
                    cout << "Queue is Not Empty\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
