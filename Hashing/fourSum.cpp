#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1; j<n; ){
            int k = j+1, l = n-1;

            while(k < l){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];

                if(sum < target){
                    k++;
                }else if(sum > target){
                    l--;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; l--;

                    while(k < l && nums[k] == nums[k-1]) k++;
                }
            }

            j++;
            while(j < n-1 && nums[j] == nums[j-1]) j++;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);
    cout << "The quadruplets that sum to " << target << " are: " << endl;
    for(vector<int> val : result){
        cout << "[" << val[0] << ", " << val[1] << ", " << val[2] << ", " << val[3] << "]" << endl;
    }

    return 0;
}