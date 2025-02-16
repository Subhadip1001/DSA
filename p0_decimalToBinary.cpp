#include <iostream>
using namespace std;


int decimalToBinary(int decNum){
    int ans = 0, pow = 1;
    
    while (decNum > 0){
        int rem = decNum % 2;
        decNum = decNum / 2;
        ans += (rem * pow);
        pow *= 10;
    }
    return ans;
}

int binaryToDecimal(int biNum){
    int ans = 0;
    int pow = 1;
    while (biNum > 0){
        int rem = biNum % 10;
        biNum = biNum / 10;
        ans += (rem * pow);
        pow *= 2;
    }
    return ans;
}

int main(){
    int decNum, biNum;
    int choice;
    cout << "Enter 1 for Decimal to Binary conversion and 2 for Binary to Decimal conversion: ";
    cin >> choice;

    if(choice == 1){
        cout << "Enter a decimal number: ";
        cin >> decNum;
        cout << "Binary form of " << decNum << " is " << decimalToBinary(decNum) << endl;
    }
    else if(choice == 2){
        cout << "Enter a binary number: ";
        cin >> biNum;
        cout << "Decimal form of " << biNum << " is " << binaryToDecimal(biNum) << endl;
    }
    else{
        cout << "Invalid choice" << endl;
    }
    return 0;
}