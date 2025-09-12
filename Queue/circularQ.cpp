#include<iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int currSixe, capacity;
    int f, r;

    public:
    CircularQueue(int size){
        capacity = size;
        currSixe = 0;
        arr = new int[capacity];
        f = 0; r = -1;
    }

    bool isEmpty(){
        return currSixe == 0;
    }

    void push(int data){
        if(currSixe == capacity){
            cout << "Circular Queue is full !!" << endl;
            return;
        }
        r = (r+1)%capacity;
        arr[r] = data;
        currSixe++;
    }

    void pop(){
        if(isEmpty()){
            cout << "Circular Queue is empty !!" << endl;
            return;
        }

        f = (f+1)%capacity;
        currSixe--;
    }

    int front(){
        if(isEmpty()){
            cout << "Circular Queue is empty !!" << endl;
            return -1;
        }
        return arr[f];
    }

    void display(){
        cout << "Array elemets are : ";
        for(int i=0; i<capacity; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.display();
    cq.pop();
    cq.push(4);
    cq.display();
    cout << "Circular Queue elemets are : ";
    while(!cq.isEmpty()){
        cout << cq.front() << " ";
        cq.pop();
    }
    cout << endl;
    return 0;
}