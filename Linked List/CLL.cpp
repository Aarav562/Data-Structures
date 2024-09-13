#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class CircularLL{
    private:
    Node *head;

    public:
    CircularLL(){head = NULL;}
    CircularLL(int A[],int n);
    void Display();
    void RecDisp();
    void Insert(int pos,int x);
    ~CircularLinkedList();
};
CircularLL::CircularLL(int A[], int n){
    Node *last,*temp;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;
    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i]
        temp->next = head;
        last->next = temp;
        last = temp;
    }
}
void CircularLL::Display()
{
    Node *p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=head);
}
void CircularLL::RecDisp(){
    Node *p = head;
    static int flag = 0;
    if(p!=head || flag==0){
        flag = 1;
        cout<<p->data<<" ";
        RecDisp(p->next);
    }
    flag = 0;
}
void CircularLL::Insert(int pos,int x){
    Node *p,*t;
    int i;
    int length;
    Node *q =head;
    do{
        length++;
        q=q->next;
    }while(q!=head);

    if(pos==0){
        t = new Node;
        t->data =x;
        if(head==NULL){
            head = t;
            head->next = head;
        }
        else{
            p = head;
            while(p->next!=head){
                p=p->next;
            }
            p->next=t;
            t->next = head;
        }
    }
    else{
        p = head;
        if(length>pos){
            cout<<"Invalid Position";
            return;
        }
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
        t =new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
CircularLinkedList::~CircularLinkedList(){
    Node* p = head;
    while (p->next != head){
        p = p->next;
    }
    while (p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }
    if (p == head){
        delete head;
        head = nullptr;
    }
}