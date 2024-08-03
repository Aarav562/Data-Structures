#include<iostream>
#include<string>
using namespace std;
template<class T>
void print(T &vec,int n,string s){
    cout<< s << ":  [ "<<flush;
    for(int i=0;i<n;i++){
        cout << vec[i] << flush;
        if(i<n-1){
            cout<< ", "<<flush;
        }
    } 
    cout<<"]"<<endl;
}
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertion_sort(int A[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int x = A[i];
        while(j>=0&&A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]= x;
    }
}
int main(){
    int A[]={5,9,3,6,7,9,10,51,23,12};
    int n = sizeof(A)/sizeof(A[0]);
    print(A,n,"A");
    insertion_sort(A,n);
    print(A,n,"Sorted A");
    return 0;
}