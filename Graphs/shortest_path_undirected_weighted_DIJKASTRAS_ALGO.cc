#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
void shortest_path_DIJKASTRAS_ALGO (unordered_map<T1, set<pair<T1, T2>>>& adj, T1 source) {
    unordered_map<T1, bool> visited;
    unordered_map<T1, int> distance;

    for (auto node : adj) {
        visited[node.first] = false;
        distance[node.first] = INT_MAX;
    }

    distance[source] = 0;

    queue<T1> q;
    q.push(source);
    while (!q.empty()) {
        T1 front = q.front();
        q.pop();
        for (auto node : adj[front]) {
                if ((distance[front] + node.second ) < distance[node.first]) {
                    distance[node.first] = distance[front] + node.second;
                }
        }

        visited[front] = true;

        int smallest = INT_MAX;
        for (auto x : distance) {
            if (!visited[x.first]) {
                if (x.second < smallest) {
                    smallest = x.second;
                    front = x.first;
                }
            }
        }
        if (!visited[front]) {
            q.push(front);
        }
    }

    for (auto node : distance) {
        cout<<"Distance of "<<node.first<<" from "<<source<<" is : "<<node.second<<"\n";
    }
}