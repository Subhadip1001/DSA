#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// LeetCode: 131
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

bool isPalindrome(string s){
    string s2 = s;
    reverse(s2.begin(), s2.end());

    return s == s2;
}

void getAllPartitions(string s, vector<string>& partitions, vector<vector<string>>& ans){
    if(s.size() == 0){
        ans.push_back(partitions);
        return;
    }

    for(int i=0; i<s.size(); i++){
        string part = s.substr(0, i + 1);

        if(isPalindrome(part)){
            partitions.push_back(part);
            getAllPartitions(s.substr(i + 1), partitions, ans);
            partitions.pop_back();
        }
    }
}

vector<vector<string>> prtition(string s){
    vector<vector<string>> ans;
    vector<string> partitions;

    getAllPartitions(s, partitions, ans);
    return ans;
}

int main(){
    string s = "aab";
    vector<vector<string>> ans = prtition(s);
    for(const auto& vec : ans){
        cout << "[ ";
        for(const string& str : vec){
            cout << "'" << str << "'" << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}