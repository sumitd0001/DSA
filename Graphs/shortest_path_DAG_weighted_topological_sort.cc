#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
void topological_sort_weighted_DFS (unordered_map<T1, set<pair<T1, T2>>>& adj, unordered_map<T1, bool>& visited, stack<T1>& s, T1 source) {
    visited[source] = true;

    for (auto node : adj[source]) {
        if (!visited[node.first]) {
            topological_sort_weighted_DFS(adj, visited, s, node.first);
        }
    }
    s.push(source);
}

template <typename T1, typename T2>
void shortest_path_DAG_weighted (unordered_map<T1, set<pair<T1, T2>>>& adj, T1 source) {
    unordered_map <T1, bool> visited;
    stack<T1> s;
    unordered_map<T1, int> dist;

    for (auto node : adj) {
        visited[node.first] = false;
        dist[node.first] = INT_MAX;
    }
    dist[source] = 0;
    topological_sort_weighted_DFS(adj, visited, s, source);

    while(!s.empty()) {
        T1 top = s.top();
        s.pop();

        for (auto node : adj[top]) {
            if(dist[top] + node.second < dist[node.first]) {
                dist[node.first] = dist[top] + node.second;
            }
        }
    }

    for (auto val : dist) {
        cout<<"Distance of "<<val.first<<" from "<<source<<" : ";
        if (val.second == INT_MAX) {
            cout<<"Can't be reached\n";
        }
        else {
            cout<<val.second<<"\n";
        }
    }
}
