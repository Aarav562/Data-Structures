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
    for(int i=0;i<V;i++){
        dist[i] = INT_MAX;
        setSpt[i] = false;
    }
    dist[src] = 0;
    for(int count =0;count<V-1;count++){
        int u = minDist(dist,setSpt);
        setSpt[u] = true;
        for(int v=0;v<V;v++){
                if (!setSpt[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                }
        }
    }
    printSolution(dist);
}
int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    Dijkstra(graph,0);
    return 0;
}