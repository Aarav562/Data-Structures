#include<stdio.h>
// O(n) Iterative Loop
int fib(int n){
    int t0=0,t1=1,s=0;
    if(n<=1)
        return n;
    for(int i =2;i<=n;i++){
        s = t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}
// O(2^n) Recursion
int fibr(int n){
    if(n<=1)
        return n;
    else
        return fib(n-2)+fib(n-1);
}
// O(n) Recursion using Memorization
int F[10];
int fibm(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1)
            F[n-2] = fibm(n-2);
        if(F[n-1]==-1)
            F[n-1] = fibm(n-1);
        return F[n-2] + F[n-1];
    }
}
int main(){
    for(int i=0;i<10;i++){
        F[i]=-1;
    }
    printf("%d",fibm(5));
    return 0;
}