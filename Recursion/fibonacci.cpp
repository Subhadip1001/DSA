#include<iostream>
using namespace std;

// LeetCode: 509
// Fibonacci Number

int fib(int n){
    if(n == 0 || n == 1) return n;

    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << fib(n) << endl;
    return 0;
}