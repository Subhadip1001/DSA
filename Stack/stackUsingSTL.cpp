#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    st.pop();

    cout << "Top element is: " << st.top() << endl;
    cout << "Stack size is: " << st.size() << endl;

    cout << "Stack elements are: ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}