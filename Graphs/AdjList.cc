#include <bits/stdc++.h>
using namespace std;

template <typename T>
void addEdge (unordered_map<T, unordered_set<T>>& adj, T u, T v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

template <typename T>
void addEdge_Directed_Graph (unordered_map<T, unordered_set<T>>& adj, T u, T v) {
    adj[u].insert(v);
    //adj[v].insert(u);
}

template <typename T1, typename T2>
void addEdge_undirected_weighted (unordered_map<T1, set < pair<T1, T2> > >& adj, T1 u, T1 v, T2 cost) {
    adj[u].insert({v, cost});
    adj[v].insert({u, cost});
}

template <typename T1, typename T2>
void addEdge_directed_weighted (unordered_map<T1, set < pair<T1, T2> > >& adj, T1 u, T1 v, T2 cost) {
    adj[u].insert({v, cost});
    //adj[v].insert({u, cost});
}

template <typename T>
void calculate_indegree (unordered_map<T, unordered_set<T>>& adj, unordered_map <T, int>& indegree) {
    for(auto s : adj) {
        if (indegree.find(s.first)!=indegree.end()) {
            for (auto val : s.second) {
                indegree[val]++;
            }
        }
        else {
            indegree.insert({s.first, 0});
            for (auto val : s.second) {
                indegree[val]++;
            }
        }
    }
}

template <typename T>
void topological_sorting_BFS(unordered_map<T, unordered_set<T>>& adj) {
    unordered_map<T, int> indegree;
    calculate_indegree(adj, indegree);
    cout<<"indegrees for the given graph nodes\n";
    for (auto val : indegree) {
        cout<<val.first<<" "<<val.second<<"\n";
    }

    queue<T> q;
    for (auto val : indegree) {
        if (val.second == 0) {
            q.push(val.first);        
        }
    }
    cout<<"Topological Sort BFS : \n";
    while (!q.empty()) {
        T front = q.front();
        q.pop();
        cout<<front<<" ";
        for (auto val : adj[front]) {
            indegree[val]--;
            if (indegree[val] == 0) q.push(val);
        }
    }cout<<"\n";
}

template <typename T>
bool detect_cycle_DAG_Kahns_Algo (unordered_map<T, unordered_set<T>>& adj) {
    cout<<"Detec cycle in DAG using Topological Sort, Kahns Algorithm\n";
    unordered_map<T, int> indegree;
    calculate_indegree(adj, indegree);
    cout<<"indegrees for the given graph nodes\n";
    for (auto val : indegree) {
        cout<<val.first<<" "<<val.second<<"\n";
    }

    int cnt = adj.size();
    queue <T> q;

    int t{0};

    for (auto val : indegree) {
        if (val.second == 0) {
            q.push(val.first);
            t++;
        }
    }
    while (!q.empty()) {
        T f = q.front();
        q.pop();

        for (auto val : adj[f]) {
            indegree[val]--;
            if (indegree[val] == 0) {
                q.push(val);
                t++;
            }
        }
    }
    return (cnt != t);
}

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

template <typename T>
bool detect_cycle_directed_graph_DFS (unordered_map <T, unordered_set<T>>& adj, unordered_map <T, bool>& visited, unordered_map <T, bool>& recStack, T source) {
    visited[source] = true;
    recStack[source] = true;

    for(auto n : adj[source]) {
        if (!visited[n]) {
            if (detect_cycle_directed_graph_DFS(adj, visited, recStack, n)) return true;
        }
        else if (recStack[n]) return true;
    }
    recStack[source] = false;
    return false;

}


template <typename T>
bool detect_cycle_directed_graph_DFS (unordered_map<T, unordered_set<T>>& adj) {
    cout<<"If Cycle exists in directed graph DFS : \n";
    unordered_map <T, bool> visited;
    unordered_map <T, bool> recStack;
    for(auto p : adj) {
        visited[p.first] = false;
        recStack[p.first] = false;
    }
    for (auto p : adj) {
        if (!visited[p.first]) {
                if (detect_cycle_directed_graph_DFS(adj, visited, recStack, p.first)) return true;
                cout<<"\n";
        }
    }
    return false;
}

template <typename T>
void print (const unordered_map<T, unordered_set<T>>& adj) {
    cout<<"adj List : \n";
    for(const auto& ver : adj) {
        cout<<ver.first<<"->";
        for(const auto& l : ver.second) {
            cout<<l<<" ";
        }cout<<"\n";
    }
}

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

template <typename T1, typename T2>
void topological_sort_weighted_DFS (unordered_map<T1, set<pair<T1, T2>>>& adj, unordered_map<T1, bool>& visited, stack<T1>& s, T1 source) {
    visited[source] = true;

    for (auto node : adj[source]) {
        if (!visited[node.first]) {
            topological_sort_weighted_DFS(adj, visited, s, node.first);
        }
    }
    s.push(source);
}

template <typename T1, typename T2>
void shortest_path_DAG_weighted (unordered_map<T1, set<pair<T1, T2>>>& adj, T1 source) {
    unordered_map <T1, bool> visited;
    stack<T1> s;
    unordered_map<T1, int> dist;

    for (auto node : adj) {
        visited[node.first] = false;
        dist[node.first] = INT_MAX;
    }
    dist[source] = 0;
    topological_sort_weighted_DFS(adj, visited, s, source);

    while(!s.empty()) {
        T1 top = s.top();
        s.pop();

        for (auto node : adj[top]) {
            if(dist[top] + node.second < dist[node.first]) {
                dist[node.first] = dist[top] + node.second;
            }
        }
    }

    for (auto val : dist) {
        cout<<"Distance of "<<val.first<<" from "<<source<<" : ";
        if (val.second == INT_MAX) {
            cout<<"Can't be reached\n";
        }
        else {
            cout<<val.second<<"\n";
        }
    }
}

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

int main () {

    unordered_map<int, unordered_set<int>> adj;
    
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);

    print(adj);
    BFS(adj);
    DFS(adj);
    Shortest_Path_Unweighted_Graph(adj);
    cout<<detect_cycle_BFS(adj)<<"\n";
    cout<<detect_cycle_DFS(adj)<<"\n";

    unordered_map<int, unordered_set<int>> adj_directed;
    addEdge_Directed_Graph(adj_directed, 1, 2);
    addEdge_Directed_Graph(adj_directed, 1, 4);
    addEdge_Directed_Graph(adj_directed, 2, 3);
    addEdge_Directed_Graph(adj_directed, 2, 5);
    addEdge_Directed_Graph(adj_directed, 3, 7);
    addEdge_Directed_Graph(adj_directed, 4, 6);
    addEdge_Directed_Graph(adj_directed, 5, 7);
    addEdge_Directed_Graph(adj_directed, 6, 5);
    addEdge_Directed_Graph(adj_directed, 6, 7);

    topological_sorting_BFS(adj_directed);
    topological_sort_DFS(adj_directed);
    bool isCycle = detect_cycle_DAG_Kahns_Algo(adj_directed);
    cout<<"Cycle Exists : "<<isCycle<<"\n";

    unordered_map<int, unordered_set<int>> adj_directed_cycle;
    addEdge_Directed_Graph(adj_directed_cycle, 1, 2);
    addEdge_Directed_Graph(adj_directed_cycle, 1, 3);
    addEdge_Directed_Graph(adj_directed_cycle, 2, 3);
    addEdge_Directed_Graph(adj_directed_cycle, 3, 1);
    addEdge_Directed_Graph(adj_directed_cycle, 3, 4);
    addEdge_Directed_Graph(adj_directed_cycle, 4, 4);
    isCycle = detect_cycle_DAG_Kahns_Algo(adj_directed_cycle);
    cout<<"Cycle Exists : "<<isCycle<<"\n";

    unordered_map<int, set<pair<int, int>>> adj_directed_weighted;
    addEdge_directed_weighted(adj_directed_weighted, 1, 2, 2);
    addEdge_directed_weighted(adj_directed_weighted, 1, 5, 1);
    addEdge_directed_weighted(adj_directed_weighted, 2, 3, 3);
    addEdge_directed_weighted(adj_directed_weighted, 5, 3, 2);
    addEdge_directed_weighted(adj_directed_weighted, 5, 6, 4);
    addEdge_directed_weighted(adj_directed_weighted, 3, 4, 6);
    addEdge_directed_weighted(adj_directed_weighted, 6, 4, 1);
    cout<<"Shortest Path in a DAG weighted : \n";
    for (auto node : adj_directed_weighted) {
        shortest_path_DAG_weighted(adj_directed_weighted, node.first); 
    }

    unordered_map<int, set<pair<int, int>>> adj_undirected_weighted;
    addEdge_undirected_weighted(adj_undirected_weighted, 1, 2, 4);
    addEdge_undirected_weighted(adj_undirected_weighted, 1, 3, 8);
    addEdge_undirected_weighted(adj_undirected_weighted, 2, 3, 11);
    addEdge_undirected_weighted(adj_undirected_weighted, 2, 4, 8);
    addEdge_undirected_weighted(adj_undirected_weighted, 3, 5, 7);
    addEdge_undirected_weighted(adj_undirected_weighted, 3, 6, 1);
    addEdge_undirected_weighted(adj_undirected_weighted, 4, 5, 2);
    addEdge_undirected_weighted(adj_undirected_weighted, 4, 7, 7);
    addEdge_undirected_weighted(adj_undirected_weighted, 4, 8, 4);
    addEdge_undirected_weighted(adj_undirected_weighted, 5, 6, 6);
    addEdge_undirected_weighted(adj_undirected_weighted, 6, 8, 2);
    addEdge_undirected_weighted(adj_undirected_weighted, 7, 8, 14);
    addEdge_undirected_weighted(adj_undirected_weighted, 7, 9, 9);
    addEdge_undirected_weighted(adj_undirected_weighted, 8, 9, 10);

    for (auto node : adj_undirected_weighted) {
        shortest_path_DIJKASTRAS_ALGO(adj_undirected_weighted, node.first);
    }

    for (auto node : adj_undirected_weighted) {
        minimum_Spanning_Tree_PRIMS_ALGO(adj_undirected_weighted, node.first);
    }

    return 0;
}