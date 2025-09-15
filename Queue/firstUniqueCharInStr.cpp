#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

// LeetCode : 387
//  First Unique Character in a String

int uniqueChar(string s){
    unordered_map<char, int> um;
    queue<int> q;

    for(int i=0; i<s.size(); i++){
        if(um.find(s[i]) == um.end()){
            q.push(i);
        }

        um[s[i]]++;

        while(q.size() > 0 && um[s[q.front()]] > 1){
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front();
}

int main(){
    string s = "leetcode";
    cout << uniqueChar(s);
    return 0;
}