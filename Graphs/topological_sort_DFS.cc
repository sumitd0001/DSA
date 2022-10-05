#include <bits/stdc++.h>
using namespace std;

template <typename T>
void topological_sort_DFS(unordered_map <T, unordered_set<T>>& adj, stack <T>& s, unordered_map <T, bool>& visited, T source) {
    visited[source] = true;

    for (auto val : adj[source]) {
        if (!visited[val])
        topological_sort_DFS(adj, s, visited, val);
    }
    s.push(source);
}

template <typename T>
void topological_sort_DFS (unordered_map <T, unordered_set<T>>& adj) {
    cout<<"Topological Sort DFS : \n";
    unordered_map <T, bool> visited;
    stack <T> s;
    for (auto val : adj) {
        visited[val.first] = false;
    }

    for (auto val : adj) {
        if (!visited[val.first]) {
            topological_sort_DFS(adj, s, visited, val.first);
        }
    }

    while (!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }cout<<"\n";
}