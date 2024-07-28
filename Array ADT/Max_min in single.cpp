#include<iostream>
using namespace std;
void find_max_min(int A[],int n){
    int max = A[0];
    int min = A[0];
    for(int i=0;i<n;i++){
        if(A[i]<min){
            min = A[i];
        }
        else if(A[i]>max){
            max = A[i];
        }
    }
}
//Best Case Is O(n)
//Worst Case Is O(n)
