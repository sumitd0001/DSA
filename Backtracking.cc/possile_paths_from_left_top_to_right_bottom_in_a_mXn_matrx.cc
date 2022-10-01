#include <bits/stdc++.h>
using namespace std;

void print_all_paths(int arr[][3], int m, int n, int i, int j, int temp[][3]) {
    if(i == (m-1) && j == (n-1)) {
        temp[i][j]=1;
        for(int x=0; x<m; ++x) {
            for(int y=0; y<n; ++y) {
                if(temp[x][y]==1) cout<<arr[x][y]<<" ";
            }
        }cout<<"\n";
        temp[i][j]=0;
    }

    temp[i][j]=1;    
    if ((i-1) >=0 && temp[i-1][j]!=1) {
        //temp[i-1][j] = 1;
        print_all_paths(arr, m, n, i-1, j, temp);
        temp[i-1][j] = 0;
    }
    if ((j-1) >=0 && temp[i][j-1]!=1) {
        //temp[i][j-1] = 1;
        print_all_paths(arr, m, n, i, j-1, temp);
        temp[i][j-1] = 0;
    }
    if ((i+1)<m && temp[i+1][j]!=1) {
        //temp[i+1][j] = 1;
        print_all_paths(arr, m, n, i+1, j, temp);
        temp[i+1][j] = 0;
    }
    if ((j+1)<n && temp[i][j+1]!=1) {
        //temp[i][j+1] = 1;
        print_all_paths(arr, m, n, i, j+1, temp);
        temp[i][j+1] = 0;
    }
}

int main () {

    //int m{2}, n{3};
    int arr[2][3] =  { {1, 2, 3},
                       {4, 5, 6} };
    int temp[2][3] = {0};

    /*for(int i=0; i<2; ++i) {
        for(int j=0; j<3; ++j) {
            cout<<arr[i][j]<<" ";
        }cout<<"\n";
    }*/

    /*for(int i=0; i<2; ++i) {
        for(int j=0; j<3; ++j) {
            cout<<temp[i][j]<<" ";
        }cout<<"\n";
    }*/

    print_all_paths(arr, 2, 3, 0, 0, temp);

    return 0;
}