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
int operation(char op, int x, int y){
    if (op == '+'){
        return x + y;
    } else if (op == '-'){
        return x - y;
    } else if (op == '*'){
        return x * y;
    } else if (op == '/'){
        return x / y;
    }
}
int postfix_evaluation(string postfix){
    stack<int> stk;
    int x,y;
    int res;
    for(auto itr=postfix.begin();itr!=postfix.end();itr++){
        if(isOperand(*itr)){
            stk.push(*itr-'0');
        }
        else{
            x=stk.top();
            stk.pop();
            y=stk.top();
            stk.pop();
            res = operation(*itr,y,x);
            stk.push(res);
        }
    }
    res=stk.top();
    stk.pop();
    return res;
}
int main(){
    string post ="35*62/+4-";
    cout<<postfix_evaluation(post);
    return 0;
}