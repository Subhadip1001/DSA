#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// LeetCode: 155
// Min Stack

class MinStack {
    stack<pair<int, int>> stk;
public:
    MinStack() {
       
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
        } else{
            int minVal = min(val, stk.top().second);
            stk.push({val, minVal});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum Element: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top Element: " << minStack.top() << endl; // Returns 0
    cout << "Minimum Element: " << minStack.getMin() << endl; // Returns -2

    return 0;
}