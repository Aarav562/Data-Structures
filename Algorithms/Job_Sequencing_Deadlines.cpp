#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,vector<int> &profit) {
    int n = id.size();
    vector<pair<int,pair<int,int>>> jobs;
    for(int i=0;i<n;i++){
        jobs.push_back({profit[i],{deadline[i],id[i]}});
    }
    sort(jobs.rbegin(),jobs.rend());
    int max_deadline = 0;
    for(int i=0;i<n;i++){
        max_deadline = max(max_deadline,jobs[i].second.first);
    }
    vector<int> slot(max_deadline,-1);
    int count =0,total_profit =0;
    for(int i=0;i<n;i++){
        int curr_deadline = jobs[i].second.first;
        int curr_id = jobs[i].second.second;
        int curr_profit = jobs[i].first;
        for(int j=min(max_deadline,curr_deadline)-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j] = curr_id;
                count++;
                total_profit += curr_profit;
                break;
            }
        }
    }
    return {count,total_profit};
}

int main(){
    vector<int> id = {1, 2, 3, 4};
    vector<int> deadline = {2, 1, 2, 1};
    vector<int> profit = {100, 19, 27, 25};
    vector<int> result = JobSequencing(id, deadline, profit);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Total profit: " << result[1] << endl;
    return 0;
}