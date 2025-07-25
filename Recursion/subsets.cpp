#include<iostream>
#include<vector>
using namespace std;

// LeetCode: 78
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets){
    if(i == nums.size()){
        allSubsets.push_back({ans});
        return;
    }

    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);

    ans.pop_back();
    // exclude
    getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(nums, ans, 0, allSubsets);

    return allSubsets;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for(const auto& subset : result){
        cout << "[ ";
        for(int val : subset){
            cout << val << " ";
        }
        cout << "] ";
    }

    return 0;
}