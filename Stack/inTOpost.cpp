#include<iostream>
#include<stack>
#include<string>
using namespace std;
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'||x=='^'){
        return 0;
    }
    return 1;
}
int outPre(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 3;
    }
    else if(x=='^'){
        return 6;
    }
    else if(x=='('){
        return 7;
    }
    else if(x==')'){
        return 0;
    }
}
int inPre(char x){
    if(x=='+'||x=='-'){
        return 2;
    }
    else if(x=='*'||x=='/'){
        return 4;
    }
    else if(x=='^'){
        return 5;
    }
    else if(x=='('){
        return 0;
    }
    return -1;
}
string convert(string infix){
    string postfix;
    stack<char> stk;
    string::iterator itr;
    itr = infix.begin();
    while(itr!=infix.end()){
        if(isOperand(*itr)){
            postfix+=*itr;
            itr++;
        }
        else{
            if(stk.empty()||outPre(*itr)>inPre(stk.top())){
                stk.push(*itr);
                itr++;
            }
            else if(outPre(*itr)==inPre(stk.top())){
                stk.pop();
            }
            else{
                postfix+=stk.top();
                stk.pop();
            }
        }
    }
    while(!stk.empty()&&stk.top()!=')'){
        postfix+=stk.top();
        stk.pop();
    }
    return postfix;
}
int main(){
    string s = "((a+b)*c)-d^e^f";
    cout<<convert(s);
    return 0;
}