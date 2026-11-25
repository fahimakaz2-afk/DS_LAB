/* Binary tree using array 
    1.Build(i)
    2.isEmpty()
    3.size()
    4.height()
    5.postorder(i)
    6.inorder(i)
    7.preorder(i)
    8.search(x)
    9.levelorder()

*/


#include<iostream>
#include <queue>
using namespace std;

class BinaryTree{
public:
    char*a;
    int h;
    int n;

    BinaryTree(int height){
        h = height;
        n = (1 << h)-1;

        a = new char[n];
        for(int i = 0; i < n; i++){
            a[i] = '\0';
        }
    }

    void build(int i){
        if(i>=n)
            return;
        if(i == 0){
            cout << "Enter the root node: ";
        }
        else if(i%2 == 1){
            cout << "Enter the left child of "<<a[(i-1)/2] <<": ";
        }
        else{
            cout<<"Enter the right child "<<a[(i-1)/2] <<": ";
        }

        cin >>a[i];
        char ans;
        cout<<"Does "<<a[i]<<" have left child(Y/y)? ";
        cin>>ans;

        if((ans == 'Y' || ans == 'y') && (2*(i+1)-1 < n)){
            build(2*(i+1) - 1);
        }

        cout << "Does "<<a[i]<<" have right child(Y/y)? ";
        cin>>ans;

        if((ans == 'Y' || ans == 'y') && (2*(i+1) < n)){
            build(2*(i+1));
        }
    }

    bool isEmpty(){
        if(a[0] == '\0'){
            return true;
        }
        else{
            return false;
        }
    }

    int size(){
        int sz = 0;

        for(int i =0; i <n; i++)
            if(a[0]!=0) sz++;
        
        return sz;
    }

    void preorder(int i){

        //print root
        if(i < n && a[0] != '\0' )
            cout<<a[i]<<" ";

        //left 
        if(2*i+1 <= n)
        preorder(2*i+1);

        //right
        if(2*i+2 <= n)
            preorder(2*i+2);
    }

    void inorder(int i){
        if(i < n && a[0] != '\0' ){

            if(2*i+1 < n && a[2*i+1] != '\0')
                    inorder(2*i+1);
            
            cout << a[i] <<" ";

            if(2*i+2 < n && a[2*i+2] != '\0')
                    inorder(2*i+2);
                    
        }
    }

    void postorder(int i){
        if(i < n && a[0] != '\0' ){

            if(2*i+1 < n && a[2*i+1]!= '\0')
                postorder(2*i+1);

            if(2*i+2 < n && a[2*i+2] != '\0')
                postorder(2*i+2);

            cout << a[i]<<" ";
        }
    }

    int search(int x){
        for(int i = 0 ; i < n; i++){
            if(a[i] == x)
                return i;
        }
        cout<<"Not found!! "<<endl;
        return -1;
    }

    int height(){
        return h;
    }

     void levelOrder() {
        if (a[0] == '\0')
            return;

        queue<int> q;

        q.push(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            cout << a[i] << " ";

            if (2 * i + 1 < n && a[2 * i + 1] != '\0')
                q.push(2 * i + 1);

            if (2 * i + 2 < n && a[2 * i + 2] != '\0')
                q.push(2 * i + 2);
        }
    }

};

int main() {
    int h;

    cout << "Enter height of tree (number of levels): ";
    cin >> h;

    if (h < 1) {
        cout << "Invalid height!";
        return 0;
    }

    BinaryTree t(h);

    cout << "\n--- Create Binary Tree ---\n";
    t.build(0);

    cout << "\n\nPreorder Traversal: ";
    t.preorder(0);

    cout << "\nInorder Traversal: ";
    t.inorder(0);

    cout << "\nPostorder Traversal: ";
    t.postorder(0);

    cout << "\nLevel Order Traversal: ";
    t.levelOrder();

    cout << endl;

    return 0;
}