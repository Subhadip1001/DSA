#include<iostream>
#include<vector>
using namespace std;

// LeetCode: 37
// The Sudoku puzzle is the problem of filling a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 subgrids that compose the grid contain all of the digits from 1 to 9.

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        // Horizontal
        for(int j=0; j<9; j++){
            if(board[row][j] == dig){
                return false;
            }
        }

        // Vertical
        for(int i=0; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        // Grid
        int sRow = (row/3)*3;
        int sCol = (col/3)*3;
        for(int i=sRow; i<=sRow+2; i++){
            for(int j=sCol; j<=sCol+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col){
        if(row == 9){
            return true;
        }

        int nextRow = row, nextCol = col+1;
        if(nextCol == 9){
            nextRow = row+1;
            nextCol = 0;
        }

        if(board[row][col] != '.'){
            return helper(board, nextRow, nextCol);
        }

        // place digit
        for(char dig='1'; dig<='9'; dig++){
            if(isSafe(board, row, col, dig)){
                board[row][col] = dig;
                if(helper(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};

int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution sol;
    sol.solveSudoku(board);
    cout << "Solved Sudoku:" << endl;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}