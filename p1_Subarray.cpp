#include<iostream>
using namespace std;

void dispaySubarray(int arr[], int sz){
    for(int st=0; st<sz; st++){
        for(int end=st; end<sz; end++){
            for(int i=st; i<=end; i++){
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "ENter array elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dispaySubarray(arr, n);
    return 0;
}