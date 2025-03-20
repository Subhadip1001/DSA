#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int>& coins){
    int n = coins.size();

    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(coins[mid]==0){
            swap(coins[low], coins[mid]);
            low++; mid++;
        }else if(coins[mid]==1){
            mid++;
        }else{
            swap(coins[mid], coins[high]);
            high--;
        }
    }
}

int main(){
    vector<int> coins = {1,0,2,1,1,2,0,2,0,2};
    sort012(coins);
    for(int i=0; i<coins.size(); i++){
        cout << coins[i] << "\t";
    }
    return 0;
}