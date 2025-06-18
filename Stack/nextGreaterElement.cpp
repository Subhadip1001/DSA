#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> stk;

    for(int i=n-1; i>=0; i--){
        while(!stk.empty() && stk.top() <= arr[i]){
            stk.pop();
        }

        if(stk.empty()){
            ans[i] = -1;
        }else{
            ans[i] = stk.top();
        }

        stk.push(arr[i]);
    }

    return ans;
}

int main(){
    vector<int> arr = {6, 8, 0, 1, 3};
    int n = arr.size();

    vector<int> ans = nextGreaterElement(arr, n);
    cout << "Next Greater Element: ";
    for(int val : ans){
        cout << val << " ";
    }
    return 0;
}