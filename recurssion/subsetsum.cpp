#include<bits/stdc++.h>
using namespace std;

// applying the pick and non pick
void helper(vector<int> nums,int index,int sum,vector<int>& ans){
    // 
    if(index == nums.size()){
        ans.push_back(sum);
        return;
    }

    helper(nums,index+1,sum+nums[index],ans);
    helper(nums,index+1,sum,ans);

}

// sum of all the subsets of array subset -> 2^n;
vector<int> subsetsum(vector<int> nums){
    vector<int> res;
    int sum = 0;
    helper(nums,0,sum,res);
    sort(res.begin(),res.end());
    return res;
}



int main(){
    vector<int> nums = {3,1,2};
    vector<int> result = subsetsum(nums);
    for(auto it:result){
        cout <<"{"<<it <<"} ";
    }
    return 0;
}