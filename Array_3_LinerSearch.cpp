#include<iostream>
using namespace std;

int LinearSearch(int arr[], int size, int trg){
    for(int i=0; i<size; i++){
        if(trg == arr[i]){
            return i;
        }
    }
    return -1;
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

    int target;
    cout << " enter your target elemet : ";
    cin >> target;

    int indx = LinearSearch(arr, n, target);

    if(indx == -1){
        cout << "Target is not in this array" << endl;
    }else{
        cout << "Target in " << indx << endl;
    }

    return 0;
}