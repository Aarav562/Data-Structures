#include<iostream>
using namespace std;
void swap(int A[],int i,int j){
    int temp = A[i];
    A[i]=A[j];
    A[j]=temp;
}
int Delete(int A[],int n){
    int x = A[0];
    A[0] = A[n-1];
    int i=0;
    int j= 2*i+1;
    while(j<n-1){
        if(A[j+1]>A[j]){
            j=j+1;
        }
        if(A[i]<A[j]){
            swap(A,i,j);
            i=j;
            j=2*i+1;
        }
        else{
            break;
        }
    }
    return x;
}
void Heapify(int A[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        int j=2*i+1;
        while(j<n-1){
            if(A[j+1]>A[j]){
                j=j+1;
            }
            if(A[i]<A[j]){
                swap(A,i,j);
                i=j;
                j=2*i+1;
            }
            else{
                break;
            }           
        }
    }
}
template<class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
int main(){
    int A[] = {5,10,30,20,35,40,15};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A,n,"A");
    Heapify(A,n);
    Print(A,n,"Heapified");
    return 0;
}