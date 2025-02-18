#include<bits/stdc++.h>
using namespace std;

vector<int> belmanford(vector<vector<int>> edges,int V,int src){
    vector<int> dist(V,1e8);
    dist[src] = 0;
    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int u= it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e8 && dist[v]>dist[u] + wt){
                dist[v] = dist[u] +wt;
            }
        }
    }
    for(auto it: edges){
        int u= it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u]!=1e8 && dist[v]>dist[u] + wt){
            return {-1};
        }
    }
    return dist;
}

int main(){
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<int>> edges(E);
    cout << "Enter the edges (u, v, weight) for each edge:" << endl;
    for(int i = 0; i < E; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
    }
    
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> result = belmanford(edges, V, src);
    
    if(result[0] == -1){
        cout << "Graph contains a negative weight cycle!" << endl;
    } else {
        cout << "Shortest distances from source vertex " << src << ":" << endl;
        for(int i = 0; i < V; i++){
            if(result[i] == 1e8)
                cout << "INF ";
            else
                cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}