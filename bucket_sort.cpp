#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }

        void insert(int x){
            Node* newNode = new Node(x);
            newNode->next = head;
            head = newNode;
        }

        bool isEmpty(){
            return head == nullptr;
        }

        int deleteLast() {
        if (head->next == nullptr) {
            int x = head->data;
            delete head;
            head = nullptr;
            return x;
        }

        Node* temp = head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node* last = temp->next;
        int x = last->data;

        delete last;
        temp->next = nullptr;

        return x;
    }

    // Destructor: free remaining nodes
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

};

class BucketSort{
    public:
        void sort(int a[], int n){
            if(n <= 0)
                return;

            //find maximum

            int m = a[0];

            for(int i = 1; i < n; i++){
                if(a[i] > m)
                    m = a[i];
            }

            if(m < 0){
                cout << "Only non- negative integers supported.";
                return;
            }

            // create m+1 buckets

            LinkedList* L = new LinkedList[m+1];

            //insert elements into buckets

            for(int i = 0; i < n; i++){
                L[a[i]].insert(a[i]);
            }

            int i = 0;

            for(int j = 0; j <= m; j++){
                while(!L[j].isEmpty()){
                    a[i] = L[j].deleteLast();
                    i++;
                }
            }

            delete[] L;
        }

};

int main(){

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!";
        return 0;
    }

    int* a = new int[n];

    cout << "Enter " << n << " non-negative integers: ";

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    BucketSort b;
    b.sort(a, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    delete[] a;

    return 0;
}