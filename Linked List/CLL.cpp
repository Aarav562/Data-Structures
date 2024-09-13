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
};
CircualLL::CircularLL(int A[],int n){
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
void CircularLL::Display(){
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