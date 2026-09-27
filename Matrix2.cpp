//Matrix read,print,mul using class
#include <iostream>
using namespace std;

class Matrix {
private:
    int a[10][10];
    int row;
    int col;

public:
    void read(int r, int c);
    void print();
    void mul(Matrix m1, Matrix m2);
};

void Matrix::read(int r, int c) {
    row = r;
    col = c;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void Matrix::print() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix::mul(Matrix m1, Matrix m2) {
    if (m1.col != m2.row) {
        cout << "Multiplication not possible!!!" << endl;
        return;
    }

    row = m1.row;
    col = m2.col;


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            a[i][j] = 0;
            for (int k = 0; k < m1.col; k++) {
                a[i][j] += m1.a[i][k] * m2.a[k][j];
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Multiplication not possible! Columns of Matrix 1 must match rows of Matrix 2." << endl;
        return 0;
    }

    Matrix m1, m2, m3;

    cout << "\nEnter elements for Matrix 1:\n";
    m1.read(r1, c1);

    cout << "\nEnter elements for Matrix 2:\n";
    m2.read(r2, c2);

    m3.mul(m1, m2);

    cout << "\nResultant Matrix:\n";
    m3.print();

    return 0;
}
