#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int secondLargest(vector<long>& nums){
    long fLargest = LONG_MIN;
    long sLargest = LONG_MIN;

    for(long val : nums){
        if(val > fLargest){
            sLargest = fLargest;
            fLargest = val;
        }else if(val<fLargest && val>sLargest){
            sLargest = val;
        }
    }

    return sLargest;
}

int main(){
    // vector<int> nums = {12,35,1,10,34,1};
    vector<long> nums = {28078,19451,935,28892,2242,3570,5480,231};
    long ans = secondLargest(nums);
    cout << "Second Largest element is : " << ans << endl;
    return 0;
}