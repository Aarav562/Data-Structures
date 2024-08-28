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
int main(){
    int A[] = {1,2,4,6,7,8,3,6,10};
    LinkedList ll(A,sizeof(A)/sizeof(A[0]));
    ll.Display();
    ll.Rec_Display();
    return 0;
}


