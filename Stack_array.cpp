//  Stack Using Array
// Write a program to implement a stack using an array and perform PUSH and POP operations.
// •	Perform the PUSH operation to insert an element into the stack.
// •	Perform the POP operation to remove an element from the stack.
// •	Display the elements of the stack.
// •	Handle stack overflow and stack underflow conditions.

#include<iostream>
using namespace std;

class stack{
    int arr[10];
    int top;
    public:
        stack(){
            top = -1;
        }
        void display(){
            if(top == -1){
                cout<<"Array is empty"<<endl;
            }
            else{
                for(int i = top; i >=0; i--){
                    cout<<arr[i]<<"\t";
                }
                cout<<endl;
            }
        }

        void pop(){
            if(top == -1){
                cout<<"Stack underflow";
            }
            else{
                cout<<"Popped element: "<<arr[top]<<endl;
                top--;
            }
            
        }

        void push(int x){
            if(top == 9){
                cout<<"Stack overflow"<<endl;
            }
            else{
                top++;
                arr[top] = x;
                cout<< x <<" Is pushed in Stack "<<endl;
            }
        }
};

int main(){
    stack s;
    int choice, x;
    do{
        cout<<"\n----MENU----"<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Element you want to add"<<endl;
                cin>>x;
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting program" << endl;
                break;
            default:
                cout<<"Invalid choice: "<<endl;
        }
    }while(choice!=4);
    return 0;
}