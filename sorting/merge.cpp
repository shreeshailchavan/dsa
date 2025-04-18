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


// inplace merge sort

void inplace_merge(vector<int>& arr,int left,int mid,int right){
    int low = left;
    int high = mid+1;
    vector<int> temp;

    while(low <= mid && high <= right){
        if(arr[low] < arr[high]){
            temp.push_back(arr[low]);
            low++;
        }
        else{
            temp.push_back(arr[high]);
            high++;
        }
    }

    while(low <= mid){
        temp.push_back(arr[low]);
        low++;
    }

    while(high <= right){
        temp.push_back(arr[high]);
        high++;
    }

    for(int i=left;i<=right;i++){
        arr[i] = temp[i-left];
    }
}

void inplace_merge_sort(vector<int>& v,int left,int right){
    if(left>=right)
        return;
    int mid = (left+right)/2;
    inplace_merge_sort(v,left,mid);
    inplace_merge_sort(v,mid+1,right);

    inplace_merge(v,left,mid,right);
}



int main(){
    vector<int> v({3, 7, 6, -10, 15, 25, 55, -13});
    // vector<int> merged = merge_sort(v);
    inplace_merge_sort(v,0,v.size()-1);
    for(auto& it:v){
        cout<<it<<" ";
    }

    return 0;


}