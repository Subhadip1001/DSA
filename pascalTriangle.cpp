#include <iostream>
#include<vector>
using namespace std;

// LeetCode : 118. Pascal's Triangle

class pascalTriangle{
    public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col=1; col<row; col++){
            ans *= (row-col);
            ans /= col;
            ansRow.push_back(ans);
        }

        return ansRow;
    }

    vector<vector<int>> generate(int numRows){
        vector<vector<int>> ans;
        for(int i=1; i<numRows; i++){
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};


int main() {
    pascalTriangle pt;
    cout << "Enter rows : ";
    int numRows;
    cin >> numRows;

    vector<vector<int>> ans = pt.generate(numRows);
    cout << "Pascal's Triangle is : " << endl;
    for(vector<int> vals : ans){
        for(int num : vals){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}