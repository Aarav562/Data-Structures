#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Graph{
    int V;
    list<pair<int,int>> *adj;

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
int main(){
    int V = 9;
    Graph g(V);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);

    g.shortest_path(0);
    return 1;
}