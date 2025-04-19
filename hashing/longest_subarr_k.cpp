#include<bits/stdc++.h>
using namespace std;


int longest_subarray(vector<int>& arr,int k){

    int n = arr.size();
    int sum = 0;
    int longest = 0;

    // better approach -> works as optimal approach if tha array has =ve and -ve nums
    // unordered_map<int,int> umap;
    // for(int i=0;i<n;i++){

    //     sum+=arr[i];

    //     if(sum == k)
    //         longest = max(longest,i+1);

    //     if(umap.find(sum-k) != umap.end()){
    //             longest = max(i-umap[sum-k],longest);
    //         }

    //     if(umap.find(sum) == umap.end())
    //         umap[sum] = i;
    // }
    // return longest;

    // optimal solution
    int i=0,j=0;
    sum = arr[0];
    while(j < n){
        while(i<= j && sum > k){
            sum-=arr[i];
            i++;
        }
        if(sum == k)
            longest = max(longest,j-i+1);
        sum+=arr[j];
        j++;
    }
    return longest;

}


int main(){
    vector<int> v = {1,2,4,1,1,1,3,4,0,0,0,1,1,1};
    cout << longest_subarray(v,3) << endl;
    return 0;
}