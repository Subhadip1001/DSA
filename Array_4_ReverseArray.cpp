#include<iostream>
using namespace std;

void reveseArray(int arr[], int sz){
    int start = 0, end = sz-1;
    while (start < end){
        swap(arr[start], arr[end]);
        start++; end--;
    }
    
}

int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    reveseArray(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}