#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "ENter array elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int indx = -1;
    int largest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > largest){
            largest = arr[i];
            indx = i;
        }
    }

    //another process
    // for(int i=0; i<n; i++){
    //     largest = max(arr[i], largest);
    // }

    cout << "Largest number is : " << largest << endl;
    cout << "Index of Largest number is : " << indx;
    return 0;
}