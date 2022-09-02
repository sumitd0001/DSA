#include <bits/stdc++.h>
using namespace std;

/*
vector<int> two_number_sum (vector<int> vec, int TargetSum) {

    vector<int> ts;

    for(auto itr = vec.begin(); itr!=vec.end(); ++itr) {
        for(auto itr2 = itr+1; itr2!=vec.end(); ++itr2) {
            if((*itr + *itr2) == TargetSum) {
                ts.push_back(*itr);
                ts.push_back(*itr2);
                return ts;
            }
        }
    }
    return ts;
}
*/

/*
vector<int> two_number_sum (vector<int> vec, int TargetSum) {
    unordered_map <int, int> map;
    vector<int> ts;
    for(auto x : vec) {
        auto itr = map.find(x);
        if(itr!=map.end()) {
            ts.push_back(itr->first);
            ts.push_back(itr->second);
            return ts;
        }
        map[TargetSum-x] = x;
    }
    return ts;
}
*/

/*
vector<int> two_number_sum (vector<int> vec, int TargetSum) {
    unordered_map <int, bool> map;
    vector<int> ts;
    for(auto x : vec) {
        auto itr = map.find(TargetSum-x);
        if(itr!=map.end()) {
            ts.push_back(x);
            ts.push_back(TargetSum-x);
            return ts;
        }
        map[x] = true;
    }
    return ts;
}
*/
/*
vector<int> two_number_sum (vector<int> vec, int TargetSum) {
    sort(vec.begin(), vec.end());

    vector<int> ts;
    auto itr = vec.begin();
    auto itr2 = vec.end()-1;

    while(itr < itr2) {
        if((*itr + *itr2) == TargetSum) {
            ts.push_back(*itr);
            ts.push_back(*itr2);
            return ts;
        }
        else if ((*itr + *itr2) < TargetSum) {
            ++itr;
        }
        else if ((*itr + *itr2) > TargetSum) {
            --itr2;
        }
    }
    return ts;
}
*/

vector<int> two_number_sum (vector<int> array, int targetSum) { 
    unordered_map <int, bool> map;
    for(auto& x : array) {
        if(auto itr = map.find(targetSum-x); itr!=map.end()) {
            return {x, targetSum-x};
        }
        map[x]=true;
    }
    return {};
}

int main () {

    vector<int> vec;
    int TargetSum = 10;

    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(-4);
    vec.push_back(8);
    vec.push_back(11);
    vec.push_back(1);
    vec.push_back(-1);
    vec.push_back(6);

    vector<int> ts = two_number_sum(vec, TargetSum);
    cout<<"Target Sum : "<<TargetSum<<"\n";
    for(auto x : ts) {
        cout<<x<<" ";
    }
    return 0;
}