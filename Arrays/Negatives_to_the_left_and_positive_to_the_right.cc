#include <bits/stdc++.h>
using namespace std;
/*
i-->
j-->
-1, 2, -3, 4, 5, 6, -7, 8, 9
*/
void shiftnegative1(vector<int>& vec) {
    int i{0}, j{0};
    int size = vec.size();
    for(;i<size;++i) {
        if(vec[i] < 0) {
            swap(vec[i], vec[j]);
            ++j;
        }
    }
}
/*
i-->                    <--j
-1, 2, -3, 4, 5, 6, -7, 8, 9
*/
//2 pointer approach
void shiftnegative2(vector<int>& vec) {
    int size = vec.size()-1;
    int i{0}, j{size};
    while(i < j) {
        if(vec[i] < 0 && vec[j] < 0) {
            ++i;
        }
        else if(vec[i] < 0 && vec[j] > 0) {
            ++i;
            --j;
        }
        else if (vec[i] > 0 && vec[j] < 0) {
            swap(vec[i],vec[j]);
            ++i;
            --j;
        }
        else {
            --j;
        }
    }
}

int main () {

    vector<int> vec{-1, 2, -3, 4, 5, 6, -7, 8, 9};
    //shiftnegative1(vec);
    shiftnegative2(vec);

    for(auto x : vec) {
        cout<<x<<" ";
    }cout<<"\n";

    return 0;
}