//  Product of two Upper Triangular Matrices (UTMs).
// Write a program for the product of two UTMs using the following user-defined functions, where non-zero elements are stored in optimized 2D form and the space is minimized.
// •	void readUTM(int **q, int n)
// •	void printUTM(int **q, int n)
// •	int **mul(int **a, int **b, int n)
// •	void resMat(int **q, int n)
#include<iostream>
using namespace std;

void readUTM(int **q, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cin>>q[i][j];
        }
    }
}

void printUTM(int **q, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i<=j)
                cout<<q[i][j]<<"\t";
            else
                cout<<"0\t";
        }
        cout<<endl;
    }
}

int **mul(int **a, int **b, int n){
    int **res = new int*[n];
    for(int i = 0; i < n; i++){
        res[i] = new int[n-i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            res[i][j] = 0;
            for(int k = i; k <= j; k++){
                res[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return res;
}

void resMat(int **q, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<q[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the order: ";
    cin>>n;

    int **a = new int*[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[n-i];
    }

    cout<<"Enter first UTM matrix: "<<endl;
    readUTM(a,n);

    int **b = new int*[n];
    for(int i = 0; i < n; i++){
        b[i] = new int[n-i];
    }
    cout<<"Enter second UTM matrix: "<<endl;
    readUTM(b,n);


    int** c = mul(a,b,n);

    cout<<"First Matrix: "<<endl;
    printUTM(a,n);
    cout<<endl;
    cout<<"second  Matrix: "<<endl;
    printUTM(b,n);
    cout<<endl;
    cout<<"Resultant Matrix: "<<endl;
    printUTM(c,n);
    cout<<endl;

    for(int i = 0; i < n; i++){
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;


    return 0;
}