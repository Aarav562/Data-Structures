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
    void Reverse1();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array B);
    Array* Intersection(Array B);
    Array* Difference(Array B);
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
void Array::Reverse1(){
    int *B;
    B = new int[size];
    for(int i=length-1;int j=0;i--,j++){
        B[j] = A[i];
    }
    for(int i = 0;i<length;i++){
        A[i]=B[i];
    }
}
void Array::Reverse2(){
    for(int i=length-1;int j=0;i--,j++){
        int temp = A[i];
        A[i]=A[j];
        A[j]=temp;
    }
}
void Array::InsertSort(int x){
    int i = length-1;
    while(i>=0 && A[i]>x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1]=x;
}
int Array::isSorted(){
    for(int i=0;i<length-1;i++){
        if(A[i]>A[i+1]){
            return false;
        }
    }
    return true;
}
void Array::Rearrange(){
    int i = 0;
    int j = length -1;
    while(i<j){
        while(A[i]<0){i++;}
        while(A[i>=0]){j--;}
        if(i<j){
            swap(&A[i],&A[j]);
        }
    }
}
Array* Array::Merge(Array arr2){
    Array *C;
    C = new Array(length + arr2.length);
    int i=0;
    int j=0;
    int k=0;
    while(i<length && j<arr2.length){
        if(A[i]< arr2.A[j])
            C->A[k++] = A[i++];
        else
            C->A[k++] = arr2.A[j++];
    }
    for(;i<length;i++){
        C->A[k++] = A[i];
    }
    for(;j<arr2.length;j++){
        C->A[k++] = arr2.A[j++];
    }
    C->length = length+B.length;
    return C;
}
Array* Array::Union(Array B){
    Array* C;
    C = new Array(length + B.length);
    int i=0;
    int j=0;
    int k=0;
    while(i<length && j<B.length){
        if(A[i]<B.A[j])
            C->A[k++] = A[i++];
        else if(B.A[j]<A[i])
            C->A[k++] = B.A[j++];
        else{
            C->A[k++] = A[i++];
            j++;
        }
    }
    for(;i<length;i++){
        C->A[k++] = A[i];
    }
    for(;j<arr2.length;j++){
        C->A[k++] = arr2.A[j++];
    }
    C->length = k;
    return C;
}
Array* Array::Intersection(Array B){
        Array* C;
    C = new Array(length + B.length);
    int i=0;
    int j=0;
    int k=0;
    while(i<length && j<B.length){
        if(A[i]<B.A[j])
            i++;
        else if(B.A[j]<A[i])
            j++;
        else if(A[i]==B.A[j]){
            C->A[k++] = A[i++];
            j++;
        }
    }
    C->length = k;
    return C;
}
Array* Array::Difference(Array B){
    Array* C;
    C = new Array(length + B.length);
    int i=0;
    int j=0;
    int k=0;
    while(i<length && j<B.length){
        if(A[i]<B.A[j])
            C->A[k++] = A[i++];
        else if(B.A[j]<A[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<length;i++){
        C->A[k++] = A[i];
    }
    C->length = k;
    return C;
}