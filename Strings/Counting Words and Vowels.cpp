#include<iostream>
#include<string>
using namespace std;
void word_vowel_count(string s){
    int c_count = 0;
    int v_count = 0;
    int w_count = 1;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            v_count++;
        }
        else if((s[i]>='a'&&s[i]<='z')|| (s[i]>='A'&&s[i]<='Z')){
            c_count++;
        }
        else if(s[i]== ' ' && s[i-1]!= ' '){
            w_count++;
        }
    }
    cout<<"Number Of Vowels Is "<<v_count<<endl;
    cout<<"Number Of Words Is "<<w_count<<endl;
    cout<<"Number Of Consonants Is "<<c_count<<endl;
}
int main(){
    string s = "Hello World Guys.";
    word_vowel_count(s);
    return 0;
}