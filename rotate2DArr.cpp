#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// LeetCode : 48. Rotate Image

void rotate(vector<vector<int>>& matrix){
    int n = matrix.size();

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


int main() {
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);

    for(vector<int> val : matrix){
        for(int num : val){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}