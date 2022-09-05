#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array. Find out the sorted sqaured array.
*/

//Using stack
vector<int> sortedsqauredarrray_stack (vector<int>& array) {
    vector<int> sortedsqauredarrray;
    stack<int> s;
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        if(abs(array[left]) > abs(array[right])) {
            s.push(array[left]*array[left]);
            ++left;
        }
        else {
            s.push(array[right]*array[right]);
            --right;
        }
    }

    while(!s.empty()) {
        sortedsqauredarrray.push_back(s.top());
        s.pop();
    }

    return sortedsqauredarrray;
}

vector<int> sortedsqauredarrray (vector<int>& array) {
    vector<int> sorted_squared_array(array.size(), 0);

    int left = 0;
    int right = array.size()-1;
    int index = array.size()-1;
    while(left <= right) {
        if(abs(array[left]) > abs(array[right])) {
            sorted_squared_array[index] = array[left]*array[left];
            ++left;
            --index;
        }
        else {
            sorted_squared_array[index] = array[right]*array[right];
            --index;
            --right;
        }
    }

    return sorted_squared_array;
}

int main () {

    vector<int> vec1{-9, -8, -7, 0, 1, 2, 3, 4};
    cout << "Using Stack and another array : " << endl;
    vector<int> vec2 = sortedsqauredarrray_stack(vec1);

    for(auto& val : vec2) {
        cout<<val<<" ";
    }cout<<endl;

    cout<<"Using only another array : "<<endl;
    vector<int> vec3 = sortedsqauredarrray(vec1);
    for(auto& val : vec3) {
        cout<<val<<" ";
    }cout<<endl;

    return 0;
}
