//Selection sort using array
#include<iostream>
#include <algorithm>

using namespace std;

void selection_sort(int a[], int n){
    for(int i = 0; i < n-1; i++ ){
        int minidx = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[minidx])
                minidx = j;
       }
       if(i != minidx){
        swap(a[i], a[minidx]);
       }
    }
}

void print_array(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    cout << endl;
}



int  main(){
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

    selection_sort(a,n);

    cout << "sorted array: ";
    print_array(a, n);

    delete[] a;

    return 0;
}