#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int smallInx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[smallInx]){
                smallInx = j;
            }
        }
        swap(arr[i], arr[smallInx]);
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main(){
    int arr[] = {3, 6, 7, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    display(arr, n);
    return 0;
}