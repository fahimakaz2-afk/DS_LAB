// : Product of one Lower Triangular Matrix (LTM) and one Upper Triangular Matrix (UTM).
// Write a program for the product of an LTM and a UTM using the following user-defined functions, where non-zero elements are stored in optimized 2D form and the space is minimized.
// •	void readLTM(int **q, int n)
// •	void printLTM(int **q, int n)
// •	void readUTM(int **q, int n)
// •	void printUTM(int **q, int n)
// •	int **mul(int **a, int **b, int n)
// •	void resMat(int **q, int n)

#include<iostream>
#include <algorithm>
using namespace std;

void readLTM(int** q,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            cin>>q[i][j];
        }
    }
}
void printLTM(int** q,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            if(j<=i)
                cout<<q[i][j]<<"\t";
            else
                cout<<"0\t";
        }
        cout<<endl;
    }
}
void readUTM(int** q,int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n;j++){
            cin>>q[i][j];
        }
    }
}
void printUTM(int** q,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            if(j >= i)
                cout<<q[i][j]<<"\t";
            else
                cout<<"0\t";
        }
        cout << endl;
    }
}

int **mul(int **a, int **b, int n){
    int **res = new int*[n];
    for(int i = 0; i < n; i++){
        res[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = 0;
            for(int k = 0; k <= min(i,j); k++){
                res[i][j] += a[i][k]*b[k][j]; 
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
    int n1,n2;
    cout<<"Enter the order of LTM : ";
    cin >> n1;
    cout<<endl;
   

    int **a = new int*[n1];
    for(int i = 0; i < n1; i++ ){
        a[i] = new int[i+1];
    }

    cout<<"Enter the elements of LTM: "<<endl;
    readLTM(a,n1);

    cout<<"Enter the order of UTM : ";
    cin>>n2;
    cout<<endl;

    int** b = new int*[n2];

    for(int i = 0; i < n2; i++){
        b[i] = new int[n2-i];
    }
    cout<<"Enter the elements of UTM."<<endl;
    readUTM(b,n2);

    cout<<"First matrix is: "<<endl;
    printLTM(a,n1);
    cout<<"second matrix is: "<<endl;
    printUTM(b,n2);

    if(n1 != n2){
        cout<<"Multiplication not possible!!"<<endl;
        return 0;
    }


    int **c = mul(a,b,n1);
    cout<<endl;

    resMat(c,n1);
    
    for(int i = 0; i < n1; i++){
        delete[] a[i];
        delete[] c[i];
    }
    delete[] a;
    delete[] c;

    for(int i = 0; i < n2; i++){
        delete[] b[i];
    }
        delete[] b;

    return 0;
}