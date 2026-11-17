
/*
    Circular Queue

    FRONT points to the first element.
    REAR points to the last element.

    Operations:
    1. isEmpty() - Checks whether queue is empty.
    2. insert(x) - Inserts an element.
    3. delet() - Deletes an element.
    4. size() - Returns the number of elements.
    5. display() - Displays queue elements.

    Circular movement:
    (index + 1) % length
*/
//Circular queue
#include <iostream>
using namespace std;

class circular_queue {
    int q[100];
    int rear, front;
    int length;

public:

    circular_queue() {
        rear = front = -1;
        length = 100;
    }

    bool isEmpty() {
        if (rear == -1)
            return true;
        else
            return false;
    }

    void insert(int x) {
        if ((rear + 1) % length == front) {
            cout << "Queue is Full";
            return;
        }

        if (rear == -1)
            rear = front = 0;

        else
            rear = (rear + 1) % length;

        q[rear] = x;
    }

    int delet() {

        if (front == -1) {
            cout << "Queue is empty";
            return 0;
        }

        int x = q[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % length;

        return x;
    }

    int size() {

        if (rear == -1)
            return 0;

        else if (rear >= front)
            return rear - front + 1;

        else
            return length - front + rear + 1;
    }

    void display() {

        if (front == -1)
            return;

        int i = front;

        while (i != rear) {
            cout << q[i] << " ";
            i = (i + 1) % length;
        }

        cout << q[i] << endl;
    }
};


int main() {

    circular_queue q;
    int choice, x;

    do {
        cout << "\n\n--- Circular Queue Menu ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Size";
        cout << "\n5. Check Empty";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter element: ";
                cin >> x;
                q.insert(x);
                break;

            case 2:
                cout << "Deleted element: " << q.delet();
                break;

            case 3:
                cout << "Queue: ";
                q.display();
                break;

            case 4:
                cout << "Size: " << q.size();
                break;

            case 5:
                if (q.isEmpty())
                    cout << "Queue is Empty";
                else
                    cout << "Queue is not Empty";
                break;

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 6);

    return 0;
}
