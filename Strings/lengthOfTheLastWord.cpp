#include<iostream>
#include<string>
using namespace std;

// LeetCode : 58
// Length of Last Word

int lengthOfLastWord(string s){
    int n = s.size();
    int count = 0;

    for(int i=n-1; i>=0; i--){
        if(count==0 && s[i]==' '){
            continue;
        }else if(s[i] != ' '){
            count++;
        }else{
            break;
        }
    }

    return count;
}

int main(){
    string s = "   fly me   to   the moon  ";
    cout << "Length of Last Word : " << lengthOfLastWord(s) << endl;
    return 0;
}