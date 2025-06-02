#include<iostream>
using namespace std;

// LeetCode: 21
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

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
    private:
    Node* head;
    Node* tail;

    
    public:
    Node* getHead(){
        return head;
    }

    void setHead(Node* newHead){
        head = newHead;
    }

    List(){
        head = tail = NULL;
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

    void display(){
        Node* temp = head;
        cout << "Linked list is :" << endl;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class solution{
    public:
    Node* mergeTwoLists(Node* list1, Node* list2){
        if(list1 == NULL || list2 == NULL){
            return list1 == NULL ? list2 : list1;
        }

        if(list1->data <= list2->data){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main(){
    List ll1;
    List ll2;
    solution s;
    
    // List 1->2->3
    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(3);
    ll1.display();
    
    // List 3->5->6
    ll2.push_back(3);
    ll2.push_back(5);
    ll2.push_back(6);
    ll2.display();

    Node* mergedHead = s.mergeTwoLists(ll1.getHead(), ll2.getHead());
    List mergedList;
    mergedList.setHead(mergedHead);
    
    cout << "\nMerged list:" << endl;
    mergedList.display();
    return 0;
}