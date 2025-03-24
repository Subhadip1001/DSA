#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int str=0,end=s.size()-1;
    while(str < end){
        swap(s[str++], s[end--]);
    }
}

int main(){
    vector<char> str = {'h','e','l','l','o'};
    reverseString(str);
    cout << "Reversed String: ";
    for(auto i:str){
        cout << i << " ";
    }
    return 0;
}