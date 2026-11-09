//This code contains stack in recursive functions:
//1.Factorial(n)
//2. GCD(m,n)
//3. Fibonacci(n)
//4.Binary(n)

#include<iostream>
#include<math.h>
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

 int factorial(int n){
        Stack s(n - 1);

        while(n > 1){
            s.push(n);
            n = n - 1;
        }

        int fact = 1;

        while(s.isEmpty() == false){
            fact = fact*s.pop();
        }
        return fact;
}

int gcd(int m, int n){
    Stack s1(1), s2(1);

    s1.push(m); s2.push(n);

    while(s1.isEmpty() == false){
        m = s1.pop();
        n = s2.pop();

        if(m % n != 0){
            s1.push(n);
            s2.push(m % n);
        }
    }
    return n;
}

int fibonacci(int n){
    Stack s(n);
    s.push(n);
    int fib = 0;
    while(s.isEmpty() == false){
        n = s.pop();
        if(n > 2){
            s.push(n-1);
            s.push(n-2);
        }
        else if(n == 1 || n == 2) fib++;
    }

    return fib;
}

//Decimal to Binary
int Binary(int n){
    Stack Sr(floor(log2(n)) + 1) , Sp(floor(log2(n)) + 1);
    int p = 1, b = 0;
    while(n > 0){
        Sr.push(n % 2);
        Sp.push(p);

        p *= 10;
        n = n/2;
    }

    while(Sr.isEmpty() == false){
        b += Sr.pop()*Sp.pop();
    }
    return b;
}

int main(){
    //Factorial
    int n;
    cout<<"Enter number for Factorial: ";
    cin>>n;
    if(n < 0){
        cout<<"Factorial not defined for negative numbers";
    }

    else{
        cout <<"Factorial = "<< factorial(n)<<endl;
    }

    //GCD
    int m1, m2;
    cout << "\nEnter the no.s you want GCD of: ";
    cin>>m1>>m2;

    cout<<"The GCD is: "<<gcd(m1,m2)<<endl;

    //Fibonacci    
    int x;
    cout << "\nEnter number of terms for Fibonacci Series: ";
    cin >> x;

    for (int i = 1; i <= x; i++) {
        cout << fibonacci(i) << " ";
    }

    //Dec To Bin
    int dec;
    cout<<"\nEnter the Decimal no.: ";
    cin>>dec;
    cout<<"The Binary is: "<<Binary(dec);

    return 0;
}
