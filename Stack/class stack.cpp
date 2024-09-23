#include <iostream>
#include<string>
using namespace std;
class TwoStacks{
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int value) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = value;
        } else {
            cout << "Stack Overflow for Stack 1\n";
        }
    }
    void push2(int value){
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = value;
        } else {
            cout << "Stack Overflow for Stack 2\n";
        }
    }
    int pop1() {
        if (top1 >= 0) {
            int value = arr[top1];
            top1--;
            return value;
        } else {
            cout << "Stack Underflow for Stack 1\n";
            return -1;
        }
    }
    int pop2() {
        if (top2 < size) {
            int value = arr[top2];
            top2++;
            return value;
        } else {
            cout << "Stack Underflow for Stack 2\n";
            return -1;
        }
    }
    ~TwoStacks() {
        delete[] arr;
    }
};
class Stack{
private:
    int size;
    int top;
    int* S;
public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int stackTop();
    int postfix_eval(string postfix);
    int pop_mid();
    bool palindrome(string p);
};
Stack::Stack(int size) {
    this->size = size;
    top = -1;
    S = new int[size];
}
 
Stack::~Stack() {
    delete[] S;
}
 
void Stack::push(int x) {
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        S[top] = x;
    }
}
 
int Stack::pop() {
    int x = 1;
    if (isEmpty()){
        cout << "Stack Underflow!" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}
 
int Stack::peek(int index) {
    int x = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = S[top-index+1];
    }
    return x;
}
 
int Stack::isFull() {
    if (top == size-1){
        return 1;
    }
    return 0;
}
 
int Stack::isEmpty() {
    if (top == -1){
        return 1;
    }
    return 0;
}
 
void Stack::display() {
    for (int i=top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}
 
int Stack::stackTop() {
    if (isEmpty()){
        return -1;
    }
    return S[top];
}
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
int Stack::postfix_eval(string postfix){
    Stack stk(40);
    int x,y;
    int res;
    for(auto itr=postfix.begin();itr!=postfix.end();itr++){
        if(isOperand(*itr)){
            stk.push(*itr-'0');
        }
        else{;
            x=stk.pop();
            y=stk.pop();
            res = operation(*itr,y,x);
            stk.push(res);
        }
    }
    res=stk.pop();
    return res;
}
int Stack::pop_mid(){
    return S[(top+1)/2];
}
bool Stack::palindrome(string s){
    Stack stk(30);
    for(auto itr=s.begin();*itr!="X";itr++){
        stk.push(*itr);
    }
    for(;itr!=s.end();itr++){
        s=stk.pop();
    }
    return stk.isEmpty();
}
int main(){
    Stack S(20);
    string t = "67+";
    cout<<S.postfix_eval(t);
    return 0;
}