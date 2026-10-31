//Sparse matrix , read(), print() and add()
#include<iostream>
using namespace std;

class Node{
public:
   int row, col, val;
   Node* next;

    Node(){
        row = col = val = 0;
    }

    Node(int r,  int c, int v){
        row = r;
        col = c;
        val = v;
        next = NULL;
   }
};

class LinkedList{
    Node* head;
    int size;
public:
    LinkedList(){
        head = NULL;
        size = 0;
    }

    void insert(Node x, int pos){
        Node* newNode = new Node(x.row, x.col, x.val);

        if(pos == 0){
            newNode->next = head;
            head = newNode;
        }

        else{
            Node* temp = head;

            for(int i = 0; i < pos - 1; i++)
                temp = temp->next;

            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    Node get(int index){
        Node* temp = head;

        for(int i = 0; i < index; i++)
            temp = temp->next;

        return *temp;
    }

     int getSize(){
        return size;
    }
};

class SparseMat{
    int m, n, nz;
    LinkedList lst;
public:

    SparseMat(int rows, int cols){
        m = rows;
        n = cols;
        nz = 0;
    
    }

    

    void read(){
        int value;
        cout << "Enter matrix elements:\n";

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> value;

                if(value != 0){
                    Node x(i, j, value);
                    lst.insert(x, lst.getSize());
                    nz++;
                }
            }
        }
    }

    void print(){
       int k = 0;
       bool flag = true;
       Node x;

       for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(k < lst.getSize() && flag == true){
                x = lst.get(k);
                flag = false;
            }

            if(k < lst.getSize() && x.row == i && x.col == j){
                cout << x.val <<" ";
                k++;
                flag = true;
            }
            else{
                    cout << "0 ";
            }
        }
        cout << endl;
        }
    }

   SparseMat add(SparseMat B)
    {
        if(m != B.m || n != B.n)
        {
            cout << "Matrix dimensions must be same.\n";
            return SparseMat(0, 0);
        }

        SparseMat C(m, n);

        int i = 0, j = 0;
        int m1 = lst.getSize();
        int m2 = B.lst.getSize();

        while(i < m1 && j < m2)
        {
            Node x = lst.get(i);
            Node y = B.lst.get(j);

            if(x.row < y.row ||
              (x.row == y.row && x.col < y.col))
            {
                C.lst.insert(x, C.lst.getSize());
                C.nz++;
                i++;
            }

            else if(x.row == y.row && x.col == y.col)
            {
                x.val = x.val + y.val;

                if(x.val != 0)
                {
                    C.lst.insert(x, C.lst.getSize());
                    C.nz++;
                }

                i++;
                j++;
            }

            else
            {
                C.lst.insert(y, C.lst.getSize());
                C.nz++;
                j++;
            }
        }

        while(i < m1)
        {
            Node x = lst.get(i);
            C.lst.insert(x, C.lst.getSize());
            C.nz++;
            i++;
        }

        while(j < m2)
        {
            Node y = B.lst.get(j);
            C.lst.insert(y, C.lst.getSize());
            C.nz++;
            j++;
        }

        return C;
    }
};

// Main function
int main()
{
    SparseMat A(4, 4);
    SparseMat B(4, 4);

    cout << "Enter first matrix:\n";
    A.read();

    cout << "\nEnter second matrix:\n";
    B.read();

    cout << "\nFirst matrix:\n";
    A.print();

    cout << "\nSecond matrix:\n";
    B.print();

    SparseMat C = A.add(B);

    cout << "\nSum of matrices:\n";
    C.print();

    return 0;
}