#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
void minimum_Spanning_Tree_PRIMS_ALGO (unordered_map <T1, set<pair<T1, T2>>>& adj, T1 source) {
    cout<<"Minimum Spanning Tree : ";

    unordered_map<T1, bool> visited;
    unordered_map <T1, int> dist;
    
    for(auto node : adj) {
        visited[node.first] = false;
        dist[node.first] = INT_MAX;
    }
    dist[source] = 0;

    queue<T1> q;
    q.push(source);

    while(!q.empty()) {
        T1 front = q.front();
        cout<<front<<" ";
        q.pop();

        for (auto node : adj[front]) {
            if(!visited[node.first]) {
                if(dist[front] + node.second < dist[node.first]) {
                    dist[node.first] = dist[front] + node.second;
                }
            }
        }
        visited[front] = true;
        T2 min {INT_MAX};
        
        for (auto node : adj) {
            if (!visited[node.first]) {
                if (dist[node.first] < min) {
                    min = dist[node.first];
                    front = node.first;
                }
            }
        }
        if (!visited[front]) {
            q.push(front);
        }
    }
    cout<<"\n";
}