#include<bits/stdc++.h>
using namespace std;

void next_perm(vector<int>& v){
    int n = v.size();
    int ind = -1;
    // find the pivot that is the element from last where v[i} < v[i+1]
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            ind = i;
            break;
        }
    }

    // in case we dont find v[i] < v[i+1] then we have already the largest permutation that is array in descending order so reverse and return 
    if(ind == -1){
        reverse(v.begin(),v.end());
        return;
    }

    // no we have to find element greater than v[i] but the smallest one from the ending once we get it just swap them and break;
    for(int i=n-1;i>ind;i--){
        if(v[i]>v[ind]){
            swap(v[i],v[ind]);
            break;
        }
    }

    // now reverse the remaing part of the array from ind+1 to end
    reverse(v.begin()+ind+1,v.end());

}

int main(){
    vector<int> v = {1,2,3,4};
    next_perm(v);
    cout << "nexr perm : ";
    for(int i:v)
        cout<<i<<" ";
        
    return 0;
}