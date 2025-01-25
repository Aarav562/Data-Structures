#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Graph{
    int V;
    list<pair<int,int>> adj;

    public:
    Graph(int V);

    void add_edge(int u,int v,int w);
    void shortest_path(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<pair<int,int>>[V];
}
void Graph::add_edge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void Graph::shortest_path(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    
    vector<int> dist(V,INF);
    pq.push(make_pair(0,s));
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto neighbour: adj[u]){
            int v = neighbour.first;
            int weight  = neighbour.second;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }

    cout<<"Vertex Distance From Source"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}
