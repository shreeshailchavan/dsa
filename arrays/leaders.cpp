#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& nums){
    int n = nums.size();
    int maxi = INT_MIN;
    vector<int> result;
    for(int i=n-1;i>=0;i--){
        if(nums[i] >= maxi)
            result.push_back(nums[i]);
        
        maxi = max(nums[i],maxi);
    }

    reverse(result.begin(),result.end());
    return result;
}

int main(){

    vector<int> nums = {228,1,3,4,23,89,30};
    vector<int> result = leaders(nums);
    for(auto& it:result){
        cout<<it<<" ";
    }

    return 0;
}