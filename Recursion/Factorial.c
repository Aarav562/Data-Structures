#include<stdio.h>
//Recursion - Time = O(n)
int fact(int n){
    if(n==0)
        return 1;
    else    
        return fact(n-1)*n;
}
//Loop - Time=O(n)
int fact_loop(int n){
    int m = 1;
    for(int i=1;i<=n;i++){
        m= m*i;
    }
    return m;
}

