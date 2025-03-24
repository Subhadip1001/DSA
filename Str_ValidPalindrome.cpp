#include<iostream>
#include<cctype>
using namespace std;

bool isPalindrome(string s){
    int st=0,end=s.length()-1;
    while(st < end){
        if(!isalnum(s[st])){
            st++; continue;
        }
        if(!isalnum(s[end])){
            end--; continue;
        }
        if(tolower(s[st]) != tolower(s[end])){
            return false;
        }

        st++; end--;
    }
    return true;
}

int main(){
    string str = "A5f?3@f5a";
    cout << isPalindrome(str) << endl;
    return 0;
}