#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

// LeetCode: 443
// String Compression

int compress(vector<char>& chars){
    int n = chars.size();
    int idx = 0;

    for(int i=0; i<n; i++){
        char ch = chars[i];
        int count = 0;

        while(i < n && chars[i] == ch){
            count++; i++;
        }

        if(count == 1){
            chars[idx++] = ch;
        }else{
            chars[idx++] = ch;
            string countStr = to_string(count);
            for(char c : countStr){
                chars[idx++] = c;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}

int main(){
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);
    cout << "Compressed length: " << newLength << endl;
    return 0;
}