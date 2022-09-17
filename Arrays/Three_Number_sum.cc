#include <bits/stdc++.h>
using namespace std;

/*vector<vector<int>> three_numbers_sum(vector<int>& vec, int& targetSum) {

    sort(vec.begin(), vec.end());

    vector<vector<int>> three_numbers{};
    unordered_map<int, bool> m;
    for(auto itr = vec.begin(); itr!=vec.end(); ++itr) {
        int findingSum = targetSum - *(itr);
        for(auto itr2 = (itr+1); itr2!=vec.end(); ++itr2) {
            if(m.find(findingSum - *(itr2)) != m.end() && (*(itr2) != (findingSum - *(itr2))) && (*(itr2) != *(itr)) && (*(itr) != (findingSum - *(itr2)))){
                three_numbers.push_back({*itr, *itr2, findingSum-*(itr2)});
            }
            m[*itr2] = true;
        }
    }
    return three_numbers;
}*/

vector<vector<int>> three_numbers_sum(vector<int>& vec, int& targetSum) { 
    sort(vec.begin(), vec.end());

    vector<vector<int>> triplets{};

    int left{0}, right{0};

    for(int i = 0; i<vec.size()-2; ++i) {
        left = i+1;
        right = vec.size()-1;
        while(left < right) {
            int currentSum = vec[i]+vec[left]+vec[right];
            if(currentSum == targetSum) {
                triplets.push_back({vec[i], vec[left], vec[right]});
                left++;
                right--;
            }
            else if (currentSum < targetSum) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return triplets;
}

int main () {

    vector<int> vec{12, 3, 1, 2, -6, 5, -8, 6};
    int targetSum{0};
    vector<vector<int>> three_numbers = three_numbers_sum(vec, targetSum);

    for(auto var : three_numbers) {
        for(auto& x : var) {
            cout<<x<<" ";
        }cout<<"\n";
    }
    return 0;
}