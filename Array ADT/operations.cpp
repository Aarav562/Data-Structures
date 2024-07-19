#include<iostream>
using namespace std;
class Array{
    private:
    int *A;
    int size;
    int length;
    public:
    Array(){
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz){
        size = sz;
        length = 0;
        A= new int[size];
    }
    ~Array(){
        delete []A;
    }
    void Display();
    void Append(int x);
    void Insert(int index,int x);
    void Delete(int index);
};
void Array::Display(){
    cout<<"Enter The Elements"<<endl;
    for(int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
};
void Array::Append(int x){
    A[length] = x;
    length++;
};
void Array::Insert(int index,int x){
    if(index>size){
        cout<<"The operation is not possible."<<endl;
        return;
    }
    for(int i=length;i>index;i--){
        A[i] = A[i-1];
    }
    A[index] = x;
    length++;
};
void Array::Delete(int index){
    if(index>length){
        cout<<"The operation is not possible"<<endl;
        return;
    }
    for(int i=index;i<length-1;i++){
        A[i] = A[i+1];
    }
}