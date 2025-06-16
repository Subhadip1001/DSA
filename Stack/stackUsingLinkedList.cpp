#include<iostream>
#include<list>
using namespace std;

class Stack{
    list<int> lst;
    public:
    void push(int val){
        lst.push_front(val);
    }

    bool isEmpty(){
        return lst.size() == 0;
    }

    void pop(){
        if(!isEmpty()){
            lst.pop_front();
        } else {
            cout << "Stack is empty, cannot pop" << endl;
        }
    }

    void top(){
        if(lst.empty()){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << lst.front() << endl;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top of the stack is : ";
    s.top();
    cout << "Stack elements are: "<< endl;
    while(!s.isEmpty()){
        s.top();
        s.pop();
    }
    return 0;
}