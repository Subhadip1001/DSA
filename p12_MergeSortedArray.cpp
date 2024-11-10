#include<iostream>
#include<vector>
using namespace std;

void solution(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int indx = m+n-1, i = m-1, j = n-1;

    while(i >= 0 && j >= 0){
        if(nums1[i] >= nums2[j]){
            nums1[indx--] = nums1[i--];
        }else{
            nums1[indx--] = nums2[j--];
        }
    }

    while(j >= 0){
        nums1[indx--] = nums2[j--];
    }
}

void display(vector<int> &nums1, int m){
    for(int i=0; i<m; i++){
        cout << nums1[i] <<" ";
    }
    cout << endl;
}

int main(){
    vector<int>nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int>nums2 = {2,5,6};
    int n = 3;

    solution(nums1, m, nums2, n);
    display(nums1, m+n);
    return 0;
}