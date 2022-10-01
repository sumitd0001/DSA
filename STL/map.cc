#include <bits/stdc++.h>
using namespace std;

int main () {

    map<int, string> m;

    m.insert({1, "Sumit"});
    m[2] = "Hello";

    for(auto itr = m.begin(); itr!=m.end(); ++itr) {
        cout << itr->first << " " << itr->second<<"\n";
    }
    auto itr2 = m.insert({1, "ABC"});
    cout<<(*(itr2.first)).first<<" "<<itr2.second<<"\n";

    for(auto itr = m.begin(); itr!=m.end(); ++itr) {
        cout << itr->first << " " << itr->second<<"\n";
    }

    m[2] = "World";
    for(auto itr = m.begin(); itr!=m.end(); ++itr) {
        cout << itr->first << " " << itr->second<<"\n";
    }
    
    //if a key-value or specifically a key is not present in map
    //and we try to access that key using operator [], then that will be inserted into map
    //with a default value for value of pair i.e., second element of pair

    cout<<"********Map2********\n";

    map<int , int> m2;

    m2.insert({});    

    for(auto itr = m2.begin(); itr!=m2.end(); ++itr) {
        cout << itr->first << " " << itr->second<<"\n";
    }

    cout<<"Size of Map2 : "<<m2.size()<<"\n";
    cout<<m2[1]<<"\n";
    cout<<"Size of Map2 : "<<m2.size()<<"\n";
    cout<<m2[1]<<"\n";

    m2[1] = 10;
    m2[2] = 20;
    m2[4] = 40;
    m2[3] = 30;

    auto i = m2.find(1);

    if(i!=m2.end()) cout<<"Found\n";
    else cout<<"Not Found\n";

    return 0;
}