#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> vec;
    public:
    void push(int val){
        vec.push_back(val);
    }

    bool isEmpty(){
        return vec.size() == 0;
    }

    int top(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
        }
        return vec[vec.size() - 1];
    }

    void pop(){
        if(!isEmpty()){
            vec.pop_back();
        }else{
            cout << "Stack is empty, cannot pop" << endl;
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element is: " << s.top() << endl;
    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}