#include<iostream>
#include<vector>
#include<set>
using namespace std;

// LeetCode: 39
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order. The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

class Solution {
    public:
    set<vector<int>> s;
    void getAllCombinations(vector<int>& candidates,int idx, int target, vector<vector<int>>& ans, vector<int>& combin){
        if(idx == candidates.size() || target < 0){
            return;
        }

        if(target == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }


        combin.push_back(candidates[idx]);
        // single
        getAllCombinations(candidates, idx+1, target-candidates[idx], ans, combin);

        // multiple
        getAllCombinations(candidates, idx, target-candidates[idx], ans, combin);

        // backtrack
        combin.pop_back();
        getAllCombinations(candidates, idx+1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(candidates, 0, target, ans, combin);
        return ans;
    }
};

int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
    for(const auto& vec : ans){
        cout << "[ ";
        for(int num : vec){
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}