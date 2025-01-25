#include<bits/stdc++.h>
using namespace std;

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