//Queue implementation in array , isEmpty(), size(), insert(x), del(), display().
#include <iostream>
using namespace std;

class Queue {
    int Q[100];
    int rear;
    int front;

public:
    Queue() {
        rear = front = -1;
    }

    bool isEmpty() {
        return rear == -1;
    }

    int size() {
        if (isEmpty())
            return 0;

        return rear - front + 1;
    }

    void insert(int x) {
        if (rear == 99) {
            cout << "Queue is Full\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        Q[rear] = x;

        cout << x << " inserted successfully\n";
    }

    int del() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        int x = Q[front];

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }

        return x;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        for (int i = front; i <= rear; i++) {
            cout << Q[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, x;

    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Size\n";
        cout << "5. Check Empty\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter element: ";
                cin >> x;
                q.insert(x);
                break;

            case 2:
                x = q.del();

                if (x != -1)
                    cout << "Deleted element: " << x << endl;
                break;

            case 3:
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
