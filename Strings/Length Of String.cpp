#include<iostream>
#include<string>
using namespace std;
int length_string(string s){
    int length = 0;
    for(int i=0;s[i]!='\0';i++){
        length++;
    }
    return length;
}
int main(){
    string s = "The World Is Great";
    cout<<length_string(s);
    return 0;
}