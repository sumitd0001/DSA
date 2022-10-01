#include <bits/stdc++.h>
using namespace std;

int main () {

    string str = "Hello";
    int i = 6;
    unordered_map<string, vector<int>> m;
    
    m.insert ({"Hello", {1,2,3,4}});
    
    auto& vec = m[str];

    for(auto x : vec) {
        cout<<x<<" ";
    }cout<<"\n";

    bool val = find(vec.begin(), vec.end(), 4) != vec.end();

    cout<<val<<"\n";

    if(2!=1 && !val) {
        vec.push_back(i);
        i++;
    }

    for(auto var : m) {
        for(auto vec : var.second) {
            cout<<vec<<" \n";
        }
    }
    cout<<m["World"].size()<<"\n";
    if(m.find("Sumit") != m.end()) {
        if(find(m["Sumit"].begin(), m["Sumit"].end(), 3) == m["Sumit"].end()) {
            cout<<"Not Found\n";
        }
    }

    for(auto var : m) {
        cout<<var.first<<" ";
    }

    return 0;
}