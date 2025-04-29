#include<bits/stdc++.h>
using namespace std;


void func(int i,int n,int& sum){
    if(i > n){
        cout << sum << endl;
        return;
    }
    sum += i;
    func(i+1,n,sum);
}


// using recurrence relation

int summation(int n){
   if(n == 0)
    return 0;
    return n+summation(n-1);
}
int main(){
    int sum = 0;
    int n = 5;
    func(0,n,sum);
    cout << summation(5) << endl;
    return 0;
}