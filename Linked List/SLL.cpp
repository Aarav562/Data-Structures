#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class LinkedList{
    private:
    Node *head;
    public:
    LinkedList(){head = NULL;}
    //Create n Number of Nodes
    LinkedList(int A[],int n);
    //Display By Traversing
    void Display();
    void Rec_Display(){ Rec_Display(head);}
    private:
    // Helper function to recursively display elements
    void Rec_Display(Node *p);
    void Insert(int pos,int x);
    void Insert_Sort(int x);
    int Deletion(int pos);
};

LinkedList::LinkedList(int A[],int n){
    Node *p,*t;
    head=new Node;
    head->data=A[0];
    head->next = NULL;
    t=head;
    for(int i=1;i<n;i++){
        p = new Node;
        p->data = A[i];
        p->next=NULL;
        t->next = p;
        t = p;
    }
}
void LinkedList::Display(){
    Node *p =head;
    while(p->next!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void LinkedList::Rec_Display(Node *p){
    if(p!=NULL){
        Rec_Display(p->next);
        cout<<p->data<<" ";
    }
}
void LinkedList::Insert(int pos, int x)
{
    Node *t;
    Node *p = head;
    if(pos<0||pos>Length()){
        return;
    }
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(pos==0){
        t->next = head;
        head =t;
    }
    else if{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
void LinkedList::Insert_Sort(int x){
    Node *t,*p;
    *p = head;
    t->data = x;
    t->next=NULL;
    if(head==NULL){
        head = t;
    }
    else{
        while(p && p->next->data<x){
            p=p->next;
        }
        t=p->next;
        p->next=t;
    }
}
int LinkedList::Deletion(int pos){
    Node *p,*q;
    auto x = NULL;
    if(pos==1){
        p = head;
        x = p->data;
        head = p->next;
        delete p;
    }
    else{
        p = head;
        q =NULL;
        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}
int main(){
    int A[] = {1,2,4,6,7,8,3,6,10};
    LinkedList ll(A,sizeof(A)/sizeof(A[0]));
    ll.Display();
    ll.Rec_Display();
    return 0;
}


