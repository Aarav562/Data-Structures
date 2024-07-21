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
    void swap(int *x,int *y);
    int linear_search(int x);
    int binary_search(int x);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
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
};
void Array::swap(int *x,int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
};
int Array::linear_search(int x){
    for(int i=0;i<length;i++){
        if(A[i]==x){
            swap(&A[i],&A[0]);
            return 0;
        }
    }
    return -1;
};
int Array::binary_search(int x){
    int m;
    int l = 0;
    int h = length-1;
    while(l<=h){
        m = (l+h)/2;
        if(x == A[m]){
            return m;
        }
        if(x < A[m]){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return -1;
}
int Array::Get(int index){
    if(index>0 && index<length){
        return A[index];
    }
}
void Array::Set(int index,int x){
    if(index>0 && index<length){
        A[index] = x;
    }
}
int Array::Max(){
    int max = A[0];
    for(int i=0;i<length;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}
int Array::Min(){
    int min = A[0];
    for(int i=0;i<length;i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}
int Array::Sum(){
    int sum =0;
    for(int i=0;i<length;i++){
        sum+= A[i];
    }
    return sum;
}
float Array::Avg(){
    int sum = Sum();
    return sum/length;
}