#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,int> freq;
    vector<int> v({1,2,1,3,4,2,4,2,1,1,2,3});
    for(int i:v){
        ++freq[i];
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(auto& it:freq){
        maxi = max(it.second,maxi);
        mini = min(it.second,mini);
    }

    cout << "max freq->" << maxi <<" min freq->"<< mini << endl;
    return 0;
}