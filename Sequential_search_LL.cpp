//Sequential search in Linked list
#include<iostream>
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

    int sequential_search(int x){
        int i = 0;
        int idx = -1;
        Node* temp = head;

        while (temp != NULL)
        {
            if(temp->data == x){
                idx = i;
                break;
            }
            temp = temp->next; 
            i++;
        }
        
        return idx;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data << "->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
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


    int idx = l1.sequential_search(x);

    if(idx == -1)
        cout<<"Not Found!!"<<endl;
    else
        cout<<"Element is Found at: "<< idx << endl;
    
    
    return 0;
}