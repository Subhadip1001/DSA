#include<iostream>
using namespace std;

// LeetCode: 125
// Valid Palindrome

bool isAlphaNum(char ch){
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
    }
    return false;
}

bool isPalindrome(string str){
    int s = 0, e = str.length()-1;

    while (s<e){

        // if(!isalnum(str[s])){ s++; continue;}
        // if(!isalnum(str[e])){ e--; continue;}

        if(!isAlphaNum(str[s])){ s++; continue;}
        if(!isAlphaNum(str[e])){ e--; continue;}

        if(tolower(str[s]) != tolower(str[e])){
            return false;
        }

        s++; e--;
    }
    return true;
}

int main(){
    string str = "Ac3?e3c&a";
    // string str = "av{45uu";
    bool ans = isPalindrome(str);
    cout << ans << endl;
    
    return 0;
}