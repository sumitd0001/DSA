#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool detect_cycle_DFS (unordered_map <T, unordered_set<T>>& adj, unordered_map <T, bool>& visited, T parent, T source) {
    visited[source] = true;

    for (auto n : adj[source]) {
        if (!visited[n]) {
            if (detect_cycle_DFS(adj, visited, source, n)) return true;
        }
        else if (visited[n] && n != parent) return true;
    }
    return false;
}

template <typename T>
bool detect_cycle_DFS (unordered_map<T, unordered_set<T>>& adj) {
    cout<<"If Cycle exists DFS : \n";
    unordered_map <T, bool> visited;
    T parent{0};

    for(auto p : adj) {
        visited[p.first] = false;
    }
    for (auto p : adj) {
        if (!visited[p.first]) {
                if (detect_cycle_DFS(adj, visited, parent, p.first)) return true;
                cout<<"\n";
        }
    }
    return false;
}