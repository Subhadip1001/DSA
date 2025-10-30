#include<iostream>
#include<vector>
using namespace std;

// LeetCode: 73
// Set Matrix Zeroes

void setZeros(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size();
    vector<int> row(m, 0), col(n, 0);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeros(matrix);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
