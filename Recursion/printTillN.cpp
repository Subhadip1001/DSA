#include <iostream>
using namespace std;

// GFG : Print 1 to n without using loops

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