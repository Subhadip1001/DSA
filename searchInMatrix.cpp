#include <iostream>
#include<vector>
using namespace std;

// LeetCode : 74. Search a 2D Matrix

bool searchRow(vector<vector<int>>& matrix, int target, int row){
    int n = matrix[0].size();
    int str = 0, end = n-1;
    while(str <= end){
        int mid = str+(end-str)/2;

        if(target == matrix[row][mid]){
            return true;
        }else if(target >= matrix[row][mid]){
            str = mid+1;
        }else{
            end = mid-1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m = matrix.size(), n = matrix[0].size();
    int strRow = 0, endRow = m-1;

    while(strRow <= endRow){
        int midRow = strRow + (endRow - strRow)/2;

        if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
            return searchRow(matrix, target, midRow);
        }else if(target >= matrix[midRow][n-1]){
            strRow = midRow+1;
        }else{
            endRow = midRow-1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 100;
    bool ans = searchMatrix(matrix, target);
    cout << ans << endl;
    return 0;
}