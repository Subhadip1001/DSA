#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main(){
    int arr[] = {3, 5, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    display(arr, n);
    return 0;
}