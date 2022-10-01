#include <bits/stdc++.h>
#include "Graph.hh""
using namespace std;

template <typename T>
Graph<T>* Graph<T>::_instance = nullptr;

template <typename T>
Graph<T>::Graph (int v = 5, int e = 7, bool old = false) : _v(v), _e(e), _old(old) {
    if (!old) {
        //create adjlist


        //create adjmatrix



    }
}


/*
cases of get instance
create a new graph : so have to create both, old = false
use old graph : old = true

*/
template <typename T>
Graph<T>* Graph<T>::getInstance () {
    if(!_instance) {
        _instance = new Graph(5, 7);
    }
    return _instance;
}

template <typename T>
Graph<T>* Graph<T>::getInstance (int v, int e) {
    delete _instance;
    _instance = new Graph(v, e);
    return _instance;
}

template <typename T>
const T** Graph<T>::getadjMatrix () {
    return adjMatrix;
}

template <typename T>
const unordered_map<T, unordered_set<T>>* Graph<T>::getadjList () {
    return adjList;
}

template <typename T>
void Graph<T>::addEdge_adjList(const T& j, const T& k) {
    adjList[j].insert(k);
    adjList[k].insert(j);
}

template <typename T>
void Graph<T>::create_adj_list() {
    adjList = new unordered_map<T, unordered_set<T>>;

    for(int i = 0; i<_e; ++i) {
        T j, k; 
        cout<<"Enter Vertices for edge to add : \n";
        cin>>j>>k;
        addEdge_adjList(j, k);
    }
}

template <typename T>
void Graph<T>::print_adj_list() {
    for(const auto& v1 : adjList) {
        cout<<v1.first<<"->";
        for(const auto& v2 : v1.second) {
            cout<<v2<<" ";
        }cout<<"\n";
    }
}

template <typename T>
void Graph<T>::print_adj_matrix () {
    for(int i = 0; i<_v; ++i) {
        cout<<i
    }
}

template <typename T>
void Graph<T>::addEdge_adjMatrix(const T& j, const T& k) {
    adjMatrix[j][k] = 1;
    adjMatrix[k][j] = 1;
}

template <typename T>
void Graph<T>::create_adj_matrix() {
    adjMatrix = new T[_v][_v];

    for(int i = 0; i<_e; ++i) {
        cout<<"Enter Vertices for edge to add : \n";
        cout<<"Enter Vertices for edge to add : \n";
        cin>>j>>k;
        addEdge_adjMatrix(j, k);
    
    }

}


