#include<iostream>
using namespace std;

int singleElement(int arr[],int n){

    if(n == 1) return arr[0];

    int st=0,end=n-1;
    while(st <= end){
        int mid = st + (end - st)/2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
             return arr[mid];
        }
        
        if(mid % 2 == 0){
            if(arr[mid-1] == arr[mid]){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }else{
            if(arr[mid-1] == arr[mid]){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,1,2,3,3,4,4,8,8};
    int ans = singleElement(arr, (sizeof(arr)/sizeof(arr[0])));
    cout << "Single element in this sorted array is : " << ans << endl;
    return 0;
}