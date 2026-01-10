#include<iostream>
#include<string>
#include<vector>
using namespace std;

// LeetCode : 28;
// Find the Index of the First Occurrence in a String

class Solution{
    public:
    vector<int> buildLps(string needle){
        int n = needle.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;

        while(i < n){
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle){
        int m = needle.size(), n = haystack.size();
        if(n < m) return -1;

        vector<int> lps = buildLps(needle);
        int i = 0, j = 0;

        while(i<n){
            if(haystack[i] == needle[j]){
                i++; j++;
            }

            if(j==m){
                return i-j;
            }else if(i<n && haystack[i] != needle[j]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
};

int main(){
    // string haystack = "sadbutsad", needle = "sad";
    // string haystack = "leetcode", needle = "leeto";
    string haystack = "aabcbade", needle = "ade";
    Solution s;
    int ans = s.strStr(haystack, needle);
    cout << ans << endl;
    return 0;
}