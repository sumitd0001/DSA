#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool detect_cycle_BFS (unordered_map<T, unordered_set<T>>& adj, unordered_map <T, bool>& visited, unordered_map <T, T>& parent, T source) {
    queue<T> q;
    visited[source] = true;

    q.push(source);
    while (!q.empty()) {
        T f = q.front();
        q.pop();

        for (auto n : adj[f]) {
            if (!visited[n]) {
                q.push(n);
                parent[n] = f;
            }
            else if (visited[n]) {
                    if (parent.find(n) != parent.end()) {
                        if(parent[f] != n) return true;
                    }
            }
        }
    }
    return false;
}

template <typename T>
bool detect_cycle_BFS (unordered_map<T, unordered_set<T>>& adj) {
    cout<<"If Cycle exists BFS : \n";
    unordered_map <T, bool> visited;
    unordered_map <T, T> parent;

    for(auto p : adj) {
        visited[p.first] = false;
        parent[p.first] = 0; 
    }
    for (auto p : adj) {
        if (!visited[p.first]) {
                if (detect_cycle_BFS(adj, visited, parent, p.first)) return true;
                cout<<"\n";
        }
    }
    return false;
}