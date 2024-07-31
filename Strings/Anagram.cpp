#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int check_anag(string A,string B){
    int H[26] ={};
    if(A.size()!=B.size()){
        return 0;
    }
    for(int i=0;A[i]!='\0';i++){
        H[A[i]-97]+=1;
    }
    for(int i=0;B[i]!='\0';i++){
        H[B[i]-97]-=1;
        if(H[B[i]-97]<0){
            return 0;
            break;
        }
    }
    return 1;
}
int main(){
    string A = "decimal";
    string B = "meicala";
    if(check_anag(A,B)){
        cout<<"It is Anagram.";
    }
    else{
        cout<<"It is not Anagram.";
    }
    return 0;
}