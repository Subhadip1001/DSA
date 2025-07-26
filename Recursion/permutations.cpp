#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// LeetCode: 46
// Given an array of distinct integers, return all possible permutations. You can return the answer in any order.

void getPermutations(vector<int>& nums, int idx, vector<vector<int>>& ans){
    if(idx == nums.size()){
        ans.push_back({nums});
        return;
    }

    for(int i=idx; i<nums.size(); i++){
        swap(nums[idx], nums[i]);
        getPermutations(nums, idx + 1, ans);

        swap(nums[idx], nums[i]); // backtrack to restore the original order
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    getPermutations(nums, 0, ans);
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for(const auto& perm : result){
        cout << "[ ";
        for(int val : perm){
            cout << val << " ";
        }
        cout << "] ";
    }

    return 0;
}