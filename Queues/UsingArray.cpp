#include<iostream>
using namespace std;
class Queues{
    private:
    int size;
    int front;
    int rear;
    int* Q;
    public:
    Queues(int size);
    ~Queues();
    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void Display();
};
Queues::Queues(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
}
Queues::~Queues(){
    delete[] Q;
}
void Queues::Display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<flush;
        if(i<rear){
            cout<<"<-"flush;
        }
    }
    cout<<endl;
}
void Queues::enqueue(int x){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
void Queues::dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        front++;
    }
}
bool Queues::isEmpty(){
    if(front==rear){
        return true;
    }
    else{
        return false;
    }
}
bool Queues::isFull(){
    if(rear=size-1){
        return true;
    }
    else{
        return false;
    }
}
