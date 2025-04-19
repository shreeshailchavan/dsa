#include<bits/stdc++.h>
using namespace std;



string reverse_string(string str,int i){
    if(i>=str.length()-1)
        return str;
    swap(str[i],str[str.length()-i-1]);
    
    return reverse_string(str,i+1);
}

bool check_pallindrome(string& s,int i){
    if(i>=s.length()-i-1)
        return true;
    if(s[i] != s[s.length()-i-1])
        return false;
    return check_pallindrome(s,i+1);

}


int main(){

    string s = "madam";
    cout  << check_pallindrome(s,0) << endl;
    return 0;

}