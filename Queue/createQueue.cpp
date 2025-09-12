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

class Queue{
    Node* head;
    Node* tail;
    
    public:
    Queue(){
        head = tail = NULL;
    }

    // empty fuction: check queue is empty or not
    bool empty(){
        return head == NULL;
    }

    // push fuction: add value at the tail of the linked list
    void push(int val){
        Node* newNode = new Node(val);
        if(empty()){
            head = tail = newNode;
        }else{;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // pop function: pop elements from the front of the linked list
    void pop(){
        if(empty()){
            cout << "Linked List is empty !!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Front fuction: told about front value
    int front(){
        if(empty()){
            cout << "Linked List is empty !!" << endl;
            return -1;
        }
        return head->data;
    }

    // display fuction: showing all the data
    void diaplay(){
        if(empty()){
            cout << "Linked List is empty !!" << endl;
            return;
        }

        cout << "Queue elements are : ";
        while(!empty()){
            cout << front() << " ";
            pop();
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    cout << "Queue front elements is : " << q.front() << endl;
    q.push(3);
    q.pop();
    q.diaplay();
    return 0;
}