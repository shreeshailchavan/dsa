#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> left,vector<int> right){
    int i=0,j=0,k=0;
    int m = left.size();
    int n = right.size();
    vector<int> merged(m+n);
    while(i < m && j<n){
        if(left[i] < right[j]){
            merged[k] = left[i];
            i++;
            k++;
        }
        else{
            merged[k] = right[j];
            j++;
            k++;
        }
    }

    while(i < m){
        merged[k] = left[i];
        i++;
        k++;
    }

    while(j < n){
        merged[k] = right[j];
        j++;
        k++;
    }

    return merged;
}


vector<int> merge_sort(vector<int> arr){
    if(arr.size() == 1)
        return arr;
    int mid = arr.size()/2;
    vector<int> left(arr.begin(),arr.begin()+mid);
    vector<int> right(arr.begin()+mid,arr.end());
    vector<int> leftsub = merge_sort(left);
    vector<int> rightsub = merge_sort(right);

    return merge(leftsub,rightsub);
}



int main(){
    vector<int> v({3, 7, 6, -10, 15, 25, 55, -13});
    vector<int> merged = merge_sort(v);
    for(auto& it:merged){
        cout<<it<<" ";
    }

    return 0;


}