#include<iostream>
#include<stack>
using namespace std;

// LeetCode: 20
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

bool isVaild(string s){
    stack<char> stk;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stk.push(s[i]);
        }else{
            if(stk.empty()){
                return false;
            }

            if((stk.top() == '(' && s[i] == ')') || (stk.top() == '{' && s[i] == '}') || (stk.top() == '[' && s[i] == ']')){
                stk.pop();
            }else{
                return false;
            }
        }
    }

    return stk.size() == 0;
}

int main(){
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if(isVaild(s)){
        cout << "The string is valid." << endl;
    }else{
        cout << "The string is not valid." << endl;
    }
    return 0;
}