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