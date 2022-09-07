#include <bits/stdc++.h>
using namespace std;

int maxsubarraysum_kadanes_algo(vector<int>& vec){
    int max_sum = INT_MIN;
    int sum = 0;

    for(int i = 0; i<vec.size(); ++i) {
        sum += vec[i];
        if(sum > max_sum) {
            max_sum = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return max_sum;
}

int main () {

    vector<int> vec1{5,6,0,4,-1,4,7,2};
    vector<int> vec2{4,-4,6,-6,10,-11,12};
    vector<int> vec3{3,4,1,0,-2,-6,8,3};
    vector<int> vec4{-3,-4,-1,-10,-2,-6,-8,-3};

    cout<<maxsubarraysum_kadanes_algo(vec1)<<endl;
    cout<<maxsubarraysum_kadanes_algo(vec2)<<endl;
    cout<<maxsubarraysum_kadanes_algo(vec3)<<endl;
    cout<<maxsubarraysum_kadanes_algo(vec4)<<endl;

    return 0;
}