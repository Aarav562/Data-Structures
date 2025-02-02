#include<bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[]){
    vector<int>visited(V,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int sum =0;
    while(!pq.empty()){
        int u = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if(visited[u]==0){
            visited[u]=1;
            sum+=wt;
        }
        for(auto it : adj[u]){
            int v = it[0];
            int w = it[1];
            if(visited[v]==0){
                pq.push({w,v});
            }
        }
    }
    return sum;
}
int main() {
    int V = 5;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7}
    };
    for (auto edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << "Minimum Spanning Tree weight: " << spanningTree(V, adj) << endl;
    return 0;
}