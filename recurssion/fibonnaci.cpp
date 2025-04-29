#include<bits/stdc++.h>
using namespace std;

long long fibonnaci(int n){
    if(n == 1 || n == 0)
        return n;
    long long last = fibonnaci(n-1);
    long long secondLast = fibonnaci(n-2);
    return last + secondLast;
   
}

int main(){
    long long ans = fibonnaci(4);
    cout << ans ; 
    return 0;
}