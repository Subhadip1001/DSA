#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr, int target){
    int start = 0, end = arr.size()-1;

    while(start <= end){
        int mid = start + (end - start) / 2;
        if(target > arr[mid]){
            start = mid+1;
        }else if(target < arr[mid]){
            end = mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}

// Using recursion
int recBinarySearch(vector<int>arr, int target, int start, int end){
    if(start <= end){
        int mid = start+(end-start)/2;
        if(target > arr[mid]){
            return recBinarySearch(arr, target, mid+1, end);
        }else if(target < arr[mid]){
            return recBinarySearch(arr, target, start, mid-1);
        }else{
            return mid;
        }
    }
}

int main(){
    vector<int>arr = {-1, 0, 7, 8, 12, 15, 20};
    int target = 15;

    cout<<binarySearch(arr,target)<<endl;
    // Recursion
    cout<<recBinarySearch(arr, target, 0, arr.size()-1);
    return 0;
}