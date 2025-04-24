#include<bits/stdc++.h>
using namespace std;
int knapsack(int W,int n,vector<int>& wt,vector<int>& val){
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(wt[i-1]<=w){
                dp[i][w]=max(dp[i-1][w],val[i-1]+dp[i-1][w-wt[i-1]]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}
int main(){
    int n,W;
    cout<<"Enter The number of items: ";
    cin>>n;
    cout<<"Enter THe Maximum capacity: ";
    cin>>W;
    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++){
        cout<<"Enter weight of item "<<i+1<<endl;
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cout<<"Enter value of item "<<i+1<<endl;
        cin>>val[i];
    }
    int max_prof = knapsack(W,n,wt,val);
    cout<<max_prof;
    return 0;
    
}