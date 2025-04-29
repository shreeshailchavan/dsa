#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> v,vector<int>& processed,int index,vector<vector<int>>& ans){
    if(index >= v.size()){
        ans.push_back(processed);
        return;
    }

    processed.push_back(v[index]);
    helper(v,processed,index+1,ans);
    processed.pop_back();
    helper(v,processed,index+1,ans);
}

vector<vector<int>> subsequence(vector<int> v){
    vector<vector<int>> ans;
    vector<int> processed;
    int index = 0;
    helper(v,processed,index,ans);
    return ans;
}



int main(){
    vector<int> v = {3,1,2};
    vector<vector<int>> ans =  subsequence(v);

    for(auto& i:ans){
        cout<<"[";
        for(int nums:i){
            cout << nums << " ";
        }
           
        cout << "]"<<endl;
    }

    return 0;
}