#include<iostream>
#include<string>
#include<bits/stdc++.h> 
using namespace std;
//Using Hashing, Time is O(n)
void duplicates(string s){
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    int H[26] = {};
    int i;
    for(i=0;s[i]!='\0';i++){
        H[s[i]-97]++;
    }
    for(i=0;i<26;i++){
        if(H[i]>1){
            cout<<"Character "<<(char)(i+97)<<" is repeated "<< H[i]<<" times"<<endl;
        }
    }
}
//By Using The Bitwise Operator
void dup_bit(string S){
    long int H=0,x=0;
    for(int i=0;S[i]!='\0';i++){
        x=1;
        x = x<<(S[i]-97);
        if((x&H)>0){
            cout<<S[i]<<" is Duplicate";
        }
        else{
            x =1;
        }
    }
}
int main(){
    string s = "Helloo";
    dup_bit(s);
    return 0;    
}