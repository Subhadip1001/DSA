#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// Leetcode Problem: 496
// Next Greater Element I

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2){
    unordered_map<int, int> map;
    stack<int> stk;

    for (int i = nums2.size() - 1; i >= 0; i--){
        while (!stk.empty() && stk.top() <= nums2[i]){
            stk.pop();
        }

        if (stk.empty()){
            map[nums2[i]] = -1;
        }else{
            map[nums2[i]] = stk.top();
        }

        stk.push(nums2[i]);
    }

    int n = nums1.size();
    vector<int> ans;

    for (int i = 0; i < n; i++){
        ans.push_back(map[nums1[i]]);
    }

    return ans;
}

int main(){
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans;
    ans = nextGreaterElement(nums1, nums2);
    cout << "Next Greater Element: ";
    for (int val : ans){
        cout << val << " ";
    }
    return 0;
}