#include <bits/stdc++.h>
using namespace std;

int main () {

    cout<<"pair <int, int>\n";
    pair <int,int> p1;
    cout<<"Default Values : "<<p1.first<<" "<<p1.second<<"\n";

    cout<<"pair <int, string>\n";
    pair <int, string> p2;
    cout<<"Default Values : "<<p2.first<<" "<<p2.second<<"\n";

    cout<<"pair <int, char>\n";
    pair <int, char> p3;
    cout<<"Default Values : "<<p2.first<<" "<<p3.second<<"\n";

    pair <int, int> p4{10, 10};
    pair <int, int> p5{20, 20};
    pair <int, int> p6{20, 10};
    pair <int, int> p7{30, 5};

    if (p1 == p4) cout<<"pair p1("<<p1.first<<", "<<p1.second<<") is equal to pair p4("<<p4.first<<", "<<p4.second<<")\n";
    else cout<<"pair p1("<<p1.first<<", "<<p1.second<<") is not equal to pair p4("<<p4.first<<", "<<p4.second<<")\n";

    if (p4 < p5) cout<<"pair p4("<<p4.first<<", "<<p4.second<<") is less than pair p5("<<p5.first<<", "<<p5.second<<")\n";
    else cout<<"pair p4("<<p4.first<<", "<<p4.second<<") is greater than or equal to pair p5("<<p5.first<<", "<<p5.second<<")\n";
    

    if (p4 < p6) cout<<"pair p4("<<p4.first<<", "<<p4.second<<") is less than pair p6("<<p6.first<<", "<<p6.second<<")\n";
    else cout<<"pair p4("<<p4.first<<", "<<p4.second<<") is greater than or equal to pair p6("<<p6.first<<", "<<p6.second<<")\n";

    if (p5 < p6) cout<<"pair p5("<<p5.first<<", "<<p5.second<<") is less than pair p6("<<p6.first<<", "<<p6.second<<")\n";
    else cout<<"pair p5("<<p5.first<<", "<<p5.second<<") is greater than or equal to pair p6("<<p6.first<<", "<<p6.second<<")\n";

    if (p6 < p5) cout<<"pair p6("<<p6.first<<", "<<p6.second<<") is less than pair p5("<<p5.first<<", "<<p5.second<<")\n";
    else cout<<"pair p6("<<p6.first<<", "<<p6.second<<") is greater than or equal to pair p5("<<p5.first<<", "<<p5.second<<")\n";


    if (p7 > p6) cout<<"pair p7("<<p7.first<<", "<<p7.second<<") is greater than pair p6("<<p6.first<<", "<<p6.second<<")\n";
    else cout<<"pair p7("<<p7.first<<", "<<p7.second<<") is less than or equal to pair p6("<<p6.first<<", "<<p6.second<<")\n";

    pair <int, int> p8;
    pair <int, int> p9{10, 15};
    p8 = p9;
    cout<<"p8 : "<<p8.first<<" "<<p8.second<<"\n";
    cout<<"p9 : "<<p9.first<<" "<<p9.second<<"\n";

    pair <int, int> p10;
    pair <int, int> p11{1, 2};
    p11.swap(p10);
    cout<<"pair p10(0, 0) swapped with pair p11(1,2)\n";
    cout<<"p10 : "<<p10.first<<" "<<p10.second<<"\n";
    cout<<"p11 : "<<p11.first<<" "<<p11.second<<"\n";

    pair p12 = make_pair(1, "Hello");
    cout<<"pair p12 using make_pair(1, Hello)\n";
    cout<<"p12 : "<<p12.first<<" "<<p12.second<<"\n";

    vector<pair<int, int>> vec{{1, 7}, {-1, 9}, {-1, 11}};
    cout<<"Ascending order : \n";
    sort(vec.begin(), vec.end());
    for(auto& var : vec) {
        cout<<var.first<<" "<<var.second<<"\n";
    }
    cout<<"Descending order : \n";
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    for(auto& var : vec) {
        cout<<var.first<<" "<<var.second<<"\n";
    }

    return 0;
}