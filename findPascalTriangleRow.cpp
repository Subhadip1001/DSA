#include <iostream>
#include<vector>
using namespace std;

void rowOfPascalTriangle(int n){
    int res = 1;

    cout << res << " ";
    for(int i=1; i<n; i++){
        res *= n-i;
        res /= i;
        cout << res << " ";
    }
}

int main() {
    int n;
    cout << "Enter row : ";
    cin >> n;
    rowOfPascalTriangle(n);
    return 0;
}