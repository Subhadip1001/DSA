#include <iostream>
#include <vector>
using namespace std;

void productOfArray(int arr[], int s)
{
    vector<int> ans(s, 1);

    /*
    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            if(i != j){
                ans[i] *= arr[j];
            }
        }
    }
    */

    // Prefix
    for (int i = 1; i < s; i++){
        ans[i] = ans[i - 1] * arr[i - 1];
    }

    // Suffix
    int suffix = 1;
    for(int i=2; i>=0; i--){
        suffix *= arr[i+1];
        ans[i] *= suffix;
    }

    cout << "Ans : ";
    for (int i = 0; i < s; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    productOfArray(arr, n);

    return 0;
}