#include<iostream>
#include<vector>
using namespace std;

class Stack{
    int* arr;
    int top;
    int capacity;

    public:
    Stack(int size){
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int val){
        if(top == capacity-1){
            cout << "Stack Overflow" << endl;
            return;
        }

        arr[++top] = val;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        for(int i=top; i>=0; i--){
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    ~Stack(){
        delete[] arr;
        cout << "Stack destroyed" << endl;
    }
};

int main(){
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;
    Stack s(n);
    while(true){
        int choise;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check if empty\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choise;
        switch(choise){
            case 1: {
                int val;
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            }
            case 2: {
                s.pop();
                cout << "Popped top element." << endl;
                break;
            }
            case 3: {
                cout << "Top element is: " << s.peek() << endl;
                break;
            }
            case 4: {
                s.display();
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    }
    return 0;
}