#include <bits/stdc++.h>
using namespace std;



int main () {

    int t{0};
    int n{0};
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> vec(n, 0);
        int max = 0;
        int color = 0;
        for(int i = 0; i<n; ++i) {
            cin>>vec[i];
            if(vec[i] >= max) {
                max = vec[i];
                color = i+1;
            }
        }
        cout<<color<<"\n";
    }
    return 0;
}