#include<bits/stdc++.h>
using namespace std;

int subcount(vector<int> v,int i,int sum,int k){
    if(i == v.size()){
        if(sum == k) return 1;
        else    return 0;
    }
    sum+=v[i];
    int left = subcount(v,i+1,sum,k);
    sum-=v[i];
    int right = subcount(v,i+1,sum,k);

    return left+right;
}

int main(){

    vector<int> v = {1,2,1};
    int sum = 0;
    int count = subcount(v,0,sum,2);
    cout << count << endl;
    return 0;
}