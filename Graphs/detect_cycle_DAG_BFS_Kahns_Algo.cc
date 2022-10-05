#include <bits/stdc++.h>
#include "topological_sorting_BFS.cc"
using namespace std;

template <typename T>
bool detect_cycle_DAG_Kahns_Algo (unordered_map<T, unordered_set<T>>& adj) {
    cout<<"Detec cycle in DAG using Topological Sort, Kahns Algorithm\n";
    unordered_map<T, int> indegree;
    calculate_indegree(adj, indegree);
    cout<<"indegrees for the given graph nodes\n";
    for (auto val : indegree) {
        cout<<val.first<<" "<<val.second<<"\n";
    }

    int cnt = adj.size();
    queue <T> q;

    int t{0};

    for (auto val : indegree) {
        if (val.second == 0) {
            q.push(val.first);
            t++;
        }
    }
    while (!q.empty()) {
        T f = q.front();
        q.pop();

        for (auto val : adj[f]) {
            indegree[val]--;
            if (indegree[val] == 0) {
                q.push(val);
                t++;
            }
        }
    }
    return (cnt != t);
}