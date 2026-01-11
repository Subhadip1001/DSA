#include <iostream>
using namespace std;

void printTillN(int n){
    if(n == 0) return;

    printTillN(n - 1);
    cout << n << " ";
}

int main() {
    int n = 5;
    printTillN(n);
    return 0;
}