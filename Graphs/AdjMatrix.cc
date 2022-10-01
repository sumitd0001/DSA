#include <bits/stdc++.h>
using namespace std;

int main () {

    int v{0};
    int e{0};

    cout<<"Enter number of vertices : \n";
    cin>>v;

    cout<<"Enter number of edges : \n";
    cin>>e;

    int adj[v][v] = {};

    for (int i = 0; i<e; ++i) {
        cout<<"Total edges : "<<i<<"\n";
        int j{0}, k{0};
        cout<<"Enter the vertices having edges between them: \n";
        cin>>j>>k;
        if(j > v-1 || k > v-1) {
            cout<<"Please enter valide vertices\n";
            --i;
        }
        else {

            adj[j][k] = 1;
            adj[k][j] = 1;
        }
    }
    cout<<"  ";
    for(int i=0; i<v; ++i)  {
        cout<<" "<<i;
    }cout<<"\n";
    for(int i=0; i<v; ++i) {
        cout<<i<<"->";
        for(int j=0; j<v; ++j) {
            cout<<adj[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}