//sequential search or linear search in array
#include<iostream>
using namespace std;

int sequential_search(int a[], int n, int x){
    int index = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            index = i;
            break;
        }
    }
    return index;
}

int  main(){
    int n,val;
    cout << "Enter the no. of elements in array: ";
    cin >> n;

    int*a = new int[n];

    cout << "Enter "<< n <<" integers:"<<endl;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout<<"Enter the element you want to find: "<<endl;
    cin >> val;

    int idx = sequential_search(a,n,val);

    if(idx == -1)
        cout << "Element NOt Found!!!";
    else{
        cout << "Element is at: "<< idx <<endl;
    }

    delete[] a;

    return 0;
}