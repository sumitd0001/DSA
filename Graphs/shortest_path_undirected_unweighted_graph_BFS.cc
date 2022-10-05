#include <bits/stdc++.h>
using namespace std;

template <typename T>
void Shortest_Path_Unweighted_Graph (unordered_map<T, unordered_set<T>>& adj, unordered_map<T, bool>& visited, 
unordered_map<T, int>& distance, T source) {
    cout<<"Source Node : "<<source;
    distance[source] = 0;
    visited[source] = true;
    queue <T> q;
    q.push(source);

    while (!q.empty()) {
        T f = q.front();
        q.pop();
        for(auto n : adj[f]) {
            if (!visited[n]) {
                q.push(n);
                visited[n] = true;
                distance[n] = distance[f] + 1;
            }
        }
    }
}


template <typename T>
void Shortest_Path_Unweighted_Graph (unordered_map<T, unordered_set<T>>& adj) {
    cout<<"Shortest Path : \n";
    unordered_map<T, bool> visited;
    unordered_map<T, int> distance;
    for (auto p : adj) {
        visited[p.first] = false;
        distance[p.first] = INT_MIN;
    }
    for (auto p : adj) {
        if (!visited[p.first]) {
            Shortest_Path_Unweighted_Graph(adj, visited, distance, p.first);
            cout<<"\n";
        }
    }
    for (auto x : distance) {
        cout<<x.first<<" : "<<x.second<<"\n";
    }
}
