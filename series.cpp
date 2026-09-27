//  Define an array class with insert(x, index) and display member functions. 
//  Therefore, write a program to read n and store the series: 1, 2, 2, 3, 4, 4, 5, 6, 6, …, n
// in an array object.
#include <iostream>
using namespace std;

class Array {
    int arr[100];
    int n;

public:
    Array() {
        n = 0;
    }

    void insert(int x, int index) {
        if (n >= 100 || index < 0 || index > n) {
            return;
        }

        for (int i = n; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = x;
        n++;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array a;
    int n;
    int index = 0;

    cout << "Enter the value of n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            a.insert(i, index);
            index++;
        }
        else {
            a.insert(i, index);
            index++;

            a.insert(i, index);
            index++;
        }
    }

    cout << "The series is:" << endl;
    a.display();

    return 0;
}