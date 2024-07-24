#include<iostream>
using namespace std;
//Single Missing Element, The Time Taken Is O(n)
void missing_element_sorted(int A[],int n){
    int l = A[0];
    int h = A[-1];
    int diff = l - 0;
    for(int i=1;i<n;i++){
        if(A[i]-i!=diff){
            cout<<"The Missing Element Is: "<<i+diff;
            break;
        }
    }
}

//Multiple Missing Elements, Time is O(n)
void missing_multiple(int A[],int n){
    int l = A[0];
    int diff = l-0;
    cout<<"The Missing Elements Are: "
    for(int i=1;i<n;i++){
        if(A[i]-i!=diff){
            while(diff<A[i]-i){
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
}

//Missing Elements In Unsorted Array
void hashing_method(int A[],int n,int l,int h){
    int H[h+1]={};
    for(int i=0;I<n;i++){
        H[A[i]] ++;
    }
    for(int i=0;i<n;i++){
        if(H[i]==0){
            cout<<i<<" ";
        }
    }
}
