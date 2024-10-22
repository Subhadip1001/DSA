#include<iostream>
using namespace std;

int binExpo(int x, int n){
    long binForm = n;
    double ans = 1.0;

    if(x==0) return 0.0;
    if(x==1) return 1.0;
    if(n==0) return 1.0;
    if(x==-1 && n%2==0) return 1.0;
    if(x==-1 && n%2!=0) return -1.0;

    if(binForm < 0){
        x = 1/x;
        binForm = -binForm;
    }

    while(binForm > 0){
        if(binForm % 2 == 1){
            ans *= x;
        }
        x *= x;
        binForm /= 2;
    }
    return ans;
}

int main(){
    int x, n;
    cout << "Enter number : ";
    cin >> x;

    cout << "Enter power : ";
    cin >> n;

    double res = binExpo(x,n);
    cout << "Ans : " << res << endl;
    return 0;
}

// x^n
// power convert into binary form 
// if 1 then multiple 