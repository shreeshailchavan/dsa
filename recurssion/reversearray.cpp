#include<bits/stdc++.h>
using namespace std;

void reverse_array(vector<int>& arr,int i){
    if(i>=arr.size()-i-1)
        return;
    swap(arr[i],arr[arr.size()-i-1]);
    reverse_array(arr,i+1);
}

int main(){
    vector<int> v = {1,2,3,4,5,6};
    for(int i:v)
        cout<<i << " ";
    
    reverse_array(v,0);
    cout<<"After reverse : "<<endl;
    for(int i:v)
        cout<<i << " ";
    return 0;
}