#include<iostream>
using namespace std;

int buyAndSell(int prices[], int s){
    int maxProfit = 0;
    int bestBuy = prices[0];

    for(int i=0; i<s; i++){
        if(prices[i] > bestBuy){
            maxProfit = max(maxProfit, prices[i]-bestBuy);
        }

        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main(){
    int n;
    cout << "Enter pricesay size: ";
    cin >> n;

    int prices[n];
    cout << "Enter your prices : ";
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }

    int maxProfit = buyAndSell(prices, n);
    cout << "Maximun Profit = " << maxProfit << endl;

    return 0;
}