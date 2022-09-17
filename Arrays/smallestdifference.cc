#include <bits/stdc++.h>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());
  vector<int> result{};
  int left{0}, right{0};
  int diff = INT_MAX;
  int i{arrayOne[0]};
  int j{arrayTwo[0]};
  while(left < arrayOne.size() && right< arrayTwo.size()) {
    int d = abs(arrayOne[left]-arrayTwo[right]);
    if(d == 0) {
      i = arrayOne[left];
      j = arrayTwo[right];
      diff = d;
      break;
    }
    else if(d < diff) {
      diff = d;
      i = arrayOne[left];
      j = arrayTwo[right];
      diff = d;
    }
    else if (arrayOne[left] < arrayTwo[right]) {
      left++;
    }
    else if (arrayOne[left] > arrayTwo[right]) {
      right++;
    }
  }
  result.push_back(i);
  result.push_back(j);
  return result;
}

int main () {
    vector<int> vec1{-1, 5, 10, 20, 28, 3};
    vector<int> vec2{26, 134, 135, 15, 17};
    vector<int> result = smallestDifference(vec1, vec2);
    for(auto& var : result) {
        cout<<var<<" ";
    }
    return 0;
}
