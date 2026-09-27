//Write a program to find the determinant of UTM.

#include<iostream>
using namespace std;

void readUTM(int d[10][10],int n){
    for(int  i=0; i< n; i++){
        for(int j = i; j<n;j++)
            cin>>d[i][j];
        }
    }

void printUTM(int d[10][10],int n){
    for(int  i=0; i< n; i++){
        for(int j =0; j< n; j++){
        if(i<=j)
            cout<<d[i][j]<<"\t";
        else
            cout<<"0\t";
        }
        cout<<endl;
    }
    
}

double detUTM(int d[10][10], int n){
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

    cout<<"Enter the elements of Upper Traingular matrix: "<<endl;
    readUTM(a,n);
    printUTM(a,n);
    deter = detUTM(a,n);

    cout<<"The determenant of this matrix is: "<<deter<<endl;


    
    return 0;
}