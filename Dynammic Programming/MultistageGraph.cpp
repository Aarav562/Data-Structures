#include<bits/stdc++.h>
using namespace std;
int main(){
    int stages = 4,min;
    int n =8;
    int cost[9],d[9],path[9];
    int G[9][9] ={{0,0,0,0,0,0,0,0,0},
                    {0,0,2,1,3,0,0,0,0},
                    {0,0,0,0,0,2,3,0,0},
                    {0,0,0,0,0,6,7,0,0},
                    {0,0,0,0,0,6,8,9,0},
                    {0,0,0,0,0,0,0,0,6},
                    {0,0,0,0,0,0,0,0,4},
                    {0,0,0,0,0,0,0,0,5},
                    {0,0,0,0,0,0,0,0,0}};
    cost[n] =0;
    for(int i =n-1;i>=1;i--){
        min = INT_MAX;
        for(int k=i+1;k<=n;k++){
            if(G[i][k]!=0 && G[i][k] + cost[k] < min){
                min = G[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }
    path[1] = 1;
    path[stages] = n;
    for(int i=2;i<stages;i++){
        path[i] = d[path[i-1]];
    }
    cout<<"The Shortest Distance From Source to Sink is:"<<endl;
    for(int i=1;i<stages;i++){
        cout<<path[i];
        if(i<stages-1){
            cout<<"->";
        }
    }
    return 0;
}