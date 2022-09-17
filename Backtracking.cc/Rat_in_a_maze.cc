//Needs to work on the below solution which wrong

#include<bits/stdc++.h>
using namespace std;

bool rat_in_a_maze(int arr[][4], int R, int C, int sr, int sc, int er, int ec) {
    if(sr == er && sc ==ec) {
        return true;
    }

    if((sr-1) >= 0 && arr[sr-1][sc]==1) {
        cout<<"sr : "<<sr<<" sc : "<<sc<<"\n";
        return rat_in_a_maze(arr, R, C, sr-1, sc, er, ec);
    }
    if((sr+1) < R && arr[sr+1][sc]==1) {
        cout<<"sr : "<<sr<<" sc : "<<sc<<"\n";
        return rat_in_a_maze(arr, R, C, sr+1, sc, er, ec);
    }
    if((sc-1) >= 0 && arr[sr][sc-1]==1) {
        cout<<"sr : "<<sr<<" sc : "<<sc<<"\n";
        return rat_in_a_maze(arr, R, C, sr, sc-1, er, ec);
    }
    if((sc+1) < C && arr[sr][sc+1]==1) {
        cout<<"sr : "<<sr<<" sc : "<<sc<<"\n";
        return rat_in_a_maze(arr, R, C, sr, sc+1, er, ec);
    }
    return false;
}


int main () {

    int arr[][4] = { 
        {1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {0, 1, 0, 0}, 
        {1, 1, 1, 1} };    
    int R{4}, C{4};
    int sr{0};
    int sc{0};
    int er{3};
    int ec{3};
    cout<<rat_in_a_maze(arr, R, C, sr, sc, er, ec)<<"\n";
    return 0;
}
