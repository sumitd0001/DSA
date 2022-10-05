#include <bits/stdc++.h>
using namespace std;

template <typename T>
void calculate_indegree (unordered_map<T, unordered_set<T>>& adj, unordered_map <T, int>& indegree) {
    for(auto s : adj) {
        if (indegree.find(s.first)!=indegree.end()) {
            for (auto val : s.second) {
                indegree[val]++;
            }
        }
        else {
            indegree.insert({s.first, 0});
            for (auto val : s.second) {
                indegree[val]++;
            }
        }
    }
}

template <typename T>
void topological_sorting_BFS(unordered_map<T, unordered_set<T>>& adj) {
    unordered_map<T, int> indegree;
    calculate_indegree(adj, indegree);
    cout<<"indegrees for the given graph nodes\n";
    for (auto val : indegree) {
        cout<<val.first<<" "<<val.second<<"\n";
    }

    queue<T> q;
    for (auto val : indegree) {
        if (val.second == 0) {
            q.push(val.first);        
        }
    }
    cout<<"Topological Sort BFS : \n";
    while (!q.empty()) {
        T front = q.front();
        q.pop();
        cout<<front<<" ";
        for (auto val : adj[front]) {
            indegree[val]--;
            if (indegree[val] == 0) q.push(val);
        }
    }cout<<"\n";
}