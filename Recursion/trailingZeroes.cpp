#include <iostream>
using namespace std;

// LeetCode : 172
// Factorial Trailing Zeroes

class solution{
    public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n > 0){
            n /= 5;
            count += n;
        }

        return count;
    }
};

int main() {
    int n = 13;
    solution s;
    cout << s.trailingZeroes(n) << endl;
    return 0;
}