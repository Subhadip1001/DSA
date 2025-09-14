#include<iostream>
#include<queue>
using namespace std;

// LeetCode : 225
// Implement Stack using Queues

class Mystack{
    public:
    queue<int> q1;
    queue<int> q2;

    void push(int x){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

int main(){
    Mystack stk;
    stk.push(2);
    stk.push(1);
    cout << stk.top() << endl;
    cout << stk.pop() << endl;
    stk.empty();
    return 0;
}