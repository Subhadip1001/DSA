#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr, int n){
    if(n == 0 || n == 1) return true;

    return (arr[n-1] >= arr[n-2]) && isSorted(arr, n-1);
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    if(isSorted(arr, n)){
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }
    return 0;
}