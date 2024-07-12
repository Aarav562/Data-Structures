#include<stdio.h>
// O(n^2) Recursive method
int e(int x,int n){
    static int p=1,f=1;
    int r;
    if(n==0)
        return 1;
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}
// O(n) Horners Method
double e(int x,int n){
    static int s=1;
    if(n==0)
        return s;
    s=1+x/n*s;
    return e(x,n-1);
}
// O(n) Loop Iterative
double e(int x,int n){
    double s=1;
    double num =1;
    double den =1;
    for(int i=1;i<=n;i++){
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}
