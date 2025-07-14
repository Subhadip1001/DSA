#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// LeetCode: 1
// Two Sum

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> m;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++){
        int first = nums[i];
        int second = target - first;

        if(m.find(second) != m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }

        m[first] = i;
    }

    return ans;
}

int main(){
    vector<int> nums = {11, 7, 4, 15, 2};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices of the two numbers that add up to " << target << ": ";
    for(int index : result){
        cout << index << " ";
    }
    return 0;
}