#include <bits/stdc++.h>
#include "BFS.cc"
#include "DFS.cc"
//#include "topological_sorting_BFS.cc" // already included in detect_cycle_DAG_BFS_Kahns_Algo.cc file
#include "topological_sort_DFS.cc"
#include "shortest_path_undirected_unweighted_graph_BFS.cc"
#include "detect_cycle_undirected_BFS.cc"
#include "detect_cycle_undirected_DFS.cc"
#include "detect_cycle_directed_graph_DFS.cc"
#include "detect_cycle_DAG_BFS_Kahns_Algo.cc"
#include "shortest_path_DAG_weighted_topological_sort.cc"
#include "shortest_path_undirected_weighted_DIJKASTRAS_ALGO.cc"
#include "minimum_spanning_tree_PRIMS_ALGO.cc"
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
void print (const unordered_map<T, unordered_set<T>>& adj) {
    cout<<"adj List : \n";
    for(const auto& ver : adj) {
        cout<<ver.first<<"->";
        for(const auto& l : ver.second) {
            cout<<l<<" ";
        }cout<<"\n";
    }
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
    cout<<"Cycle Exists Directed Graph BFS (Kahn's algo): "<<isCycle<<"\n";
    isCycle = detect_cycle_directed_graph_DFS(adj_directed);
    cout<<"Cycle Exists Directed Graph DFS : "<<isCycle<<"\n";


    unordered_map<int, unordered_set<int>> adj_directed_cycle;
    addEdge_Directed_Graph(adj_directed_cycle, 1, 2);
    addEdge_Directed_Graph(adj_directed_cycle, 1, 3);
    addEdge_Directed_Graph(adj_directed_cycle, 2, 3);
    addEdge_Directed_Graph(adj_directed_cycle, 3, 1);
    addEdge_Directed_Graph(adj_directed_cycle, 3, 4);
    addEdge_Directed_Graph(adj_directed_cycle, 4, 4);
    isCycle = detect_cycle_DAG_Kahns_Algo(adj_directed_cycle);
    cout<<"Cycle Exists Directed Graph BFS (Kahn's algo): "<<isCycle<<"\n";
    isCycle = detect_cycle_directed_graph_DFS(adj_directed_cycle);
    cout<<"Cycle Exists Directed Graph DFS : "<<isCycle<<"\n";

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