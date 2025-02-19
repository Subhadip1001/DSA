#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums){
    int ans = 0;
    for(int val: nums){
        ans ^= val;
    }

    return ans;
}

int main(){
    vector<int> nums = {4,1,2,1,2};
    int ans = singleNumber(nums);
    cout << ans << endl;
    return 0;
}