#include<bits/stdc++.h>
using namespace std;

// the upper bound is a variation of binary search in which we find the immediate greater element index than the target
// the array needs to be sorted
// Time complexity is O(logn)

int upper_bound(vector<int>& v,int target){
    int n = v.size();
    int l = 0;
    int h = n-1;
    int ans = -1;
    int mid = (l+h)/2;
    while(l<=h){
        if(v[mid] > target){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
        mid = (l+h)/2;
    }

    return ans;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,7,10};
    cout << upper_bound(v,9) << endl;
    // cpp stl gives the upper_bound function for finding the upper_bound
    cout << upper_bound(v.begin(),v.end(),9) - v.begin() << endl;

    return 0;
}