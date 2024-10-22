#include<iostream>
using namespace std;

int maxWaterContainer(int height[], int s){
    int lp = 0, rp = s-1;
    int maxWater = 0;
    while(lp < rp){
        int w = rp - lp;
        int h = min(height[lp], height[rp]);
        int currWater = w * h;
        maxWater = max(maxWater, currWater);

        height[lp] < height[rp] ? lp++ : rp--;  
    }
    return maxWater;
}

int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int height[n];
    cout << "Enter heights : ";
    for(int i=0; i<n; i++){
        cin >> height[i];
    }
    int maxWater = maxWaterContainer(height, n);
    cout << "Maximum amount of water a container can storev: " << maxWater << endl;
    return 0;
}