//Binary search in an array, array should be sorted

#include<iostream>
#include<algorithm>
using namespace std;

int binary_search(int a[], int n, int x){
    if(x < a[0] || x > a[n-1]) return -1;
    
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low + high)/2;
        
        if(x == a[mid]) return mid;

        else if(x < a[mid]) high = mid - 1;

        else low = mid + 1;
    }

    return -1;
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

    
    int idx = binary_search(a,n,val);

    if(idx == -1)
        cout << "Element NOt Found!!!";
    else{
        cout << "Element is at: "<< idx <<endl;
    }

    delete[] a;

    return 0;
}
