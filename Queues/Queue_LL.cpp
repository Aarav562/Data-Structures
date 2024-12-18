#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class Queue{
    private:
    Node* front;
    Node* rear;
    public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
};
Queue::Queue(){
    front = nullptr;
    rear = nullptr;
}
Queue::~Queue(){
    Node *p=front;
    while(front){
        front = front->next;
        delete p;
        p=front;
    }
}
void Queue::display(){
    Node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}
void Queue::enqueue(int x){
    Node *t=new Node;
    if(t==NULL){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        t->data = x;
        t->next = NULL;
        if(front==NULL){front = rear =t;}
        else{
            rear->next = t;
            rear = t;
        }
    }
}
int Queue::dequeue(){
    int x=-1;
    Node *p;
    if(front == NULL){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        p=front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}