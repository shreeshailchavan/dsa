#include<bits/stdc++.h>
using namespace std;

void permutations(vector<int> nums,vector<int>& processed,int freq[]){
    if(processed.size() == nums.size()){
        for(auto it:processed){
            cout << it <<" ";
        }
        cout <<endl;
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!freq[i]){
        processed.push_back(nums[i]);
        freq[i] = 1;
        permutations(nums,processed,freq);
        freq[i] = 0;
        processed.pop_back();
        }
        
        
    }
}
int main(){
    vector<int> processed;
    int freq[3] = {0};
    permutations({1,2,3},processed,freq);
    return 0;
}