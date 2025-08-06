#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int st, int end){
    int idx = st-1, pivot = arr[end];

    for(int i=st; i<end; i++){
        if(arr[i] <= pivot){
            idx++;
            swap(arr[i], arr[idx]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]); // place pivot in correct position
    return idx;
}

void quickSort(vector<int>& arr, int str, int end){
    if(str < end){
        int pivIdx = partition(arr, str, end);

        quickSort(arr, str, pivIdx-1); // left half
        quickSort(arr, pivIdx+1, end); // right half
    }
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}