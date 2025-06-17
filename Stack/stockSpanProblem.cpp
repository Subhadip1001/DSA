#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Span : The maximum number of consecutive days just before day i (including day i) for which the stock price is less than or equal to the price on day i.

int main(){
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    int n = prices.size();

    // Solution
    vector<int> span(n, 0);
    stack<int> stk;

    for(int i=0; i<n; i++){
        while(stk.size() > 0 && prices[stk.top()] <= prices[i]){
            stk.pop();
        }

        if(stk.empty()){
            span[i] = i+1;
        }else{
            span[i] = i - stk.top();
        }

        stk.push(i);
    }

    // Print Stack Span
    cout << "Stock Span: ";
    for(int val :span){
        cout << val << " ";
    }
    cout << endl;


    return 0;
}