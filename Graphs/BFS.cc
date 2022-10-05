#include <bits/stdc++.h>
using namespace std;

template <typename T>
void BFS (unordered_map<T, unordered_set<T>>& adj, unordered_map<T, bool>& visited, T source) {
    queue<T> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        T f = q.front();
        cout<<f<<" ";
        q.pop();
        for(T n : adj[f]) {
            if(!visited[n]) {
                q.push(n);
                visited[n] = true;
            }
        }
    }
}

template <typename T>
void BFS (unordered_map<T, unordered_set<T>>& adj) {
    cout<<"BFS : \n";
    unordered_map<T, bool> visited;
    for(auto p : adj) {
        visited[p.first] = false;
    }
    for(auto p : adj) {
        if(!visited[p.first]) {
            BFS (adj, visited, p.first);
            cout<<"\n";
        }
    }
}