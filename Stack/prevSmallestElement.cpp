#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> Solution(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> stk;

    for(int i=0; i<=n; i++){
        while(!stk.empty() && stk.top() >= nums[i]){
            stk.pop();
        }

        if(stk.empty()){
            ans[i] = -1;
        }else{
            ans[i] = stk.top();
        }

        stk.push(nums[i]);
    }

    return ans;
}

int main(){
    vector<int> nums = {3, 1, 0, 8, 6};
    vector<int> ans = Solution(nums);
    cout << "Previous Smaller Element: ";
    for(int val : ans){
        cout << val << " ";
    }
    return 0;
}