#include <bits/stdc++.h>
using namespace std;

/*
find the tournament winner : 
competitons : matches between given teams. Home and away team, 
results : reults with respect to home team, if 0 away team won, if 1, home team won
*/

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  // Write your code here.
  unordered_map<string, int> map;
  for(int i = 0; i<results.size(); ++i) {
    if(results[i] == 1) {
      auto itr1 = map.find(competitions[i][0]);
      if(itr1!=map.end()){
        ++(itr1->second);
      }
      else {
        map[competitions[i][0]] = 1;
      }
    }
    else {
      auto itr1 = map.find(competitions[i][1]);
      if(itr1!=map.end()){
        ++(itr1->second);
      }
      else {
        map[competitions[i][1]] = 1;
      }
    }
  }
    string winner{""};
    int max = 0;
    for(auto itr = map.begin(); itr!=map.end(); ++itr) {
      if(itr->second > max) {
        winner = itr->first;
        max = itr->second;
      }
    }
  return winner;
}

int main () {

  vector<vector<string>> competitions = {
    {"HTML", "Java"},
    {"Java", "Python"},
    {"Python", "HTML"},
    {"C#", "Python"},
    {"Java", "C#"},
    {"C#", "HTML"},
    {"SQL", "C#"},
    {"HTML", "SQL"},
    {"SQL", "Python"},
    {"SQL", "Java"}
    };
  vector<int> results = {0, 0, 0, 0, 0, 0, 1, 0, 1, 1};

  cout<<tournamentWinner(competitions, results)<<"\n";

    return 0;
}
/*
Output : 
SQL
*/