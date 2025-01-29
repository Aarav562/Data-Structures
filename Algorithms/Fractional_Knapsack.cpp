#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double,int>> ratio (n);
        for(int i=0; i<n; i++){
            ratio[i] = {(double)val[i]/wt[i],i};
        }
        sort(ratio.begin(),ratio.end(),greater<>());
        double max_prof =0;
        int curr_wt = 0;
        for(int i=0; i<n; i++){
            int idx = ratio[i].second;
            if(curr_wt + wt[idx] <=capacity){
                max_prof+=val[idx];
                curr_wt+= wt[idx];
            }
            else{
                double remaining = capacity -curr_wt;
                max_prof+= val[idx] * (remaining/wt[idx]);
                break;
            }
        }
        return max_prof;
    }
};