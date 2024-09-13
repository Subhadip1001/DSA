#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vec = {1,2,3};

    //push_back
    vec.push_back(23);
    vec.push_back(13);
    vec.push_back(11);

    // pop_back
    vec.pop_back();

    // front
    cout << "Front value : " << vec.front() << endl;

    // back
    cout << "Back value : " << vec.back() << endl;

    // at
    cout << "at(index) : " << vec.at(2) << endl;

    // for each loop
    for(int val: vec){
        cout << val <<endl;
    }

    cout << "size is : " << vec.size() << endl;
    return 0;
}