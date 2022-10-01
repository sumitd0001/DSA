#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    public :

        static Graph<T>* getInstance ();
        static Graph<T>* getInstance (int v, int e);
        const unordered_map<T, unordered_set<T>>* getadjList ();
        const T** getadjMatrix ();

    private : 

        static Graph* _instance;
        Graph (int v, int e, bool old);
        Graph (const Graph& obj) {}
        Graph& operator=(const Graph& obj) {}
        void create_adj_list();
        void create_adj_matrix();
        void addEdge_adjList(const T& j, const T& k);
        void addEdge_adjMatrix(const T& j, const T& int k);
        void print_adj_list();
        void print_adj_matrix();

    private:

        int _v;
        int _e;
        bool _old;
        unordered_map<T, unordered_set<T>>* adjList;
        T** adjMatrix;
};

int main () {

    return 0;
}