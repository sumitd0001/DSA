/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, 
for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Solution : Find topological sort, if able to find for all the nodes , then can be completed, other wise we can can no
Why we can not ? If there exists a cycle
Detect Cycle in a Directed Graph (DFS : recusrsion Stack , BFS : Kahn's ALgorithm)
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs (unordered_map<int, unordered_set<int>>& adj, vector<int>& visited, vector<int>& recStack, int source) {
    visited[source] = 1;
    recStack[source] = 1;

    for (auto& node : adj[source]) {
        if (!visited[node]) {
            if (dfs(adj, visited, recStack, node)) return true;
        }
        else if (recStack[node]) return true;
    }

    recStack[source] = 0;
    return false;
}

bool isPossible(int N, vector<pair<int, int> > prerequisites) {
    vector<int> visited(N, 0);
    unordered_map<int, unordered_set<int>> adj;

    for (auto& node : prerequisites) {
        adj[node.second].insert(node.first);
    }

    for (auto& node : adj) {
        cout<<node.first<<"->";
        for (auto val : node.second) {
            cout<<val<<" ";
        }cout<<"\n";
    }

    vector<int> recStack(N, 0);

    for (auto& node : adj) {
        if (!visited[node.first]) {
            if (dfs(adj, visited, recStack, node.first)) return false;
        }
    }
    return true;
}

int main () {
    vector<pair<int, int>> prerequisites;
    cout<<isPossible(4, {{1, 0}, {2, 1}, {3, 2}})<<"\n";
    cout<<isPossible(20, {{0, 10}, {3, 18}, {5, 5}, {6, 11}, {11, 14}, {13, 1}, {15, 1}, {17, 4}})<<"\n";
}
