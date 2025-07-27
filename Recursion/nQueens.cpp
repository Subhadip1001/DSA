#include<iostream>
#include<vector>
using namespace std;

// LeetCode: 51
// The N-Queens puzzle is the problem of placing N chess queens on an N×N chessboard such that no two queens threaten each other.

class Solution{
    public:
    bool isSafe(vector<string>& board, int row, int col, int n){
        // Horizontal
        for(int j=0; j<n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        // Vertical
        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // Left-digonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        
        // Right-digonal
        for(int i=row, j=col; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans){
        if(row == n){
            ans.push_back({board});
            return;
        }

        for(int j=0; j<n; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                nQueens(board, row+1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n){
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nQueens(board, 0, n, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the value of N for N-Queens: ";
    cin >> n;

    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(n);

    cout << "Number of solutions: " << results.size() << "\n\n";

    for(int i = 0; i < results.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for(const string& row : results[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}