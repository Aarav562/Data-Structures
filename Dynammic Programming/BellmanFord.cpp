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