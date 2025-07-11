#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// LeetCode: 151
// Reverse Words in a String

string reverseWords(string s){
    int n = s.length();
    string result = " ";

    reverse(s.begin(), s.end());

    for(int i=0; i<n; i++){
        string word = "";
        while (i < n && s[i] != ' '){
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if(word.length() > 0){
            result += " " + word;
        }
        
    }
    return result.substr(1);
}

int main(){
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;
    return 0;
}
