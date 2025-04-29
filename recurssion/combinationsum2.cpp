#include<bits/stdc++.h>
using namespace std;


void helper(vector<int> nums,int target,int i,vector<int>& ds,set<vector<int>> &ans){
    // if  target is 0 insert into ans
    if(target == 0){
        ans.insert(ds);
        return;
    }
    // for each index from i to n perform recurssive call
    for(int ind=i;ind<nums.size();ind++){
        // if i == i+1 that is duplicate num dont perform the recurssion call
        if(nums[ind] == nums[ind-1] && ind > i) continue;
        // if nums[ind] > target that means there is not point in taking this element and other next elements so break
        if(nums[ind] > target) break;
        // otherwise add the element and performthe recurssion from i+1
        ds.push_back(nums[ind]);
        helper(nums,target-nums[ind],ind+1,ds,ans);
        // remove the added element as a part of non pick and right recurrssive call
        ds.pop_back();
    }
}

vector<vector<int>> combsum2(vector<int> nums,int target){
    sort(nums.begin(),nums.end());
    set<vector<int>> ans;
    vector<int> ds;
    helper(nums,target,0,ds,ans);
    vector<vector<int>> res(ans.begin(),ans.end());
    return res;
}
int main(){
    vector<vector<int>> res = combsum2({2,2,3,6,7},7);
    for(auto it:res){
        cout <<"[";
        for(int i:it){
            cout << i << " ";
        }
        cout << "]"<<endl;
    }
    return 0;

}