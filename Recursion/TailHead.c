#include<stdio.h>
void tail(int n){
    if(n>0){
        printf("%d",n);
        tail(n-1);
    }
}
void head(int n){
    if(n>0){
        head(n-1);
        printf("%d",n);
    }
}
int main(){
    int x=3;
    tail(x);
    printf("\n");
    head(x);
    return 0;
}