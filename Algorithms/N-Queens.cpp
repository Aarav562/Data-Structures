#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row,int col,vector<string>& board,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void solve(int row,vector<string>& board,vector<vector<string>>& solutions,int n){
    if(row == n){
        solutions.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(row+1,board,solutions,n);
            board[row][col]='.';
        }
    }
}
void printSol(vector<vector<string>>& solutions){
    int c=1;
    for(auto i:solutions){
        cout<<"Solution: "<<c++<<endl;
        for(auto it:i){
            cout<<it<<endl;
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cout<<"ENter the value of N: ";
    cin>>n;
    vector<vector<string>>solutions;
    vector<string> board(n,string(n,'.'));
    solve(0,board,solutions,n);
    printSol(solutions);
    return 0;
    
}