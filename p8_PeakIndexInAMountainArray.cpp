#include<iostream>
#include<vector>
using namespace std;

int peakIndex(vector<int>& arr){
    int st=1, end=arr.size()-2;
    while(st <= end){
        int mid = st+(end-st)/2;
        if(arr[mid+1]<arr[mid] && arr[mid]>arr[mid-1]){
            return mid;
        }else if(arr[mid-1] < arr[mid]){ //right
            st = mid+1;
        }else{ //left
            end = mid-1;
        }
    }

    return -1;
}

int main(){
    vector<int>arr = {0, 2, 5, 8, 9, 4, 1};
    
    cout << peakIndex(arr) <<endl;
    return 0;
}