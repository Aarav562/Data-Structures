#include<iostream>
using namespace std;
template <class T>
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
int hash(int key){
    return key%10;
}
int LinearProb(int H[],int key){
    int idx = hash(key);
    int i=0;
    while(H[(idx+1)%10]!=key){
        i++;
        if(H[(idx+1)%10]==0){
            return 0;
        }
    }
    return (idx + 1) %10;
}
void Insert(int H[],int key){
    int idx = hash(key);
    if(H[idx]!=0){
        idx = LinearProb(H,key);
    }
    H[idx]=key;
}
