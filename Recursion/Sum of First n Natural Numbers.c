#include<stdio.h>
//Time = O(n) and Space = O(n)
int sum_recurs(int n){
    if(n==0)
        return 0;
    else    
        return sum(n-1) +1;
}
//Time = O(n)
int sum_loop(int n){
    int s=0;
    for(int i=0;i<=n;i++){
        s+=i;
    }
    return s;
}
//Time = O(1)
int sum_formula(int n){
    return n*(n+1)/2;
}
