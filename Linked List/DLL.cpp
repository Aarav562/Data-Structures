#include<iostream>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
};
class DoubleLinkedList{
    private:
    Node *head;
    public:
    DoubleLinkedList(){head = NULL;}
    void Display();
    void Insert(int pos,int x);
    void Delete(int pos);
    void Reverse();
};
void DoubleLinkedList::Display(){
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}
void DoubleLinkedList::Insert(int pos,int x){
    Node *t;
    Node *p = head;
    if(pos<0||pos>Length()){
        return;
    }
    t = new Node;
    t->data = x;
    t->next = NULL;
    t->prev = NULL;
    if(pos==0){
        t->next = head;
        head = t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->next->prev = t;
        t->next = p->next;
        p->next = t;
        t->prev = p;
    }
}
void DoubleLinkedList::Delete(int pos){
    Node *p;
    p = head;
    if(pos==1){
        head=head->next;
        if(head!=NULL){
            head->prev = NULL;
        }
        delete p;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next = p->next;
        if(p->next!=NULL){
            p->next->prev = p->prev;
        }
        delete p;
    }
}
void DoubleLinkedList::Reverse(){
    Node *p = head;
    Node *temp;
    while(p!=NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;
        if(p->next==NULL){
            head = p;
        }
    }
}

