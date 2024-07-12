#include<stdio.h>
int fact(int n){
    if(n==0)
        return 1;
    else    
        return fact(n-1)*n;
}
// Using Factorial Function
int nCr(int n,int r){
    int t0,t1,t2;
    t0=fact(n);
    t1 = fact(r);
    t2 = fact(n-r);
    return t0/(t1*t2);
}
// Recursive USing Pascal's Triangle
int NCR(int n,int r){
    if(r==0||n==r)
        return 1;
    else
        return NCR(n-1,r-1) + NCR(n-1,r);
}