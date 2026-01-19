#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// LeetCode : 31
// Next Permutation

void nextPermutation(vector<int>& nums){
    int pivot = -1;
    int n = nums.size();

    // Find the pivot
    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            pivot=i;
            break;
        }
    }

    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // Swap the pivot and next greater element
    for(int i=n-1; i>pivot; i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    reverse(nums.begin()+pivot+1, nums.end());
}

int main() {
    vector<int> nums = {1,2,3};
    nextPermutation(nums);
    for(int val : nums){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}