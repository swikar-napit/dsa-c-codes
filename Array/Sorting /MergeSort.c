#include<stdio.h>
void merge(int L[], int m, int R[], int n, int A[]){
    int i = 0, j = 0, k = 0;
    while(i<m && j<n){
        if(L[i] <= R[j]){
            A[k++] = L[i++];
        }
        else{
            A[k++] = R[j++];
        }
    }
    //put the remaining elements on left array
    while(i<m){
        A[k++] = L[i++];
    }
    //put the remaing element on Right array
    while(j<n){
        A[k++] = R[j++];
    }
}

void mergeSort(int A[], int n){
    if(n<2){
        return;
    }
    int mid = n/2;
    int Left[mid];
    int Right[n - mid];
    for(int i=0; i<mid; i++){
        Left[i] = A[i];
    }
    for(int i=mid; i<n; i++){
        Right[i - mid] = A[i];
    }
    mergeSort(Left, mid);
    mergeSort(Right, n-mid);
    merge(Left, mid, Right, n - mid, A);
}

int main(){
    int A[] = {10,5,4,9,7,6,1,3,2};
    int n = 9;
    mergeSort(A, n);
    printf("Array after merge sorting : ");
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}