#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int> v,int k,int index,int sum,vector<int>& pros,vector<vector<int>>& ans){

    if(index >= v.size()){
        if(sum == k){
            ans.push_back(pros);
            return true;
        }
        return false;
    }
    sum += v[index];
    pros.push_back(index);
    if(helper(v,k,index+1,sum,pros,ans)) return true;
    sum -= v[pros.back()];
    pros.pop_back();
    if(helper(v,k,index+1,sum,pros,ans)) return true;
    return false;

}
vector<vector<int>> subsequences(vector<int>v,int k){
    vector<int> pros;
    vector<vector<int>> ans;
    int sum = 0;
    helper(v,k,0,0,pros,ans);
    return ans;
}

int main(){
    vector<int> v = {1,2,1,1};
    vector<vector<int>> ans =  subsequences(v,3);

    for(auto& i:ans){
        cout<<"[";
        for(int nums:i){
            cout << nums << " ";
        }
           
        cout << "]"<<endl;
    }
    return 0;
}