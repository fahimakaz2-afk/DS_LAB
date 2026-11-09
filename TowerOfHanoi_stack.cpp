//Tower of Hanaoi using stack recursion
#include<iostream>
using namespace std;

class Stack{
public:
    int* arr;
    int top;
    int size;

    Stack(int n){
        size = n;
        arr = new int[size];
        top = -1;
    }

    void push(int x){
        if (top == size-1){
            cout << "Stack Overflow";
            return;
        }

        top++;
        arr[top] = x;
    }

    int pop(){
        if(top == -1){
            cout<<" Stack underflow ";
            return -1;
        }

        int x = arr[top];
        top--;
        return x;
    }

    bool isEmpty(){
        return top == -1;
    }

};

void Move(int n){
    int size = n*n;

    Stack Sn(size), Ss(size), Si(size),Sd(size);

    Sn.push(n);
    Ss.push('A');
    Si.push('B');
    Sd.push('C');

    while (Sn.isEmpty() == false){

        n = Sn.pop();
        char s = Ss.pop();
        char i = Si.pop();
        char d = Sd.pop();

        if(n > 1){
             // Move n-1 disks from source to intermediate

             Sn.push(n-1);
             Ss.push(s);
             Si.push(d);
             Sd.push(i);
             
            // Move largest disk from source to destination
            Sn.push(1);
             Ss.push(s);
             Si.push(i);
             Sd.push(d);

             // Move n-1 disks from intermediate to destination
             Sn.push(n-1);
             Ss.push(i);
             Si.push(s);
             Sd.push(d);

        }
        else{
            cout<< "Move "<< s << " -> " << d << endl;
        }
        
    }
    
};

int main(){
    int n;

    cout<<"Enter no. of disks: ";
    cin >> n;

    if(n <= 0) cout << "Enter a positive no. ";
    else Move(n);

    return 0;
}