#include <bits/stdc++.h>
using namespace std;

//Find all the permutations of a string

/*
Backtracking : 
Works just like Inorder Traversal of tree:

                        abc 

        abc               bac                cba

    abc     acb     bac     bca         cba     cab
    
    assuming root, try to find the next position from here, left child, try to find next pos, after completing traversal of left child, goes back to root,
    left child of left child, ||ly...goes to the terminating condition and then goes back to its parent, and then only to next child of the same parent
    prints the leaf only
*/

void permutations(string& str, int l, int r) {
    if(l == r) {
        cout<<str<<"\n";
        return;
    }
    for(int i = l; i<=r; ++i) {
        swap(str[l], str[i]);
        permutations(str, l+1, r);
        swap(str[l], str[i]);
    }
}

int main () {

    string s{"abc"};
    permutations(s, 0, s.length()-1);
    cout<<"\n";

    return 0;
}