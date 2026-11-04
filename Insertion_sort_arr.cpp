//Insertion sort using array.
#include<iostream>
using namespace std;

class arr{
public:
    int a[100];
    int n;

    void Read_arr(){
        cout<<"Enter "<<n<<" Elements of Array: "<<endl;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
    }

    void display(){
        cout<<"The Elements are: "<<endl;
        for(int i = 0; i < n; i++){
            cout << a[i] << "  ";
        }
        cout<<endl;
    }

    void InsertionSort(){
        for(int i = 1; i < n; i++){
            int j = i-1;
            int x = a[i];
            while(j >= 0 && x < a[j]){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;
        }
    }

};

int main(){
    arr a1;

    cout<<"Enter the no. of elements: ";
    cin >> a1.n;


    a1.Read_arr();
    a1.display();

    cout<<"\n----Sorted Array is---\n"<<endl;

    a1.InsertionSort();
    a1.display();


    return 0;
}
