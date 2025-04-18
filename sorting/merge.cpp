#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& arr,int left,int right){
    if(left<=right){
        int mid = (left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);

        
    }
}

int main(){
    vector<int> v({3, 7, 6, -10, 15, 25, 55, -13});


}