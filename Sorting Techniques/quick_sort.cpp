#include <iostream>
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
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
//Using Max_INT or Infinity
int partitionA(int A[],int l,int h){
    int pivot = A[l];
    int i = l;
    int j = h;
    do {
        // Increment i as long as elements are smaller/equal to pivot
        do {i++;} while (A[i] <= pivot);
        // Decrement j as long as elements are larger than pivot
        do {j--;} while (A[j] > pivot);
        if (i < j){
            swap(&A[i], &A[j]);
        }
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}
void quick_sortA(int A[],int l,int h){
    if(l<h){
        int j = partitionA(A,l,h);
        quick_sortA(A,l,j);
        quick_sortA(A,j+1,h);
    }
}

// Last Element is Pivot + without using INT_MAX or INFINITY
int partitionLast(int A[], int low, int high){
    int pivot = A[high];
    int i = low - 1;
    for (int j=low; j<=high-1; j++){
        if (A[j] < pivot){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return i+1;
}
void QuickSortLast(int A[], int low, int high){
    if (low < high){
        int p = partitionLast(A, low, high);
        QuickSortLast(A, low, p-1);
        QuickSortLast(A, p+1, high);
    }
}
 
// First Element is Pivot + without using INT_MAX or INFINITY
int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    while (true){
        while (i <= j && A[i] <= pivot){
            i++;
        }
        while (A[j] >= pivot && j >= i){
            j--;
        }
        if (j < i){
            break;
        } else {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}
void QuickSort(int A[], int low, int high){
    if (low < high){
        int p = partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}

int main() {
 
    cout << "Using INT_MAX or Infinity" << endl;
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 32767};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n-1, "\t\tA");
 
    quick_sortA(A, 0, n-1);
    Print(A, n-1, " Sorted A");
    cout << endl;
 
 
    cout << "Last Element as Pivot + w/o INT_MAX or Infinity" << endl;
    int B[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    Print(B, sizeof(B)/sizeof(B[0]), "\t\tB");
 
    QuickSortLast(B, 0, sizeof(B)/sizeof(B[0])-1);
    Print(B, sizeof(B)/sizeof(B[0]), " Sorted B");
    cout << endl;
 
    cout << "First Element as Pivot + w/o INT_MAX or Infinity" << endl;
    int C[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    Print(C, sizeof(C)/sizeof(C[0]), "\t\tC");
 
    QuickSort(C, 0, sizeof(C)/sizeof(C[0])-1);
    Print(C, sizeof(C)/sizeof(C[0]), " Sorted C");
 
    return 0;
}