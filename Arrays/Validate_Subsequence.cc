#include <bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    if(array.size() < sequence.size()) return false;
  
    if(sequence.size() == 0) true;

    int i{0}, j{0};
    for(; i<array.size(); ++i) {
        if(array[i] == sequence[j]) {
            ++j;
            if(j == sequence.size()) return true;
        }
    }
    return false;
}

int main () {

    vector<int> array{5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> sequence{1, 6, -1, 10};

    cout<<"Array : \n";
    for(auto x : array) {
        cout <<x<<" ";
    }cout<<"\n";

    cout<<"Sequence : \n";
    for(auto x : sequence) {
        cout <<x<<" ";
    }cout<<"\n";

    cout<<"Is Sequence a valid subsequence of array : "<<isValidSubsequence(array, sequence)<<"\n";

    return 0;
}