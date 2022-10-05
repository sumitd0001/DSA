#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool detect_cycle_directed_graph_DFS (unordered_map <T, unordered_set<T>>& adj, unordered_map <T, bool>& visited, 
unordered_map <T, bool>& recStack, T source) {
    visited[source] = true;
    recStack[source] = true;

    for (auto& node : adj[source]) {
        if (!visited[node]) {
            if (detect_cycle_directed_graph_DFS(adj, visited, recStack, node)) {
                return true;
            }
        }
        else if (recStack[node]) {
            return true;
        }
    }
    
    recStack[source] = false;
    return false;
}

template <typename T>
bool detect_cycle_directed_graph_DFS (unordered_map <T, unordered_set<T>>& adj) {
    unordered_map <T, bool> visited;
    unordered_map <T, bool> recStack;

    for (auto& node : adj) {
        visited[node.first] = false;
        recStack[node.first] = false;
    }

    for (auto& node : adj) {
        if (!visited[node.first]) {
            if (detect_cycle_directed_graph_DFS(adj, visited, recStack, node.first)) return true;
        }
    }
    return false;
}