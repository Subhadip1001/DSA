#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// LeetCode: 287
// Find the Duplicate Number

// TC: O(n) & SC: O(n)
int findDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    int ans;

    for(int val: nums){
        if(s.find(val) != s.end()){
            ans = val;
        }

        s.insert(val);
    }

    return ans;
}

// TC: O(n) & SC: O(1) => Fast and Slow Pointer Approach
int findDuplicateOptimized(vector<int>& nums){
    int slow = 0, fast = 0;

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);

    slow = 0;

    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main(){
    vector<int> nums = {1, 3, 4, 2, 2};
    // int result = findDuplicate(nums);
    int result = findDuplicateOptimized(nums);
    cout << "The duplicate number is: " << result << endl;
    return 0;
}
