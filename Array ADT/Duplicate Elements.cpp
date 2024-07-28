#include<iostream>
using namespace std;
//Duplicates in Sorted Array, Time is O(n)
void duplicate(int A[],int n){
    for(int i=0;i<n;i++){
        if(A[i] == A[i+1]){
            int j = i+1;
            while(A[j]==A[i]){
                j++;
                cout<<A[i]<<" "<<j-1;
                i=j-1;
            }
        }
    }
}

//Duplicates in Sorted Array Using Hash, Time is O(n)
void dupl_hash(int A[],int n,int h){
    int H[h+1] ={};
    for(int i=0;i<n;i++){
        H[A[i]]++;
    }
    for(int i=0;i<h;i++){
        if(H[i]>1){
            cout<<"Number "<<i<<" is repeated "<<H[i]<<" times"<<endl;
        }
    }
}

//DUplicates in Unsorted Array, TIme is O(n^2)
void unso_dupl(int A[],int n){
    for(int i=0;i<n;i++){
        int c = 1;
        if(A[i]!=1){
            for(int j=i+1;j<n;j++){
                if(A[i]==A[j]){
                    c++;
                    A[j] = -1;
                }
            }
            if(c>1){
                cout<<A[i]<<" is duplicated"<< c <<" times"<<endl;
            }
        }
    }
}