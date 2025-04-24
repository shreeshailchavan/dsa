#include<bits/stdc++.h>
using namespace std;

// interpolation search is much more similar to binary search in respec of T.C -> O(logn) but the key difference is that the interpolation search checks for the surrodunding element unlike for mid element like binary serch but the requirement for interpolation search all the elements in the arrray should be uniformly distributed

// forumual => pos = low + (((target - arr[low]) * (high - low)) / (arr[high] - arr[low]));

int interpolation_search(vector<int> &arr,int val){
    int n = arr.size();
    int low = 0,high = n-1;
    while(low<high){
        int pos = low+(((val-arr[low]) * (high-low))/ (arr[high] - arr[low]));
        if(arr[pos] == val)
            return pos;
        else if(arr[pos] > val)
            high=pos-1;
        else
            low = pos+1;
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int pos = interpolation_search(arr,2);
    cout << pos <<endl;
    return 0;
}