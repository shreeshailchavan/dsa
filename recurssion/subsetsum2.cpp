#include<bits/stdc++.h>
using namespace std;

// with using set
void helper(vector<int> nums,int n,int i,vector<int>& ds,set<vector<int>>& ans){
    if(i == n){
        ans.insert(ds);
        return;
    }
    ds.push_back(nums[i]);
    helper(nums,n,i+1,ds,ans);
    ds.pop_back();
    helper(nums,n,i+1,ds,ans);
}

// without using set
void helper_without_set(vector<int> nums,int n,int i,vector<int>& ds,vector<vector<int>>& ans){
    if(i == n){
        if(!ans.empty()){
            if(ans.back() != ds){
                ans.push_back(ds);
            }
        }
        else{
            ans.push_back(ds);
        }
        return;
    }

    ds.push_back(nums[i]);
    helper_without_set(nums,n,i+1,ds,ans);
    ds.pop_back();
    helper_without_set(nums,n,i+1,ds,ans);
}

// optimal way 
void optimal_helper(vector<int> nums,int n,int i,vector<int>& ds,vector<vector<int>>& ans){
    
    ans.push_back(ds);

    for(int ind = i;ind < n;ind++){
        if(nums[ind] == nums[ind-1] && ind > i) continue;
        ds.push_back(nums[ind]);
        optimal_helper(nums,n,ind+1,ds,ans);
        ds.pop_back();
    }
}

vector<vector<int>> subset(vector<int> nums,int n){

    // set<vector<int>> ans;
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> ds;
    // helper(nums,n,0,ds,ans);
    // helper_without_set(nums,n,0,ds,res);
    // vector<vector<int>> res(ans.begin(),ans.end());
    optimal_helper(nums,n,0,ds,res);
    return res;
}

int main(){
    vector<int> nums = {1,2,2};
    int n = 3;
    vector<vector<int>> result = subset(nums,n);
    for(auto it:result){
        cout <<"[";
        for(int i:it){
            cout <<" "<<i ;
        }
        cout << "]"<<endl;
    }
    return 0;
}