#include<bits/stdc++.h>
#include<iostream>
// #include<vector>
using namespace std;

// the lower bound variation of binary search is to find the smallest index which has element  >= the target
// the array needs to be sorted
// the time complexity is O(logn)

// int lower_bound(vector<int>& v,int target){
//     int n = v.size();
//     int res = -1;
//     // take out the mid first
//     int l = 0 , h = n-1;
//     int mid = (l+h)/2;
//     while(l<=h){
//         if(v[mid] >= target){
//             res = mid;
//             h = mid-1;
//         }
//         else{
//             l = mid+1;
//         }
//         mid = (l+h)/2;
//     }

//     return res;
// }

// we also have a cpp stl algorithm for lowerbound
int main(){
    vector<int> v = {1,3,4,5,6,7,8,9,10};
    int target = 2;
    // int res = lower_bound(v,target);
    // cpp stl
    int res = lower_bound(v.begin(),v.end(),target) - v.begin();
    cout << res << endl;
    return 0;
}