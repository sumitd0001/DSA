#include <bits/stdc++.h>
using namespace std;

int main () {

    set<int> s1;

    s1.insert(5);
    s1.insert(4);
    s1.insert(3);
    s1.insert(2);
    s1.insert(1);

    for(auto& var : s1) {
        cout<<var<<" ";
    }cout<<"\n";

    cout<<"lower_bound"<<"\n";
    auto itrl = s1.lower_bound(1);
    if(itrl!=s1.end()) {
        cout<<*itrl<<"\n";
    }cout<<"\n";

    set<int, less<int>> s2;
    s2.insert(5);
    s2.insert(4);
    s2.insert(3);
    s2.insert(2);
    s2.insert(1);

    for(auto& var : s2) {
        cout<<var<<" ";
    }cout<<"\n";

    set<int, greater<int>> s3;
    s3.insert(1);
    s3.insert(2);
    s3.insert(3);
    s3.insert(4);
    s3.insert(5);

    for(auto& var : s3) {
        cout<<var<<" ";
    }cout<<"\n";

    auto itr = s3.find(4);
    cout<<*itr<<"\n";

    auto itr2 = s3.find(10);
    if(itr2 != s3.end())
    cout<<*itr2<<"\n";

    if(find(s3.begin(), s3.end(), 4) != s3.end()) cout<<4<<" Found\n";
    

    //cout<<distance(itr, s3.begin())<<"\n";

    cout<<s3.size()<<"\n";
    cout<<s3.max_size()<<"\n";

    return 0;
}