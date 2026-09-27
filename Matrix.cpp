//Matrix read,print,mul using pointers
#include<iostream>
using namespace std;

void read(int** matrix, int row, int col ){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<"Enter Element "<<"[" << i << "]" << "[" <<j <<"]: ";
            cin >>*(*(matrix+i)+j);
        }
    }
}

void print(int** matrix, int row,int col){
    cout<<"Elements are: "<<endl;
    for(int i = 0; i < row; i++){
        for(int j= 0; j < col; j++){
            cout<<*(*(matrix+i)+j)<<"\t";
        }
        cout<<endl;
    }
}

void mul(int** a, int** b, int** &c, int r1,int c1,int r2, int c2 ){
    if(c1 != r2){
        cout<<"Multiplication not possible";
        c = nullptr;
        return;
    }

    c = new int*[r1];
    for(int i= 0; i<r1; i++){
        c[i] = new int[c2];
    }

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            c[i][j] = 0;
            for(int k = 0; k< c1; k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
  
}


int main(){
    int row1,row2;
    int col1,col2;
    

    cout<<"Enter no. of rows and column of matrix1: ";
    cin >>row1 >> col1;

    int **a = new int*[row1];
    for(int i = 0; i <row1 ;i++){
        a[i] = new int[col1];
    }
    read(a,row1,col1);

    cout<<"Enter no. of rows and column of matrix1: ";
    cin >>row2 >> col2;

    int **b = new int*[row2];
    for(int i = 0; i <row2 ;i++){
        b[i] = new int[col2];
    }
    
    read(b,row2,col2);

    int **c;
    mul(a,b,c,row1,col1,row2,col2);

    cout<<"First matrix: "<<endl;
    print(a,row1,col1);
    cout<<"second matrix: "<<endl;
    print(b,row2,col2);

    if(c != nullptr){ 
        cout<<"Multiplication is:"<<endl;   
        print(c,row1,col2);
   
        for(int i = 0; i < row1; i++) {
            delete[] c[i];
        }
        delete[] c;
    }

    for(int i = 0; i < row1; i++) {
        delete[] a[i];
    }
    delete[] a;

    for(int i = 0; i < row2; i++) {
        delete[] b[i];
    }
    delete[] b;

   

    
}