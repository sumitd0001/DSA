#include <bits/stdc++.h>
using namespace std;

int main () {

    vector<int> vec {1, 2, 3, 4, 5};

    cout<<*(vec.begin())<<"\n";
    cout<<*(vec.begin()+4)<<"\n";
    cout<<distance(vec.begin(), vec.begin()+4)<<"\n";
    cout<<distance(vec.begin()+4, vec.begin())<<"\n";

    return 0;
}