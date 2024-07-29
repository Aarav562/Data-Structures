#include<iostream>
#include<string>
using namespace std;
string change_case(string s){
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >=65 && s[i]<=90){
            s[i]= s[i]+32;
        }
        else if(s[i]>='a'&&s[i]<='z'){
            s[i]-=32;
        }
    }
    return s;
}
int main(){
    string s = "Hello World EverYONE.";
    cout<<change_case(s);
    return 0;

}