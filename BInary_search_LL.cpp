// Binary search in Linked List, only if linked list is sorted

#include<iostream>
#include<algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{

public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

   void insert(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data << "->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    
    int Size(){
        int s = 0;
        Node* curr = head;
        while(curr != NULL){
            curr = curr->next;
            s++;
        }
        return s;
    }

    int Binary_search(int val){
        if(head == NULL) return -1;

        Node* last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }

        if(val > last->data ){
            return -1;
        }

        if(val < head->data || val > last->data) return -1;
        

        int low = 0;
        int high = Size() - 1;

        while(low <= high){
            int mid = (low + high)/2;

            Node* curr = head;
            for(int i = 0; i < mid; i++){
                curr = curr->next;
            }

            if(val == curr->data) return mid;

            else if(val < curr->data) high = mid-1;

            else low = mid + 1;


        }
        return -1;
    }
};


int main(){
    LinkedList l1;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        l1.insert(val);
    }

    l1.display();

    int x;
    cout<<"Element u want to search? ";
    cin>>x;


    int idx = l1.Binary_search(x);

    if(idx == -1)
        cout<<"Not Found!!"<<endl;
    else
        cout<<"Element is Found at: "<< idx << endl;
    
    
    return 0;
}