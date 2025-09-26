#include<iostream>
#include<vector>
using namespace std;

// LeetCode : 26
// Remove Duplicates from Sorted Array

int removeDuplicate(vector<int>& nums){
    if(nums.empty()) return 0;

    int idx = 1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i] != nums[i-1]){
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << "There are " << removeDuplicate(nums) << " unique elemets in this array \n";
    return 0;
}