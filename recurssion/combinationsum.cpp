#include<bits/stdc++.h>
using namespace std;



void helper(vector<int> nums,int target,vector<int>& ds,vector<vector<int>>& ans,int i){
    if(i == nums.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    if(nums[i] <= target){
        ds.push_back(nums[i]);
        helper(nums,target-nums[i],ds,ans,i);
        ds.pop_back();
    }
   
    helper(nums,target,ds,ans,i+1);

}

vector<vector<int>> combinationsum(vector<int> nums,int target){
    //for all subsequences
    vector<vector<int>> ans;
    //for pick | non-pick
    vector<int> ds;
    helper(nums,target,ds,ans,0);
    return ans;
}
int main(){
    vector<int> nums = {2,3,6,7};
    vector<vector<int>> res = combinationsum(nums,7);
    for(auto it:res){
        cout << "[";
        for(int num:it)
            cout << num << " ";
        cout << "]"<<endl;
    }
    return 0;
}