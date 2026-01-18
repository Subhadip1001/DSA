#include <iostream>
using namespace std;

long long pascalTriangleValue(int row, int col){
    long long res = 1;

    for(int i=0; i<col; i++){
        res *= (row-i);
        res /= (i+1);
    }

    return res;
}

int main() {
    int r,c;
    cout << "Enter row : ";
    cin >> r;
    cout << "Enter col : ";
    cin >> c;
    long long ans = pascalTriangleValue(r-1, c-1);
    cout << ans << endl;
    return 0;
}