#include <bits/stdc++.h>
using namespace std;
/*
Question  :
Needs to find the elment which occurs thrice
*/
int main () {
    int size{0};
    cout<<"Enter the size of the array : \n";
    cin>>size;
    int* arr = new int[size];
    map <int, int> m;
    cout<<"Enter "<<size<<" elements\n";
    for(int i = 0; i<size; ++i) {
        cin>>arr[i];
        m[arr[i]]++; // int values in the maps are initialized with 0
    }
    int count{0};
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        if(itr->second == 3) {
            count++;
            cout<<itr->first<<" occurs thrice in the array"<<endl;
        }
    }
    if(!count)
    cout<<"No element frequency is 3 in the array"<<endl;
    return 0;
}