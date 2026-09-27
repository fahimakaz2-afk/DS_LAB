//Write a program to find the determinant of Diagonal matrix
#include<iostream>
using namespace std;

void read(int d[10][10],int n){
    for(int  i=0; i< n; i++){
            cin>>d[i][i];
        }
    }

void print(int d[10][10],int n){
    for(int  i=0; i< n; i++){
        for(int j =0; j< n; j++){
        if(i==j)
            cout<<d[i][j]<<"\t";
        else
            cout<<"0\t";
        }
        cout<<endl;
    }
    
}

double det(int d[10][10], int n){
    int dm = 1;
    for(int i = 0; i < n; i++){
        dm*=d[i][i];
    }
    return dm;
}

int main(){
    int a[10][10];
    int n;
    double deter;
    cout<<"Enter order: ";
    cin>>n;

    cout<<"Enter the elements of diagonal matrix: "<<endl;
    read(a,n);
    print(a,n);
    deter = det(a,n);

    cout<<"The determenant of this matrix is: "<<deter<<endl;


    
    return 0;
}