
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
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
        }
    }

    int del(int pos) {
        Node* temp = head;
        Node* prev = NULL;

        if (pos == 0) {
            int x = temp->data;
            head = head->next;
            delete temp;
            return x;
        }

        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        int x = temp->data;
        prev->next = temp->next;
        delete temp;

        return x;
    }
};

class RadixSort {
public:
    void radixSort(int a[], int n) {
        int m = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] > m)
                m = a[i];
        }

        int d = 0;
        while (m > 0) {
            d++;
            m = m / 10;
        }

        LinkedList L[10];

        for (int k = 1; k <= d; k++) {

            for (int i = 0; i < n; i++) {
                int digit = a[i];

                for (int j = 1; j < k; j++)
                    digit = digit / 10;

                digit = digit % 10;

                L[digit].insert(a[i], 0);
            }

            int i = 0;

            for (int j = 0; j <= 9; j++) {
                while (L[j].isEmpty() == false) {
                    a[i] = L[j].del(L[j].size() - 1);
                    i++;
                }
            }
        }
    }
};

int main() {
    int a[] = {86, 3, 50, 12, 47};
    int n = 5;

    RadixSort r;
    r.radixSort(a, n);

    cout << "Sorted list: ";

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
