#include<bits/stdc++.h>
using namespace std;
#define V 9

int minDist(int dist[], bool sprSet[]){
    int min = INT_MAX,min_idx;
    for(int v=0;v<V;v++){
        if(sprSet[v] == false && dist[v]<=min){
            min = dist[v];
            min_idx = v;
        }
    }
    return min_idx;
}
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}
void Dijkstra(int graph[V][V],int src){
    int dist[V];
    bool setSpt[V];
    for(int i=0;i<v;i++){
        dist[i] = INT_MAX;
        setSpt[i] = false;
    }
    dist[src] = 0;
    for(int count =0;count<V-1;count++){
        int u = minDist(dist,setSpt);
        setSpt[u] = true;
        for(int v=0;v<V;v++){
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                }
        }
    }
    printSolution(dist);
}