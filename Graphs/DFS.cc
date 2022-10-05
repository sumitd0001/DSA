#include <bits/stdc++.h>
using namespace std;

template <typename T>
void DFS (unordered_map<T, unordered_set<T>>& adj, unordered_map<T, bool>& visited, T source) {

    visited[source] = true;
    cout<<source<<" ";

    for (auto n : adj[source]) {
        if (!visited[n]) {
            DFS(adj, visited, n);
        }
    }
}

template <typename T>
void DFS (unordered_map<T, unordered_set<T>>& adj) {
    cout<<"DFS : \n";
    unordered_map<T, bool> visited;
    for(auto p : adj) {
        visited[p.first] = false;
    }
    for(auto p : adj) {
        if(!visited[p.first]) {
            DFS (adj, visited, p.first);
            cout<<"\n";
        }
    }
}