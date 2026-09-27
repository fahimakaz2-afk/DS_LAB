// Products involving Lower Triangular Matrices . LTM X LTM.
// Using optimized 2D storage for non-zero elements.

#include<iostream>
using namespace std;

void readLTM(int **q, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cin>>q[i][j];
        }
    }
}

void printLTM(int **q, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i>=j)
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
        res[i] = new int[i+1];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            res[i][j] = 0;
            for(int k = j; k <= i; k++){
                res[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter the order: ";
    cin>>n;

    int **a = new int*[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[i+1];
    }

    cout<<"Enter first LTM: "<<endl;
    readLTM(a,n);


    int **b = new int*[n];
    for(int i = 0; i < n; i++){
        b[i] = new int[i+1];
    }

    cout<<"Enter second LTM: "<<endl;
    readLTM(b,n);

    cout<<endl;
    cout<<"LTM 1: "<<endl;
    printLTM(a,n);

    cout<<endl;
    cout<<"LTM 2: "<<endl;
    printLTM(b,n);

    cout<<"The resultant matrix is: "<<endl;
    int** c = mul(a,b,n);
    printLTM(c,n);

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

