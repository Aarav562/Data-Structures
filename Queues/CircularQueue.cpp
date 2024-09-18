#include<iostream>
using namespace std;
class CircularQ{
    private:
    int size;
    int front;
    int rear;
    int* Q;
    public:
    CircularQ(int size);
    ~CircularQ();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int dequeue();
    void display();
};
CircularQ::CircularQ(int size){
    this->size = size;
    front =0;
    rear=0;
    Q = new int [size];
}
CircularQ::~CircularQ(){
    delete [] Q;
}
bool CircularQ::isEmpty(){
    if(front==rear){
        return true;
    }
    return false;
}
bool CircularQ::isFull(){
    if((rear+1)%size==front){
        return true;
    }
    return false;
}
void CircularQ::enqueue(int x){
    if(isFull()){
        cout<<"Queue Overflow"<<flush;
    }
    else{
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}
int CircularQ::dequeue(){
    int x=-1;
    if(isEmpty()){
        cout<<"Queue Underflow"<<flush;
    }
    else{
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}
void CircularQ::display(){
    int i=front +1;
    do{
        cout<<Q[i]<<flush;
        if(i<rear){
            cout<<"<-"<<flush;
        }
        i = (i+1)%size;
    }while(i!=(rear+1)%size);
}
int main(){
    int A[] = {1, 3, 5, 7, 9};
    CircularQ cq(sizeof(A)/sizeof(A[0]) + 1);
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]);
    }
    // Display
    cq.display();
    cout << endl;
    // Overflow
    cq.enqueue(10);
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.dequeue();
    }
    // Underflow
    cq.dequeue();
 
    return 0;
}