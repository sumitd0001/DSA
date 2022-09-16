#include <bits/stdc++.h>
using namespace std;

int changeInconstructible(vector<int>& coins) {
    sort (coins.begin(), coins.end());

    int change = 0;
    for(auto& coin : coins) {
        if(coin > change+1) return change+1;
        change+=coin;
    }
    return change+1;
}

int main () {

    vector<int> coins {5, 7, 1, 1, 2, 3, 22};

    cout<<changeInconstructible(coins);

    return 0;
}