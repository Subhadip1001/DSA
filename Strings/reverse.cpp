#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    cout << "Enter your string : " << endl;
    getline(cin, str);

    // Reverse the string
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}