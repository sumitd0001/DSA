#include <bits/stdc++.h>
using namespace std;

/*
Given a N*N board with the Knight placed on the first block of an empty board. 
Moving according to the rules of chess knight must visit each square exactly once. 
Print the order of each cell in which they are visited.
*/

void knights_tour(int arr[][8], int m, int n, int i, int j, int temp[][8]) {
    
}

int main () {
     int arr[8][8] = { 
                     {0 , 59 , 38, 33, 30, 17, 8, 63},
                     {37, 34, 31, 60, 9, 62, 29, 16},
                     {58, 1, 36, 39, 32, 27, 18, 7},
                     {35, 48, 41, 26, 61, 10, 15, 28},
                     {42, 57, 2, 49, 40, 23, 6, 19},
                     {47, 50, 45, 54, 25, 20, 11, 14},
                     {56, 43, 52, 3, 22, 13, 24, 5},
                     {51, 46, 55, 44, 53, 4, 21, 12}
                     };

    int temp[8][8] = {};

    knights_tour();

    return 0;
}