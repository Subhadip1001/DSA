#include <iostream>
#include<vector>
using namespace std;

// LeetCode : 229. Majority Element II

vector<int> majorityElement(vector<int>& nums){
    int freq1 = 0, freq2 = 0;
        int ele1 = 0, ele2 = 0;

        for (int x : nums) {
            if (freq1 > 0 && x == ele1) freq1++;
            else if (freq2 > 0 && x == ele2) freq2++;
            else if (freq1 == 0) {
                ele1 = x;
                freq1 = 1;
            }
            else if (freq2 == 0) {
                ele2 = x;
                freq2 = 1;
            }
            else {
                freq1--;
                freq2--;
            }
        }

        // verify
        freq1 = 0; freq2 = 0;
        for (int x : nums) {
            if (x == ele1) freq1++;
            else if (x == ele2) freq2++;   // else-if is IMPORTANT
        }

        vector<int> res;
        int mini = nums.size() / 3 + 1;

        if (freq1 >= mini) res.push_back(ele1);
        if (freq2 >= mini) res.push_back(ele2);

        return res;
}

int main() {
    vector<int> nums = {4,2,1,1};
    vector<int> ans = majorityElement(nums);

    for(int val : ans){
        cout << val << " ";
    }
    return 0;
}