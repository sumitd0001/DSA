#include <bits/stdc++.h>
using namespace std;

void combinations (string& str, int i, int pos, int end, string& temp) {

    if(pos == end) return;

    if(pos < end) {
        for(int j = pos; j<=i; ++j) {
            cout<<temp[j];
        }
    }
    temp[pos] = str[i];
    combinations(str, i+1, pos+1, end, temp);
    combinations(str, i, pos+1, end, temp);
}

int main () {

    string str{"abcdef"};
    string temp{""};

    combinations(str, 0, 0, str.length()-1, temp);

    return 0;
}