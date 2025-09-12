#include<iostream>
#include<deque>
using namespace  std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    cout << "Front value : " << dq.front() << endl;
    cout << "Back value : " << dq.back() << endl;

    dq.push_front(4);

    cout << "Deque elements are : ";
    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
    return 0;
}
