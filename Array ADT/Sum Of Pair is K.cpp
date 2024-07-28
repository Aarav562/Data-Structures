#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Sum Of Pair Is Target, Time is O(n^2)
void checkPair(int A[],int n,int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]+A[j]==k){
                cout<<A[i]<<"+"<<A[j]<<"="<<k<<endl;
            }
        }
    }
}

// Hashing Apporach, Time is O(n)
void checkPair2(int A[],int k){
    int n = sizeof(A)/sizeof(A[0]);
    int k = *max_element(A,A+n);
    int H[k+1]={};
    for(int i=0;i<n;i++){
        if(H[k-A[i]]!=0){
            cout<<"("<<A[i]<<","<<k-A[i]<<")"<<endl;
        }
    }
}

//Checking in Sorted Array, Time is O(n)
void Sorted_Pair(int A[],int n,int k){
    int i=0;
    int j=n-1;
    while(i<j){
        if(A[i]+A[j]==k){
            cout<<A[i]<<"+"<<A[j]"="<<k<<endl;
            i++;
            j--;
        }
        else if(A[i]+A[j]<k){
            i++;
        }
        else{
            j--;
        }
    }
}