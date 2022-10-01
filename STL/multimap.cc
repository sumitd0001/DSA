#include <bits/stdc++.h>
using namespace std;

int main () {

    cout<<"multimap m\n";
    multimap <int, int> m;

    m.insert({3, 30});
    m.insert({2, 20});
    m.insert({2, 5});
    m.insert({1, 10});

    for(auto& var : m) {
        cout<<var.first<<" "<<var.second<<"\n";
    }
    cout<<"multimap m2\n";
    multimap <int, int> m2;

    m2.insert({3, 30});
    m2.insert({2, 5});
    m2.insert({2, 20});
    m2.insert({1, 10});
    for(auto& var : m2) {
        cout<<var.first<<" "<<var.second<<"\n";
    }

    return 0;
}