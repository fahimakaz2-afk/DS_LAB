//Matrix read,print,mul using pointers without functions 
#include<iostream>
using namespace std;

int main(){
    
    int r1,c1,r2,c2;

    cout<<"\nEnter the row and column of matrix 1: ";
    cin>>r1>>c1;
    cout<<"\nEnter the row and column of matrix 2: ";
    cin>>r2>>c2;

    int** m1 = new int*[r1];
    for(int i = 0; i < r1; i++){
        m1[i] = new int[c1];
    }

    int** m2 = new int*[r2];
    for(int i = 0; i < r2; i++){
        m2[i] = new int[c2];
    }

    cout<<"\nEnter the elements of matrix1: "<<endl;

    for(int i =0; i < r1; i++){
        for(int j = 0; j< c1; j++){
            cin>>m1[i][j];
        }
    }
      cout<<"\nEnter the elements of matrix2: "<<endl;

    for(int i =0; i < r2; i++){
        for(int j = 0; j< c2; j++){
            cin>>m2[i][j];
        }
    }
    cout<<"----Matrix1----"<<endl;
     for(int i =0; i < r1; i++){
        for(int j = 0; j< c1; j++){
            cout<<m1[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"----Matrix12----"<<endl;
     for(int i =0; i < r2; i++){
        for(int j = 0; j< c2; j++){
            cout<<m2[i][j]<<"\t";
        }
        cout<<endl;
    }

    
    if(c1 != r2){
        cout<<"Multiplication not possible"<<endl;
        return 0;
    }

    int** res = new int*[r1];
    for(int i = 0; i < r1; i++){
        res[i] = new int[c2];
    }

    for(int i = 0; i< r1; i++){
        for(int j = 0; j< c2; j++){
            res[i][j] = 0;
            for( int k = 0; k < c1; k++){
                res[i][j]+= m1[i][k]*m2[k][j];
            }
        }
    }

    cout<<"The multiplication is: "<<endl;
    for(int i =0; i < r1; i++){
        for(int j = 0; j< c2; j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}