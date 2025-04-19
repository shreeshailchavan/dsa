#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int>& nums){
    int maxi = *max_element(nums.begin(),nums.end());
    vector<int> count(maxi+1);
    for(int i:nums)
        ++count[i];
    
    nums.clear();

    for(int i=0;i<count.size();i++){
        while(count[i]!=0){
            nums.push_back(i);
           --count[i];
        }
    }
    
}

int main(){
    vector<int> nums = {0,3,1,3,4,2,1,2};
    count_sort(nums);
    for(int i:nums)
        cout<<i<<" ";
    return 0;

}