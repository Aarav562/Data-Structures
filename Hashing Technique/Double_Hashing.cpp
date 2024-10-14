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
int Hash(int key){
    return key%10;
}
int PrimeHash(int key){
    return 7 - (key%7);
}
int DoubleHash(int H[],int key){
    int idx = Hash(key);
    int i=0;
    while(H[(Hash(idx)+i*PrimeHash(idx))%10]!=0){
        i++;
    }
    return (idx +i*PrimeHash(idx))%10;
}
void Insert(int H[],int key){
    int idx = Hash(key);
    if (H[idx] != 0){
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}
int Search(int H[],int key){
    int idx = Hash(key);
    int i=0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % 10] != key){
        i++;
        if (H[(Hash(idx) + i * PrimeHash(idx)) % 10] == 0){
            return 0;
        }
    }
    return (Hash(idx) + i * PrimeHash(idx)) % 10;    
}
int main(){
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " A");
 

    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }
    Print(HT, 10, "HT");
 
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;
    return 0;
}