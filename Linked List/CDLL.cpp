#include<iostream>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
};
class CDLL{
    private:
    Node *head;
    public:
    CDLL(){head=NULL;}
    CDLL(int A[],int n);
    void Display();
    void Insert(int pos,int x);
    void Delete(int pos);
    ~CDLL();
}
CDLL::CDLL(int A[],int n){
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->prev = head;
    head->next = head;
    last = head;
    for(int i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        head->prev = t;
        last = t;
    }
}
void CDLL::Display(){
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }(while p!=head);
}
void CDLL::Insert(int pos,int x){
    Node *p = head;
    Node *t;
    int length = 0;
    do{
        length++;
        p=p->next;
    }(while p!=head);
    if(pos==0){
        t->data = x;
        t->next=head;
        head->prev->next =t;
        t->prev = head->prev;
        head->prev = t;
        head =t;
    }
    else if(pos<=length && pos>0){
        Node *q=head;
        for(int i=1;i<pos-1;i++){
            q=q->next;
        }
        t->data=x;
        t->next=q->next;
        q->next->prev = t;
        q->next = t;
        t->prev = q;
    }
}
void CDLL::Delete(int pos){
    if(head == NULL || pos < 1) return;
    Node *p = head;
    if(pos == 1){ 
        if(head->next == head){ 
            delete head;
            head = NULL;
        }
        else{
            head->prev->next = head->next;
            head->next->prev = head->prev;
            p = head;
            head = head->next;
            delete p;
        }
    }
    else{
        for(int i = 0; i < pos - 1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}
CDLL::~CDLL(){
   if(head == NULL) return;
    Node *p = head;
    do{
        Node *temp = p;
        p = p->next;
        delete temp;
    }while(p != head);
    head = NULL;
}