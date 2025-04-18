#include<bits/stdc++.h>
using namespace std;


void radix_sort(vector<int>& arr){
    int exp = 1;
    int maxi = *max_element(arr.begin(),arr.end());
    vector<vector<int>> store(10);

    while(maxi/exp > 0){
        for(int item : arr){
            int radix_index = (item/exp) % 10;
            store[radix_index].push_back(item);
        }

        arr.clear();

        for(auto& bucket:store){
            for(int item:bucket){
                arr.push_back(item);
            }
            bucket.clear();
        }
        exp*=10;
    }
}
int main(){
    vector<int> v({170, 45, 75, 90, 802, 24, 2, 66});
    cout << "Array before sorting : "<<endl;
    for(int it:v)
        cout<<it<<" ";
    
    radix_sort(v);

    cout<<"\nArray after sorting : "<<endl;
    for(int it:v){
        cout<<it<<" ";
    }
    return 0;
}