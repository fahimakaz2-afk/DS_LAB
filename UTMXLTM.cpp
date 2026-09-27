//Read and print an UTM and an LTM; multiply UTM × LTM.
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

void printMat(int mat[10][10], int n){
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}


int main(){
    int ltm[10][10];
    int utm[10][10];
    int res[10][10];

    int n1,n2;
    cout<<"Enter the order of UTM: ";
    cin>>n1;

    cout<<"Enter the elements of UTM: ";
    readUTM(utm,n1);

    cout<<"Enter the order of LTM: ";
    cin>>n2;
    cout<<"Enter the elements of LTM: ";
    readLTM(ltm,n2);

    cout<<"UTM Matrix"<<endl;
    printUTM(utm,n1);

    cout<<endl;

    cout<<"LTM Matrix"<<endl;

    printLTM(ltm,n2);

    if(n1!= n2){
        cout<<"Multiplication is not possible!!"<<endl;
    }

    for(int i = 0; i < n1; i++ ){
        for(int j = 0; j < n1; j++){
            res[i][j] = 0;
            for(int k = max(i,j); k < n1; k++){
                res[i][j]+=utm[i][k]*ltm[k][j];
            }
        }
    }
    
    cout<<"The Multiplication is: "<<endl;
    printMat(res,n1);
    
    return 0;
}