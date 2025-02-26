#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> num, int target){
    vector<int> ans;
    int i = 0, j = num.size()-1;

    while(i < j){
        int sum = num[i] + num[j];
        if(sum > target){
            j--;
        }else if(sum < target){
            i++;
        }else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main(){
    vector<int> num = {1, 7, 11, 15};
    int target = 9;
    vector<int> ans = pairSum(num, target);
    cout << "Index of pair sum is : " << ans[0] << " " << ans[1] <<endl;
    return 0;
}