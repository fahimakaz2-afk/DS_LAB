//Bubble sort using Array

#include<iostream>
#include<algorithm>
using namespace std;

void Insertion_sort(int a[], int n){
    for(int i = 0; i < n ; i++){
        bool isSorted = true;
        for(int j = 0; j < n-1-i; j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                isSorted = false;
            }
        }

        if(isSorted == true){
            break;
        }
    }
}

void print_array(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    cout << endl;
}

int main(){
    int n;
    cout << "Enter the no. of elements in array: ";
    cin >> n;

    int*a = new int[n];

    cout << "Enter "<< n <<" integers:"<<endl;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << "original array: ";
    print_array(a,n);

    Insertion_sort(a,n);

    cout << "sorted array: ";
    print_array(a, n);

    delete[] a;


    return 0;
}