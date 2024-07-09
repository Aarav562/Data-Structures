#include<stdio.h>
int pow_slowRecurs(int m,int n){
    if(n==0)
        return 1;
    return pow(m,n-1) *m;
}

int pow_fasrRecurs(int m, int n){
    if(n==0)
        return 1;
    if(n%2 == 0){
        return pow(m*m,n/2);
    }
    else{
        return m * pow(m*m,(n-1)/2);
    }
}

int pow_loop(int m,int n){
    int s =m;
    for(int i=1;i<=n;i++){
        s= s*s;
    }
    return s;
}