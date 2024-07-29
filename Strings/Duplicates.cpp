#include<iostream>
#include<string>
using namespace std;
//Using Hashing, Time is O(n)
void duplicates(strin s){
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    int H[26] = {};
    int i;
    for(i=0;s[i]!='\0';i++){
        H[s[i]-97]++;
    }
    for(i=0;i<26;i++){
        if(H[i]>1){
            cout<<"Character "<<(char)i+97<<" is repeated"<< H[i]<<" times"<<endl;
        }
    }

}