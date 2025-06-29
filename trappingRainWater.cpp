#include<iostream>
#include<vector>
using namespace std;

// Leetcode Problem: 42
// Trapping Rain Water

// Time Complexity: O(n) && Space Complexity: O(n)
int trap(vector<int>& height){
    int n = height.size();
    if(n == 0) return 0;

    vector<int> lmax(n, 0), rmax(n, 0);
    lmax[0] = height[0];
    rmax[n-1] = height[n-1];

    for(int i=1; i<n; i++){
        lmax[i] = max(lmax[i-1], height[i]);
    }
    for(int i=n-2; i>=0; i--){
        rmax[i] = max(rmax[i+1], height[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += min(lmax[i], rmax[i]) - height[i];
    }

    return ans;
}

// Optimized Approach: Two Pointer Technique
// Time Complexity: O(n) && Space Complexity: O(1)
int trapOptimized(vector<int>& height){
    int n = height.size();
    if(n == 0) return 0;

    int left = 0, right = n - 1;
    int lmax = 0, rmax = 0;
    int ans = 0;

    while (left < right){
        lmax = max(lmax, height[left]);
        rmax = max(rmax, height[right]);

        if (lmax < rmax){
            ans += lmax - height[left];
            left++;
        }else{
            ans += rmax - height[right];
            right--;
        }
    }

    return ans;
}

int main(){
    vector<int> height = {4,2,0,3,2,5};
    int ans;
    // ans = trap(height);
    ans = trapOptimized(height);
    cout << "Trapping Rain Water: " << ans << endl;
    return 0;
}