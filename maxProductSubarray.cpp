#include<iostream>
#include<vector>
using namespace std;

// LeetCode : 152
// Maximum Product Subarray

int maxProduct(vector<int>& nums){
    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for(int i=1; i<nums.size(); i++){
        int curr = nums[i];

        int tempMax = max(curr, max(maxProd*curr, minProd*curr));
        minProd = min(curr, min(maxProd*curr, minProd*curr));
        maxProd = tempMax;

        ans = max(ans, maxProd);
    }

    return ans;
}

int main(){
    // vector<int> nums = {-1,-2,-9,-6};
    vector<int> nums = {2,3,-2,4};
    cout << "Maximum Product Subarray is : " << maxProduct(nums) << endl;
    return 0;
}