#include <bits/stdc++.h>
using namespace std;

int main () {

    multiset <int> ms1;

    ms1.insert(10);
    ms1.insert(20);
    ms1.insert(10);
    ms1.insert(5);
    ms1.insert(20);
    ms1.insert(1);

    for(auto itr = ms1.begin(); itr!=ms1.end(); ++itr) {
        cout<<*itr<<" ";
    }cout<<"\n";

    cout<<ms1.erase(25)<<"\n";

    return 0;
}