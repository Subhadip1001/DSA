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

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int pos){
        if(pos < 0){
            cout << "Invalid postion\n";
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout << "Invaild position\n";
                return;
            }
            temp = temp->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        if(head == NULL){
            cout << "Empty Linked List" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout << "Empty Linked List" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
        
    }

    // LeetCode : 206
    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // LeetCode : 876
    int middleOfTheLl(){
        Node* slow = head;
        Node* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    void printLl(){
        Node* temp = head;
        cout << "Linked list is :" << endl;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.insert(4, 2);
    ll.push_back(5);
    ll.printLl();

    int middle_value = ll.middleOfTheLl();
    cout << "Middle of this Linked List is : " << middle_value << endl;

    ll.reverse();
    ll.printLl();


    return 0;
}