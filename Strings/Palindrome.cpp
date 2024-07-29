#include<iostream>
#include<string>
#include<bits/stdc++.h> 
using namespace std;
int check_palindrome(string s1,string s2){
    transform(s1.begin(),s1.end(),s1.begin(), ::tolower);
    transform(s2.begin(),s2.end(),s2.begin(), ::tolower);
    int i=0;
    int j = s2.length()-1;
    while(i< s1.length() && j>=0){
        if(s1[i]!=s2[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int main(){
    string s1 = "Mom";
    string s2 = "Nom";
    if(check_palindrome(s1,s2)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
    return 0;
}