#include<bits/stdc++.h>
using namespace std;
void allpairsshortest(vector<vector<int>>& dist,int V){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main(){
    int V;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    vector<vector<int>> dist(V,vector<int>(V));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<"Enter The weight between "<<i+1<<" and " <<j+1<< "Give -1 for no path"<<endl;
            int w;
            cin>>w;
            if(i==j){dist[i][j]=0;}
            else if(w==-1){dist[i][j]=1e9;}
            else{dist[i][j]=w;}
        }
    }
    allpairsshortest(dist,V);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}