#include <bits/stdc++.h>
using namespace std;

void left_rotation(vector<int>& vec, int& n) {


}

int main () {

    vector<int> vec{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
                                                                  
    int n{5};

    cout<<"Before Rotation\n";

    for(auto& val : vec) {
        cout<<val<<" ";
    }cout<<"\n";

    left_rotation(vec, n);

    cout<<"After Rotation\n";

    for(auto& val : vec) {
        cout<<val<<" ";
    }cout<<"\n";

    return 0;
}