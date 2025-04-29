#include<bits/stdc++.h>
using namespace std;


void helper(vector<int> nums,int target,int i,vector<int>& ds,set<vector<int>> &ans){
    if(target == 0){
        ans.insert(ds);
        return;
    }

    for(int ind=i;ind<nums.size();ind++){
        if(nums[ind] == nums[ind-1] && ind > i) continue;
        if(nums[ind] > target) break;
        ds.push_back(nums[ind]);
        helper(nums,target-nums[ind],ind+1,ds,ans);
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