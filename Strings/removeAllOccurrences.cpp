#include<iostream>
using namespace std;

// LeetCode: 1910
// Remove All Occurrences of a Substring

string removeOccurrences(string s, string part){
    while(s.length() > 0 && s.find(part) <= s.length()){
        s.erase(s.find(part), part.length());
    }

    return s;
}

int main(){
    string str = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(str, part) << endl;
    return 0;
}