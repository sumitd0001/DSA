#include <bits/stdc++.h>
using namespace std;

string Sorted_Characters(string str)
{
    set<char> s;
    int len = str.length();
    for(int x=0; x<len; ++x) {
        cout<<str[x]<<" ";
        s.insert(str[x]);
    }cout<<"\n";
    
    string str2;
    int i{0};
    
    for(auto x : s) {
        str2+=x;
    }
    
    return str2;
}

int main () {

    cout<<Sorted_Characters("adbcdcd");
    return 0;
}