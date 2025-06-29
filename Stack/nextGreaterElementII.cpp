#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Leetcode Problem: 503
// Next Greater Element II

vector<int> nextGreaterElement(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> stk;

    for(int i=2*n-1; i>=0; i--){
        while(!stk.empty() && stk.top() <= nums[i%n]){
            stk.pop();
        }

        ans[i%n] = stk.empty() ? -1 : stk.top();
        stk.push(nums[i%n]);
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4,3};
    vector<int> ans;
    ans = nextGreaterElement(nums);
    cout << "Next Greater Element: ";
    for(int val : ans){
        cout << val << " ";
    }
    return 0;
}