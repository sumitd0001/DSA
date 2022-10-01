#include <bits/stdc++.h>
using namespace std;

int main () {

    unordered_set <int> us1;

    auto itr1 = us1.insert(1);
    auto itr2 = us1.insert(1);

    cout<<*(itr1.first)<<" "<<itr1.second<<"\n";
    cout<<*(itr2.first)<<" "<<itr2.second<<"\n";
    
    unordered_set <int> us2;

    us1.swap(us2);

    return 0;
}