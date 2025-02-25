#include<iostream>
#include<climits>
using namespace std;

// Max sum of subarray
void BruteForceApproach(int arr[], int sz){
    int maxSum = INT_MIN;

    for (int st=0; st<sz; st++){
        int currentSum = 0;
        for(int end=st; end<sz; end++){
            currentSum += arr[end];
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << "Max sum of subarray is : " << maxSum;
}

// Kadanse's Algorithm
int kadanseAlgo(int arr[], int sz){
    int maxSum = INT_MIN;
    int currentSum = 0;

    for(int i=0; i<sz; i++){
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if(currentSum < 0){
            currentSum = 0;
        }
    }

    return maxSum;
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
    BruteForceApproach(arr, n);

    // Kadanse's Algorithm
    cout << "\nMax sum of subarray is : " << kadanseAlgo(arr, n);
    return 0;
}