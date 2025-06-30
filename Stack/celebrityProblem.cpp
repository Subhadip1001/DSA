#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int getCelebrity(vector<vector<int>>& arr){
    int n = arr.size();
    stack<int> stk;

    for(int i=0; i<n; i++){
        stk.push(i);
    }

    while(stk.size() > 1){
        int i = stk.top();
        stk.pop();

        int j = stk.top();
        stk.pop();

        if(arr[i][j] == 0){
            stk.push(i);
        }else{
            stk.push(j);
        }

        int celeb = stk.top();

        for(int i=0; i<n; i++){
            if((i!=celeb) && (arr[i][celeb] == 0 || arr[celeb][i] == 1)){
                return -1;
            }
        }

        return celeb;
    }
}

int main(){
    vector<vector<int>> arr ={{0,1,0},{0,0,0},{0,1,0}};

    int ans = getCelebrity(arr);
    cout << "Celebrity is : " << ans << endl;
    return 0;
}