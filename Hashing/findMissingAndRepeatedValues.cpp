#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// LeetCode : 2965
// Find Missing and Repeated Values

vector<int> find(vector<vector<int>>& grid){
    int n = grid.size();
    unordered_set<int> s;
    vector<int> ans;
    int a, b;

    int actualSum = 0, expSum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }

            s.insert(grid[i][j]);
        }
    }

    expSum = (n*n) * (n*n + 1) / 2;
    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int main(){
    vector<vector<int>> grid = {
        {9,1,7},
        {8,9,2},
        {3,4,6}
    };

    vector<int> result = find(grid);
    cout << "Repeated and Missing Values: ";
    for (int value : result){
        cout << value << " ";
    }
    return 0;
}