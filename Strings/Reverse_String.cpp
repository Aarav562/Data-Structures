#include<iostream>
#include<string>
using namespace std;
void reverse1(char A[]){
    char rev[20];
    int i,j;
    for(i=0;A[i]!='\0';i++){}
    i-=1;
    for(j=0;i>=0;i--,j++){
        rev[j] = A[i];
    }
    rev[j]='\0';
    cout<<rev;
}
//Second Method Swap Characters
void reverse2(char A[]){
    char t;
    int i,j;
    for(j=0;A[j]!='\0';j++){}
    j=j-1;
    for(i=0;i<j;i++,j--){
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    cout<<A;
}



int main(){
    char S[] = "Mero";
    reverse2(S);
    return 0;
}

