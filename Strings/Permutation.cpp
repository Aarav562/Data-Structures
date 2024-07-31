#include<iostream>
#include<String>
#include<bits/stdc++.h>
using namespace std;
void perm(string S,int k){
    static int A[10] = {0};
    static char Res[10];
    if(S[k]=='\0'){
        Res[k]='\0';
        cout<<Res<<endl;
    }
    else{
        for(int i=0;S[i]!='\0';i++){
            if(A[i]==0){
                Res[k]=S[i];
                A[i]=1;
                perm(S,k+1);
                A[i]=0;
            }
        }
    }
}
int main(){
    string S = "Ebu";
    perm(S,0);
    return 0;
}