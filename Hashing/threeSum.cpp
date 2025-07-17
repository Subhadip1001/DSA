#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// LeetCode: 15
// 3Sum

// TC: O(n^2) & SC: O(1) => Two Pointer Approach
vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1, k = n-1;

        while(j < k){
            int sum = nums[i]+nums[j]+nums[k];

            if(sum < 0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++; k--;

                while(j < k && nums[j] == nums[j+1]) j++;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    cout << "The triplets that sum to zero are: " << endl;
    for(vector<int> triplet : result){
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    return 0;
}