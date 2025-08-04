#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int str, int mid, int end){
    vector<int> temp;
    int i = str, j = mid + 1;

    while(i <= mid && j<= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    // left part
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    // right part
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+str] = temp[idx];
    }
}

void sort(vector<int>& arr, int str, int end){
    if(str < end){
        int mid = str + (end - str) / 2;

        // sort left part
        sort(arr, str, mid);
        // sort right part
        sort(arr, mid + 1, end);

        merge(arr, str, mid, end);
    }
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    sort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}