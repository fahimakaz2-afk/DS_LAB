//Write a program to find the determinant of LTM.

#include<iostream>
using namespace std;

void readLTM(int d[10][10],int n){
    for(int  i=0; i< n; i++){
        for(int j = 0; j < i+1 ;j++)
            cin>>d[i][j];
        }
    }

void printLTM(int d[10][10],int n){
    for(int  i=0; i< n; i++){
        for(int j = 0; j< n; j++){
        if(j<=i)
            cout<<d[i][j]<<"\t";
        else
            cout<<"0\t";
        }
        cout<<endl;
    }
    
}

double detLTM(int d[10][10], int n){
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

    cout<<"Enter the elements of Lower Traingular matrix: "<<endl;
    readLTM(a,n);
    printLTM(a,n);
    deter = detLTM(a,n);

    cout<<"The determenant of this matrix is: "<<deter<<endl;


    
    return 0;
}