#include<bits/stdc++.h>
using namespace std;

void compute_lps(char* pat,int m,int* lps){
    int len =0;
    lps[0] = 0;
    int i=1;
    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat,char* txt){
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    compute_lps(pat,M,lps);
    int i=0;
    int j=0;
    while(N-i >= M-j){
        if(pat[j] == txt[i]){
            j++;
            i++;
        }
        if(j==M){
            cout<<"Pattern found at index "<<i-j;
            j = lps[j-1];
        }
        else if(i<N && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i=i+1;
            }
        }
    }
}
int main(){
    char txt[] = "ababcabcabababd";
    char pat[] = "ababd";
    KMPSearch(pat,txt);
    return 0;
}