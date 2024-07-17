#include<iostream>
using namespace std;

class Array{
    private:
    int* A;
    int size;
    int length;
    public:
    Array(int s){
        size =s;
        A = new int[size];
    }
    void create(){
        cout<<"Enter the number of elements: "<< flush;
        cin >> length;
        cout<<"Enter the array elements: " << flush;
        for(int i=0;i<length;i++){
            cin>>A[i];
        }
    }
    void display(){
        for(int i=0;i<length;i++){
            cout<<A[i]<<" ";
        }
    }
    ~Array(){
        delete[] A;
        cout<<"Array Destroyed!!"<<endl;
    }
};
int main(){
    Array arr(20);
    arr.create();
    arr.display();
    return 0;

}