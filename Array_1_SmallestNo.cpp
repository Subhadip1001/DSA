#include <iostream>
#include<climits>

using namespace std;

int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];

    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int smallest = INT_MAX;
    // for(int i=0; i<n; i++){
    //     if(smallest > arr[i]){
    //         smallest = arr[i];
    //     }
    // }

    // another process 
    for(int i=0; i<n; i++){
        smallest = min(arr[i], smallest);
    }


    cout << "Smallest number in this array is : " << smallest << endl;
    return 0;
}
